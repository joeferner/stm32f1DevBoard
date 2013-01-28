
#define GPIOA_CRL   (*((volatile unsigned int*)(0x40010800))) 
#define GPIOA_CRH   (*((volatile unsigned int*)(0x40010804))) 
#define GPIOA_IDR   (*((volatile unsigned int*)(0x40010808))) 
#define GPIOA_ODR   (*((volatile unsigned int*)(0x4001080C))) 
#define GPIOA_BSRR  (*((volatile unsigned int*)(0x40010810))) 
#define GPIOD_CRH   (*((volatile unsigned int*)(0x40011404))) 
#define GPIOD_BSRR  (*((volatile unsigned int*)(0x40011410))) 
#define RCC_APB2ENR (*((volatile unsigned int*)(0x40021018))) 

void ResetISR(void); 
void NMIException(void); 
void HardFaultException(void); 
void delay(void); 

typedef void (*pfnISR)(void);    // Pointer to exception handle function 

__attribute__ ((section(".isr_vector")))
pfnISR VectorTable[] =  
{ 
  (pfnISR)(0x20001000),  // The initial stack pointer is the top of SRAM 
  ResetISR,              // The reset handler 
  NMIException, 
  HardFaultException 
}; 

void delay(void) 
{ 
  unsigned int i; 
  for(i = 0; i < 0x3ffff; ++i) {
    asm("nop"); 
  }
} 

int main(void) 
{
  int led;

  RCC_APB2ENR |= (1<<5); 
  RCC_APB2ENR |= (1<<2); 
  GPIOA_CRL = 0x44444441; 
  
  while(1){
      if (led == 0) {
        GPIOA_ODR |= (1<<0);
        led = 1;
      }
      else {
        GPIOA_ODR &= ~(1<<0);
        led = 0;
      }
      
      delay();
  }
}

//***************************************************************************** 
// 
// The following are constructs created by the linker, indicating where the 
// the "data" and "bss" segments reside in memory.  The initializers for the 
// for the "data" segment resides immediately following the "text" segment. 
// 
//***************************************************************************** 
extern unsigned long _etext; 
extern unsigned long _data; 
extern unsigned long _edata; 
extern unsigned long _bss; 
extern unsigned long _ebss; 

void ResetISR(void) 
{ 
  //unsigned long *src, *dst; 
  
  // 
  // Copy the data segment initializers from flash to SRAM. 
  // 
  //src = &_etext;
  //dst = &_data;
  //while (dst < &_edata) {
  //  *dst++ = *src++;
  //}
  
  // 
  // Zero fill the bss segment. 
  // 
  //for(dst = &_bss; dst < &_ebss; dst++) { 
  //  *dst = 0; 
  //} 
  
  // 
  // Call the application's entry point. 
  // 
  main(); 
} 

void NMIException(void) 
{ 
  return; 
} 

void HardFaultException(void) 
{ 
  return; 
}

