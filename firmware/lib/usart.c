
#include "usart.h"
#include "io.h"
#include <math.h>

void usart1_init(uint16_t baud) {
  STM32_RCC_APB2ENR |= ((1 << 14) | (1 << 2));

  STM32_GPIOA_CRH = 0x444444b4;

  double usartdiv = (double) STM32_FPCLK2 / ((double) baud * 16.0);
  double mantissa;
  double fraction = modf(usartdiv, &mantissa);
  unsigned int brrFraction = (unsigned int) (fraction * 16);
  unsigned int brrMantissa = (unsigned int) mantissa;
  unsigned int brr = (brrMantissa << 4) | (brrFraction & 0x0f);

  STM32_USART1_CR1 =
          STM32_USART1_CR1_UE /* enable */
          | ~STM32_USART1_CR1_M /* 1 Start bit, 8 Data bits, n Stop bit */
          | STM32_USART1_CR1_RXNEIE /* RX Interrupt enabled */
          ;
  STM32_USART1_CR2 = STM32_USART1_CR2_STOP_1; /* 1 stop bit */
  STM32_USART1_BRR = brr;
  STM32_USART1_CR1 |=
          STM32_USART1_CR1_TE /* TX Enabled */
          | STM32_USART1_CR1_RE /* RX Enabled */
          ;
}

void usart1_send(unsigned char c) {
  STM32_USART1_DR = c;
  while (!(STM32_USART1_SR & STM32_USART1_SR_TXE));
}

void usart1_send_str(const char *str) {
  while (*str) {
    usart1_send((unsigned char) *str++);
  }
}

unsigned char usart1_recv() {
  while (!(STM32_USART1_SR & STM32_USART1_SR_RXNE));
  return STM32_USART1_DR;
}
