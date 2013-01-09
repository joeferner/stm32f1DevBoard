
#include "spi.h"
#include "gpio.h"

void spi1_init(unsigned int speed, unsigned int bitOrder, unsigned int mode) {
  STM32_RCC_APB2ENR |= STM32_RCC_APB2ENR_IOPAEN; // enable clock for PORT A
  STM32_GPIO_CONFIG_LOW(STM32_GPIOA, 5, STM32_GPIO_OUTPUT_PP | STM32_GPIO_OUTPUT_50MHz); /* SCK */
  STM32_GPIO_CONFIG_LOW(STM32_GPIOA, 7, STM32_GPIO_OUTPUT_PP | STM32_GPIO_OUTPUT_50MHz); /* MOSI */
  STM32_GPIO_CONFIG_LOW(STM32_GPIOA, 7, STM32_GPIO_INPUT_FLOATING); /* MISO */

  STM32_SPI1_CR1 =
          speed
          | bitOrder
          | STM32_SPI1_CR1_DFF_8
          | STM32_SPI1_CR1_SSM
          | STM32_SPI1_CR1_SSI
          | STM32_SPI1_CR1_MSTR
          | STM32_SPI1_CR1_SPE;
  STM32_RCC_APB2ENR |= STM32_RCC_APB2ENR_SPI1EN; // enable clock for SPI
}

unsigned char spi1_send_buffer(unsigned char* c, unsigned int len) {
  while(len > 1) {
    spi1_send(*c++);
    len--;
  }
  return spi1_send(*c);
}

unsigned char spi1_send(unsigned char c) {
  spi1_tx(c);
  return spi1_rx();
}

void spi1_tx(unsigned char c) {
  STM32_SPI1_DR = c;
  while (!(STM32_SPI1_SR & STM32_SPI1_SR_TXE));
}

unsigned char spi1_rx() {
  while (!(STM32_SPI1_SR & STM32_SPI1_SR_RXNE));
  return STM32_SPI1_DR;
}
