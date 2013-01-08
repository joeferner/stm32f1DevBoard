
#include "spi.h"
#include "gpio.h"

void spi_init(unsigned int speed, unsigned int bitOrder, unsigned int mode) {
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

unsigned char spi_send_buffer(unsigned char* c, unsigned int len) {
  while(len > 1) {
    spi_send(*c++);
    len--;
  }
  return spi_send(*c);
}

unsigned char spi_send(unsigned char c) {
  spi_tx(c);
  return spi_rx();
}

void spi_tx(unsigned char c) {
  STM32_SPI1_DR = c;
  while (!(STM32_SPI1_SR & STM32_SPI1_SR_TXE));
}

unsigned char spi_rx() {
  while (!(STM32_SPI1_SR & STM32_SPI1_SR_RXNE));
  return STM32_SPI1_DR;
}
