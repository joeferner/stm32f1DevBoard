
#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define STM32_GPIOA GPIOA

#define STM32_GPIO_OUTPUT_PP      (0x0<<2)
#define STM32_GPIO_INPUT_FLOATING (0x1<<2)

#define STM32_GPIO_OUTPUT_50MHz   (0x3<<0)

#define STM32_GPIO_CONFIG_LOW(port, pin, mode) \
  port ## _CRL = (port ## _CRL & ~(0xf << ((pin - 1) * 4))) | mode << ((pin - 1) * 4);

#define STM32_GPIO_CONFIG_HIGH(port, pin, mode) \
  port ## _CRH = (port ## _CRH & ~(0xf << ((pin - 8) * 4))) | mode << ((pin - 8) * 4);
  
#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

