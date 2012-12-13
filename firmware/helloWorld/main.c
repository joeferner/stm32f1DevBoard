#define STACK_TOP 0x20000800   // just a tiny stack for demo

static void nmi_handler();
static void hardfault_handler();
int main();

// Define the vector table
unsigned int *myvectors[4]
__attribute__ ((section("vectors"))) = {
  (unsigned int *) STACK_TOP,         // stack pointer
  (unsigned int *) main,              // code entry point
  (unsigned int *) nmi_handler,       // NMI handler (not really)
  (unsigned int *) hardfault_handler  // hard fault handler
};


int main() {
  int i = 0;

  for(;;) {
    i++;
  }
}

void nmi_handler() {
  for(;;);
}

void hardfault_handler() {
  for(;;);
}
