
#include <wirish/wirish.h>
#include <sdcard/Sd2Card.h>

#define SDCARD_CS  D10

HardwareSPI spi1(1);
Sd2Card sdcard(spi1, SDCARD_CS);

void setup() {
  uint8_t blockBuffer[512];
  for (int i = 0; i < 512; i++) {
    blockBuffer[0];
  }

  delay(5000);
  SerialUSB.println("Begin");
  spi1.begin(SPI_QUARTER_SPEED, MSBFIRST, 0);
  sdcard.begin();

  SerialUSB.print("cardSize:");
  uint32_t cardSize = sdcard.getCardSize();
  SerialUSB.println(cardSize);

  SerialUSB.println("block(0):");
  sdcard.readBlock(0, blockBuffer);
  for (int i = 0; i < 512;) {
    for (int col = 0; col < 16; col++, i++) {
      SerialUSB.print(blockBuffer[i], 16);
      SerialUSB.print(" ");
    }
    SerialUSB.println();
  }

  SerialUSB.print("cardSize:");
  cardSize = sdcard.getCardSize();
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
