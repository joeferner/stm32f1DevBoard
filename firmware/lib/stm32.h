/* 
 * File:   stm32.h
 * Author: jferner
 *
 * Created on January 8, 2013, 12:19 PM
 */

#ifndef STM32_H
#define	STM32_H

#include "io.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define STM32_DELAY_US_MULT (STM32_SYSCLK / 3600000)

  void stm32_init();

#ifdef	__cplusplus
}
#endif

#endif	/* STM32_H */

