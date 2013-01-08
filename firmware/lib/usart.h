#ifndef UART_H
#define	UART_H

#include <inttypes.h>

#ifdef	__cplusplus
extern "C" {
#endif

  void usart1_init(uint16_t baud);
  void usart1_send(unsigned char c);
  void usart1_send_str(const char *str);
  unsigned char usart1_recv();

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

