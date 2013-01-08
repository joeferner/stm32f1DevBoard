#ifndef CLOCK_ARCH_H
#define	CLOCK_ARCH_H

#include <stdint.h>

typedef uint32_t clock_time_t;
#define CLOCK_CONF_SECOND		(clock_time_t)1000
								//(F_CPU / (1024*255)), this cannot be used as it gives overflows
								//Freqency divided prescaler and counter register size

#include <clock.h>

#endif	/* CLOCK_ARCH_H */

