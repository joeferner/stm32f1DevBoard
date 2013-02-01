
#include <wirish/wirish.h>
#include <sdfat/Sd2Card.h>

#define SDCARD_SPI 1
#define SDCARD_CS  PA0

HardwareSPI spi1(SDCARD_SPI);
Sd2Card sdcard(spi1);

void setup() {
  Serial1.begin(9600);
  Serial1.println("begin");

  enableDebugPorts();
  delay(5000);
  disableDebugPorts();
  
  uint8_t blockBuffer[512];
  for (int i = 0; i < 512; i++) {
    blockBuffer[i] = 0;
  }

  Serial1.println("spi begin");
  spi1.begin(SPI_QUARTER_SPEED, MSBFIRST, 0);
  Serial1.println("sdcard begin");
  sdcard.init(SPI_QUARTER_SPEED, SDCARD_CS);
  Serial1.println(sdcard.errorData());

  Serial1.print("cardSize:");
  uint32_t cardSize = sdcard.cardSize();
  Serial1.println(cardSize);

  Serial1.println("block(0):");
  sdcard.readBlock(0, blockBuffer);
  for (int i = 0; i < 512;) {
    for (int col = 0; col < 16; col++, i++) {
      Serial1.print(blockBuffer[i], 16);
      Serial1.print(" ");
    }
    Serial1.println();
  }

  Serial1.print("cardSize:");
  cardSize = sdcard.cardSize();
  Serial1.println(cardSize);

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
