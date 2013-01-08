
#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stm32.h"

  void spi_init(unsigned int speed, unsigned int bitOrder, unsigned int mode);
  unsigned char spi_send_buffer(unsigned char* c, unsigned int len);
  unsigned char spi_send(unsigned char c);

  void spi_tx(unsigned char c);
  unsigned char spi_rx();

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

