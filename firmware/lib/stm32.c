
#include "stm32.h"
#include <inttypes.h>

#define STM32_NR_INTERRUPTS     43
#define SYSTICK_RELOAD_VAL      71999 /* takes a cycle to reload */

void setup_flash();
void setup_clocks();
void setup_nvic();
void systick_init(uint32_t reload_val);
void nvic_init(uint32_t address, uint32_t offset);
void systick_enable();
void nvic_set_vector_table(uint32_t address, uint32_t offset);

void stm32_init() {
  setup_flash();
  setup_clocks();
  setup_nvic();
  systick_init(SYSTICK_RELOAD_VAL);
}

void setup_flash() {
  uint32_t acr = STM32_FLASH_ACR;
  acr &= ~STM32_FLASH_ACR_LATENCY_MASK;
  STM32_FLASH_ACR = acr | STM32_FLASH_ACR_PRFTBE | STM32_FLASH_ACR_LATENCY_2;
}

void setup_clocks() {
  // Turn on HSI. We'll switch to and run off of this while we're
  // setting up the main PLL.
  rcc_turn_on_clk(RCC_CLK_HSI);

  // Turn off and reset the clock subsystems we'll be using, as well
  // as the clock security subsystem (CSS). Note that resetting CFGR
  // to its default value of 0 implies a switch to HSI for SYSCLK.
  RCC_BASE->CFGR = 0x00000000;
  rcc_disable_css();
  rcc_turn_off_clk(RCC_CLK_PLL);
  rcc_turn_off_clk(RCC_CLK_HSE);
  wirish::priv::board_reset_pll();
  // Clear clock readiness interrupt flags and turn off clock
  // readiness interrupts.
  RCC_BASE->CIR = 0x00000000;

  // Enable HSE, and wait until it's ready.
  rcc_turn_on_clk(RCC_CLK_HSE);
  while (!rcc_is_clk_ready(RCC_CLK_HSE))
    ;

  // Configure AHBx, APBx, etc. prescalers and the main PLL.
  wirish::priv::board_setup_clock_prescalers();
  rcc_configure_pll(&wirish::priv::w_board_pll_cfg);

  // Enable the PLL, and wait until it's ready.
  rcc_turn_on_clk(RCC_CLK_PLL);
  while (!rcc_is_clk_ready(RCC_CLK_PLL));

  // Finally, switch to the now-ready PLL as the main clock source.
  rcc_switch_sysclk(RCC_CLKSRC_PLL);
}

/*
 * These addresses are where usercode starts when a bootloader is
 * present. If no bootloader is present, the user NVIC usually starts
 * at the Flash base address, 0x08000000.
 *
 * FIXME Let the build specify the vector table address numerically to
 * avoid having these magic values -- some people have been fixing up
 * the bootloader so it uses less space.
 */
#define USER_ADDR_ROM 0x08005000
#define USER_ADDR_RAM 0x20000C00

void setup_nvic() {
#ifdef VECT_TAB_FLASH
  nvic_init(USER_ADDR_ROM, 0);
#elif defined VECT_TAB_RAM
  nvic_init(USER_ADDR_RAM, 0);
#elif defined VECT_TAB_BASE
  nvic_init((uint32) 0x08000000, 0);
#else
#error "You must select a base address for the vector table."
#endif
}

/**
 * @brief Initialize and enable SysTick.
 *
 * Clocks the system timer with the core clock, turns it on, and
 * enables interrupts.
 *
 * @param reload_val Appropriate reload counter to tick every 1 ms.
 */
void systick_init(uint32_t reload_val) {
  STM32_SYSTICK_RVR = reload_val;
  systick_enable();
}

/**
 * Clock the system timer with the core clock and turn it on;
 * interrupt every 1 ms, for systick_timer_millis.
 */
void systick_enable() {
  /* re-enables init registers without changing reload val */
  STM32_SYSTICK_CSR =
          STM32_SYSTICK_CSR_CLKSOURCE_CORE
          | STM32_SYSTICK_CSR_ENABLE
          | STM32_SYSTICK_CSR_TICKINT_PEND;
}

/**
 * @brief Initialize the NVIC, setting interrupts to a default priority.
 */
void nvic_init(uint32_t address, uint32_t offset) {
  uint32_t i;

  nvic_set_vector_table(address, offset);

  /*
   * Lower priority level for all peripheral interrupts to lowest
   * possible.
   */
  for (i = 0; i < STM32_NR_INTERRUPTS; i++) {
    nvic_irq_set_priority(i, 0xF);
  }

  /* Lower systick interrupt priority to lowest level */
  nvic_irq_set_priority(NVIC_SYSTICK, 0xF);
}

/**
 * @brief Set the vector table base address.
 *
 * For stand-alone products, the vector table base address is normally
 * the start of Flash (0x08000000).
 *
 * @param address Vector table base address.
 * @param offset Offset from address.  Some restrictions apply to the
 *               use of nonzero offsets; see the ARM Cortex M3
 *               Technical Reference Manual.
 */
void nvic_set_vector_table(uint32_t address, uint32_t offset) {
  STM32_SCB_VTOR = address | (offset & 0x1FFFFF80);
}

/**
 * @brief Set interrupt priority for an interrupt line
 *
 * Note: The STM32 only implements 4 bits of priority, ignoring the
 * lower 4 bits. This means there are only 16 levels of priority.
 * Bits[3:0] read as zero and ignore writes.
 *
 * @param irqn device to set
 * @param priority Priority to set, 0 being highest priority and 15
 *                 being lowest.
 */
void nvic_irq_set_priority(uint32_t irqn, uint8_t priority) {
  if (irqn < 0) {
    /* This interrupt is in the system handler block */
    SCB_BASE->SHP[((uint32_t) irqn & 0xF) - 4] = (priority & 0xF) << 4;
  } else {
    NVIC_BASE->IP[irqn] = (priority & 0xF) << 4;
  }
}