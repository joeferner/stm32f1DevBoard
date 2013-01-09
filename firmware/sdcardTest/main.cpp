
#include <stm32.h>
#include <sdcard_spi.h>
#include <spi.h>
#include <usart.h>
#include <io.h>
#include <delay.h>

int main(int argc, char** argv) {
  stm32_init();
  
  STM32_RCC_APB2ENR |= STM32_RCC_APB2ENR_IOPBEN; // enable clock for PORT B
  STM32_GPIOB_CRL = 0x33333333; // set PB[0:7] as output
  STM32_GPIOB_CRH = 0x33333333; // set PB[8:15] as output

  while (1) {
    STM32_GPIOB_ODR = 0xffffffff;
    delay(1000);
    STM32_GPIOB_ODR = 0x00000000;
    delay(1000);
  }

  usart1_init(9600);
  usart1_send_str("SDCardTest\n");

  spi1_init(STM32_SPI1_CR1_F_256, STM32_SPI1_CR1_LSBFIRST, 0);
  sdcard_spi1_init();

  return 0;
}
