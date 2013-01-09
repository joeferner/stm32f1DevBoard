
#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stm32.h"

  void spi1_init(unsigned int speed, unsigned int bitOrder, unsigned int mode);
  unsigned char spi1_send_buffer(unsigned char* c, unsigned int len);
  unsigned char spi1_send(unsigned char c);

  void spi1_tx(unsigned char c);
  unsigned char spi1_rx();

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

