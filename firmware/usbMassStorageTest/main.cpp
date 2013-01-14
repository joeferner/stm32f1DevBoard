
#include <wirish/wirish.h>
#include <usbMassStorage/usbMassStorage.h>

void setup() {
  USBMassStorage.begin();

  pinMode(BOARD_LED_PIN, OUTPUT);
}

void loop() {
  togglePin(BOARD_LED_PIN);
  delay(1000);
}

// Force init to be called *first*, i.e. before static object allocation.
// Otherwise, statically allocated objects that need libmaple may fail.
__attribute__((constructor)) void premain() {
  init();
}

int main(void) {
  setup();

  while (true) {
    loop();
  }

  return 0;
}
