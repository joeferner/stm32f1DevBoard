
#ifndef IO_STM32F103X_H
#define	IO_STM32F103X_H

/* FLASH and SRAM *******************************************************************/
#define STM32_FLASH_BASE     0x08000000     /* 0x08000000 - Up to 512Kb */
#define STM32_FLASH_ACR      (*((volatile unsigned long*)(STM32_FLASH_BASE + 0x0)))

/**
 * PRFTBE: Prefetch buffer enable
 */
#define STM32_FLASH_ACR_PRFTBE (1<<4)

/**
 * LATENCY: Latency
 */
#define STM32_FLASH_ACR_LATENCY_MASK (0x7<<0)
#define STM32_FLASH_ACR_LATENCY_0    (0x0<<0)
#define STM32_FLASH_ACR_LATENCY_1    (0x1<<0)
#define STM32_FLASH_ACR_LATENCY_2    (0x2<<0)

#define STM32_SRAM_BASE      0x20000000     /* 0x20000000 - 64Kb SRAM */
#define STM32_SRAMBB_BASE    0x22000000
#define STM32_PERIPH_BASE    0x40000000

/* Register Base Address ************************************************************/

/* APB1 bus */
#define STM32_TIM2_BASE      0x40000000     /* 0x40000000 - 0x400003ff: TIM2 timer */
#define STM32_TIM3_BASE      0x40000400     /* 0x40000400 - 0x400007ff: TIM3 timer */
#define STM32_TIM4_BASE      0x40000800     /* 0x40000800 - 0x40000bff: TIM4 timer */
#define STM32_TIM5_BASE      0x40000c00     /* 0x40000c00 - 0x40000fff: TIM5 timer */
#define STM32_TIM6_BASE      0x40001000     /* 0x40001000 - 0x400013ff: TIM6 timer */
#define STM32_TIM7_BASE      0x40001400     /* 0x40001400 - 0x400007ff: TIM7 timer */
/* 0x40001800 - 0x40000fff: Reserved */
#define STM32_RTC_BASE       0x40002800     /* 0x40002800 - 0x40002bff: RTC */
#define STM32_WWDG_BASE      0x40002C00     /* 0x40002C00 - 0x40002fff: Window watchdog (WWDG) */
#define STM32_IWDG_BASE      0x40003000     /* 0x40003000 - 0x400033ff: Independent watchdog (IWDG) */
/* 0x40003400 - 0x400037ff: Reserved */
#define STM32_SPI2_BASE      0x40003800     /* 0x40003800 - 0x40003bff: SPI2/I22 */
#define STM32_I2S2_BASE      0x40003800
#define STM32_SPI3_BASE      0x40003c00     /* 0x40003c00 - 0x40003fff: SPI3/I23 */
#define STM32_I2S3_BASE      0x40003c00
/* 0x40004000 - 0x400043ff: Reserved */
#define STM32_USART2_BASE    0x40004400     /* 0x40004400 - 0x400047ff: USART2 */
#define STM32_USART3_BASE    0x40004800     /* 0x40004800 - 0x40004bff: USART3 */
#define STM32_UART4_BASE     0x40004c00     /* 0x40004c00 - 0x40004fff: UART4 */
#define STM32_UART5_BASE     0x40005000     /* 0x40005000 - 0x400053ff: UART5 */
#define STM32_I2C1_BASE      0x40005400     /* 0x40005400 - 0x400057ff: I2C1 */
#define STM32_I2C2_BASE      0x40005800     /* 0x40005800 - 0x40005Bff: I2C2 */
#define STM32_USB_BASE       0x40005c00     /* 0x40005c00 - 0x40005fff: USB device FS registers */
#define STM32_USBCANRAM_BASE 0x40006000     /* 0x40006000 - 0x400063ff: Shared USB/CAN SRAM 512 bytes */
#define STM32_CAN1_BASE      0x40006400     /* 0x40006400 - 0x400067ff: bxCAN1 */
#define STM32_CAN2_BASE      0x40006800     /* 0x40006800 - 0x40006bff: bxCAN2 */
#define STM32_BKP_BASE       0x40006c00     /* 0x40006c00 - 0x40006fff: Backup registers (BKP) */
#define STM32_PWR_BASE       0x40007000     /* 0x40007000 - 0x400073ff: Power control PWR */
#define STM32_DAC_BASE       0x40007400     /* 0x40007400 - 0x400077ff: DAC */
/* 0x40007800 - 0x4000ffff: Reserved */

/* APB2 bus */

#define STM32_AFIO_BASE      0x40010000     /* 0x40010000 - 0x400103ff: AFIO */
#define STM32_EXTI_BASE      0x40010400     /* 0x40010400 - 0x400107ff: EXTI */

#define STM32_GPIOA_BASE     0x40010800     /* 0x40010800 - 0x40010bff: GPIO Port A */
#define STM32_GPIOA_CRL      (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x0)))
#define STM32_GPIOA_CRH      (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x04)))
#define STM32_GPIOA_IDR      (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x08)))
#define STM32_GPIOA_ODR      (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x0C)))
#define STM32_GPIOA_BSRR     (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x10)))
#define STM32_GPIOA_BRR      (*((volatile unsigned long*)(STM32_GPIOA_BASE + 0x14)))

#define STM32_GPIOB_BASE     0X40010c00     /* 0X40010c00 - 0x40010fff: GPIO Port B */
#define STM32_GPIOB_CRL      (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x0)))
#define STM32_GPIOB_CRH      (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x04)))
#define STM32_GPIOB_IDR      (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x08)))
#define STM32_GPIOB_ODR      (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x0C)))
#define STM32_GPIOB_BSRR     (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x10)))
#define STM32_GPIOB_BRR      (*((volatile unsigned long*)(STM32_GPIOB_BASE + 0x14)))

#define STM32_GPIOC_BASE     0x40011000     /* 0x40011000 - 0x400113ff: GPIO Port C */
#define STM32_GPIOC_CRL      (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x0)))
#define STM32_GPIOC_CRH      (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x04)))
#define STM32_GPIOC_IDR      (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x08)))
#define STM32_GPIOC_ODR      (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x0C)))
#define STM32_GPIOC_BSRR     (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x10)))
#define STM32_GPIOC_BRR      (*((volatile unsigned long*)(STM32_GPIOC_BASE + 0x14)))

#define STM32_GPIOD_BASE     0x40011400     /* 0x40011400 - 0x400117ff: GPIO Port D */
#define STM32_GPIOD_CRL      (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x0)))
#define STM32_GPIOD_CRH      (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x04)))
#define STM32_GPIOD_IDR      (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x08)))
#define STM32_GPIOD_ODR      (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x0C)))
#define STM32_GPIOD_BSRR     (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x10)))
#define STM32_GPIOD_BRR      (*((volatile unsigned long*)(STM32_GPIOD_BASE + 0x14)))

#define STM32_GPIOE_BASE     0x40011800     /* 0x40011800 - 0x40011bff: GPIO Port E */
#define STM32_GPIOE_CRL      (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x0)))
#define STM32_GPIOE_CRH      (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x04)))
#define STM32_GPIOE_IDR      (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x08)))
#define STM32_GPIOE_ODR      (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x0C)))
#define STM32_GPIOE_BSRR     (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x10)))
#define STM32_GPIOE_BRR      (*((volatile unsigned long*)(STM32_GPIOE_BASE + 0x14)))

#define STM32_GPIOF_BASE     0x40011c00     /* 0x4001c000 - 0x400111ff: GPIO Port F */
#define STM32_GPIOF_CRL      (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x0)))
#define STM32_GPIOF_CRH      (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x04)))
#define STM32_GPIOF_IDR      (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x08)))
#define STM32_GPIOF_ODR      (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x0C)))
#define STM32_GPIOF_BSRR     (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x10)))
#define STM32_GPIOF_BRR      (*((volatile unsigned long*)(STM32_GPIOF_BASE + 0x14)))

#define STM32_GPIOG_BASE     0x40012000     /* 0x40012000 - 0x400123ff: GPIO Port G */
#define STM32_GPIOG_CRL      (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x0)))
#define STM32_GPIOG_CRH      (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x04)))
#define STM32_GPIOG_IDR      (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x08)))
#define STM32_GPIOG_ODR      (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x0C)))
#define STM32_GPIOG_BSRR     (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x10)))
#define STM32_GPIOG_BRR      (*((volatile unsigned long*)(STM32_GPIOG_BASE + 0x14)))

#define STM32_ADC1_BASE      0x40012400     /* 0x40012400 - 0x400127ff: ADC1 */
#define STM32_ADC2_BASE      0x40012800     /* 0x40012800 - 0x40012bff: ADC2 */
#define STM32_TIM1_BASE      0x40012c00     /* 0x40012c00 - 0x40012fff: TIM1 timer */

#define STM32_SPI1_BASE      0x40013000     /* 0x40013000 - 0x400133ff: SPI1 */

#define STM32_SPI1_CR1       (*((volatile unsigned long*)(STM32_SPI1_BASE + 0x0)))

/**
 * DFF: Data frame format
 */
#define STM32_SPI1_CR1_DFF_8    (0<<11)

/**
 * SSM: Software slave management
 */
#define STM32_SPI1_CR1_SSM      (1<<9)

/**
 * SSI: Internal slave select
 */
#define STM32_SPI1_CR1_SSI      (1<<8)

/**
 * SPE: SPI enable
 */
#define STM32_SPI1_CR1_SPE      (1<<6)

/**
 * BR[2:0]: Baud rate control
 */
#define STM32_SPI1_CR1_F_2      (0x0<<3)
#define STM32_SPI1_CR1_F_4      (0x1<<3)
#define STM32_SPI1_CR1_F_8      (0x2<<3)
#define STM32_SPI1_CR1_F_16     (0x3<<3)
#define STM32_SPI1_CR1_F_32     (0x4<<3)
#define STM32_SPI1_CR1_F_64     (0x5<<3)
#define STM32_SPI1_CR1_F_128    (0x6<<3)
#define STM32_SPI1_CR1_F_256    (0x7<<3)

/**
 * MSTR: Master selection
 */
#define STM32_SPI1_CR1_MSTR     (1<<2)

/**
 * LSBFIRST: Frame format
 */
#define STM32_SPI1_CR1_MSBFIRST (0<<7)
#define STM32_SPI1_CR1_LSBFIRST (1<<7)

#define STM32_SPI1_CR2       (*((volatile unsigned long*)(STM32_SPI1_BASE + 0x4)))
#define STM32_SPI1_SR        (*((volatile unsigned long*)(STM32_SPI1_BASE + 0x8)))

/**
 * TXE: Transmit buffer empty
 */
#define STM32_SPI1_SR_TXE       (1<<1)

/**
 * RXNE: Receive buffer not empty
 */
#define STM32_SPI1_SR_RXNE      (1<<0)

#define STM32_SPI1_DR        (*((volatile unsigned long*)(STM32_SPI1_BASE + 0xC)))

#define STM32_TIM8_BASE      0x40013400     /* 0x40013400 - 0x400137ff: TIM8 timer */
#define STM32_USART1_BASE    0x40013800     /* 0x40013800 - 0x40013bff: USART1 */
#define STM32_ADC3_BASE      0x40012800     /* 0x40012800 - 0x40013fff: ADC3 */
/* 0x40014000 - 0x40017fff: Reserved */
/* AHB bus */

#define STM32_SDIO_BASE      0x40018000     /* 0x40018000 - 0x400183ff: SDIO  */
/* 0x40018400 - 0x40017fff: Reserved */
#define STM32_DMA1_BASE      0x40020000     /* 0x40020000 - 0x400203ff: DMA1  */
#define STM32_DMA2_BASE      0x40020400     /* 0x40020000 - 0x400207ff: DMA2  */
/* 0x40020800 - 0x40020fff: Reserved */

#define STM32_RCC_BASE       0x40021000     /* 0x40021000 - 0x400213ff: Reset and Clock control RCC */
#define STM32_RCC_APB2ENR  (*((volatile unsigned int*)(STM32_RCC_BASE + 0x18)))
#define STM32_RCC_APB2ENR_SPI1EN  (1<<12)
#define STM32_RCC_APB2ENR_IOPGEN  (1<<8)
#define STM32_RCC_APB2ENR_IOPFEN  (1<<7)
#define STM32_RCC_APB2ENR_IOPEEN  (1<<6)
#define STM32_RCC_APB2ENR_IOPDEN  (1<<5)
#define STM32_RCC_APB2ENR_IOPCEN  (1<<4)
#define STM32_RCC_APB2ENR_IOPBEN  (1<<3)
#define STM32_RCC_APB2ENR_IOPAEN  (1<<2)
#define STM32_RCC_APB2ENR_AFIOEN  (1<<0)

/* 0x40021400 - 0x40021fff:  Reserved */
#define STM32_OTGFS_BASE     0x50000000     /* 0x50000000 - 0x500003ff: USB OTG FS */
#define STM32_FLASHIF_BASE   0x40022000     /* 0x40022000 - 0x400223ff: Flash memory interface */
#define STM32_CRC_BASE       0x40028000     /* 0x40023000 - 0x400233ff: RC */
/* 0x40023400 - 0x40027fff: Reserved */
#define STM32_ETHERNET_BASE  0x40028000     /* 0x40028000 - 0x40029fff: Ethernet */
/* 0x40030000 - 0x4fffffff: Reserved */

/* Peripheral BB base */

#define STM32_PERIPHBB_BASE  0x42000000

/* Flexible SRAM controller (FSMC) */

#define STM32_FSMC_BASE      0xa0000000

/* Other registers -- see armv7-m/nvic.h for standard Cortex-M3 registers in this
 * address range
 */

#define STM32_SCS_BASE       0xe000e000

/**
 * SysTick register map base pointer
 */
#define STM32_SYSTICK_BASE   0xE000E010
#define STM32_SYSTICK_CSR    (*((volatile unsigned int*)(STM32_SYSTICK_BASE + 0x00)))
#define STM32_SYSTICK_CSR_CLKSOURCE_CORE (1<<2);
#define STM32_SYSTICK_CSR_TICKINT_PEND   (1<<1);
#define STM32_SYSTICK_CSR_ENABLE         (1<<0);

#define STM32_SYSTICK_RVR    (*((volatile unsigned int*)(STM32_SYSTICK_BASE + 0x04)))
#define STM32_SYSTICK_CNT    (*((volatile unsigned int*)(STM32_SYSTICK_BASE + 0x08)))
#define STM32_SYSTICK_CVR    (*((volatile unsigned int*)(STM32_SYSTICK_BASE + 0x0C)))

/** System control block register map base pointer */
#define STM32_SCB_BASE       0xE000ED00
#define STM32_SCB_CPUID      (*((volatile unsigned int*)(STM32_SCB_BASE + 0x00)))
#define STM32_SCB_ICSR       (*((volatile unsigned int*)(STM32_SCB_BASE + 0x04)))
#define STM32_SCB_VTOR       (*((volatile unsigned int*)(STM32_SCB_BASE + 0x08)))
#define STM32_SCB_AIRCR      (*((volatile unsigned int*)(STM32_SCB_BASE + 0x0C)))
#define STM32_SCB_SCR        (*((volatile unsigned int*)(STM32_SCB_BASE + 0x10)))
#define STM32_SCB_CCR        (*((volatile unsigned int*)(STM32_SCB_BASE + 0x14)))
#define STM32_SCB_SHP        (*((volatile unsigned int*)(STM32_SCB_BASE + 0x18)))

#define STM32_DEBUGMCU_BASE  0xe0042000

#define STM32_USART1_SR    (*((volatile unsigned int*)(STM32_USART1_BASE + 0x00)))

/**
 * TXE: Transmit data register empty
 */
#define STM32_USART1_SR_TXE  (1<<7)

/**
 * TC: Transmission complete
 */
#define STM32_USART1_SR_TC   (1<<6)

/**
 * RXNE: Read data register not empty
 */
#define STM32_USART1_SR_RXNE (1<<5)

#define STM32_USART1_DR    (*((volatile unsigned int*)(STM32_USART1_BASE + 0x04)))

/**
 * USARTDIV = DIV_Mantissa + (DIV_Fraction / 16)
 * TX/RX baud = fCK / (16 * USARTDIV)
 *   legend: fCK - Input clock to the peripheral (PCLK1 for USART2, 3, 4, 5 or PCLK2 for USART1)
 * DIV_Mantissa[11:0]: mantissa of USARTDIV
 * DIV_Fraction[3:0]: fraction of USARTDIV
 */
#define STM32_USART1_BRR   (*((volatile unsigned int*)(STM32_USART1_BASE + 0x08)))

#define STM32_USART1_CR1   (*((volatile unsigned int*)(STM32_USART1_BASE + 0x0c)))

/**
 * UE: Enable
 */
#define STM32_USART1_CR1_UE    (1<<13)

/**
 * M: Word Length
 *   0: 1 Start bit, 8 Data bits, n Stop bit
 *   1: 1 Start bit, 9 Data bits, n Stop bit
 */
#define STM32_USART1_CR1_M     (1<<12)

/**
 * WAKE: Wakeup method
 */
#define STM32_USART1_CR1_WAKE  (1<<11)

/**
 * PCE: Parity control enable
 */
#define STM32_USART1_CR1_PCE   (1<<10)

/**
 * PS: Parity selection
 */
#define STM32_USART1_CR1_PS    (1<<9)

/**
 * PEIE: PE interrupt enable
 */
#define STM32_USART1_CR1_PEIE  (1<<8)

/**
 * TXEIE: TXE interrupt enable
 */
#define STM32_USART1_CR1_TXEIE (1<<7)

/**
 * TCIE: Transmission complete interrupt enable
 */
#define STM32_USART1_CR1_TCIE  (1<<6)

/**
 * RXNEIE: RXNE interrupt enable
 */
#define STM32_USART1_CR1_RXNEIE (1<<5)

/**
 * IDLEIE: IDLE interrupt enable
 */
#define STM32_USART1_CR1_IDLEIE (1<<4)

/**
 * TE: Transmitter enable
 */
#define STM32_USART1_CR1_TE     (1<<3)

/**
 * RE: Receiver enable
 */
#define STM32_USART1_CR1_RE     (1<<2)

/**
 * RWU: Receiver wakeup
 */
#define STM32_USART1_CR1_RWU    (1<<1)

/**
 * SBK: Send break
 */
#define STM32_USART1_CR1_SBK    (1<<0)

#define STM32_USART1_CR2   (*((volatile unsigned int*)(STM32_USART1_BASE + 0x10)))

/**
 * LINEN: LIN mode enable
 */
#define STM32_USART1_CR2_LINEN  (1<<14)

/**
 * STOP: STOP bits
 */
#define STM32_USART1_CR2_STOP_1   (0x0<<12)
#define STM32_USART1_CR2_STOP_0_5 (0x1<<12)
#define STM32_USART1_CR2_STOP_2   (0x2<<12)
#define STM32_USART1_CR2_STOP_1_5 (0x3<<12)

/**
 * CLKEN: Clock enable
 */
#define STM32_USART1_CR2_CLKEN  (1<<11)

/**
 * CPOL: Clock polarity
 */
#define STM32_USART1_CR2_CPOL   (1<<10)

/**
 * CPHA: Clock phase
 */
#define STM32_USART1_CR2_CPHA   (1<<9)

/**
 * LBCL: Last bit clock pulse
 */
#define STM32_USART1_CR2_LBCL   (1<<8)

/**
 * LBDIE: LIN break detection interrupt enable
 */
#define STM32_USART1_CR2_LBDIE  (1<<6)

/**
 * LBDL: LIN break detection length
 */
#define STM32_USART1_CR2_LBDL   (1<<5)

#define STM32_USART1_CR3   (*((volatile unsigned int*)(STM32_USART1_BASE + 0x14)))

#endif	/* IO_STM32F103X_H */

