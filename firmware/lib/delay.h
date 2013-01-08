
#ifndef DELAY_H
#define	DELAY_H

#include <inttypes.h>
#include "stm32.h"

#ifdef	__cplusplus
extern "C" {
#endif

  static inline void delay_us(uint32_t us) {
    us *= STM32_DELAY_US_MULT;
    us--; // fudge for function call overhead
    asm volatile(
              " mov r0, %[us] \n\t"
              "1: subs r0, #1 \n\t"
              " bhi 1b \n\t"
              :
              : [us] "r" (us)
              : "r0"
              );
  }

  static inline void delay(uint32_t ms) {
    for (; ms != 0; ms--) {
      delay_us(1000);
    }
  }

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

