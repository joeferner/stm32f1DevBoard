
#include <wirish/wirish.h>
#include <sdcard/Sd2Card.h>

#define SDCARD_CS  D10

HardwareSPI spi1(1);
Sd2Card sdcard(spi1);

void setup() {
  delay(5000);
  SerialUSB.println("Begin");
  spi1.begin(SPI_QUARTER_SPEED, MSBFIRST, 0);
  sdcard.init(SPI_QUARTER_SPEED, SDCARD_CS);
  
  SerialUSB.print("cardSize:");
  uint32_t cardSize = sdcard.cardSize();
  SerialUSB.println(cardSize);

  pinMode(BOARD_LED_PIN, OUTPUT);
}

void loop() {
  togglePin(BOARD_LED_PIN);
  SerialUSB.println("Working");
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
