
#include <wirish/wirish.h>
#include <usbMassStorage/usbMassStorage.h>
#include <sdcard/Sd2Card.h>

#define SDCARD_CS  D10
#define SDCARD_SPI 1

uint32_t MAL_massBlockCount[2];
uint32_t MAL_massBlockSize[2];

HardwareSPI spi1(SDCARD_SPI);
Sd2Card sdcard(spi1);

void setup() {
  spi1.begin(SPI_QUARTER_SPEED, MSBFIRST, 0);
  sdcard.begin(SPI_QUARTER_SPEED, SDCARD_CS);
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

extern "C" uint16_t usb_mass_mal_init(uint8_t lun) {
  MAL_massBlockCount[0] = sdcard.getCardSize();
  MAL_massBlockCount[1] = 0;
  MAL_massBlockSize[0] = 512;
  MAL_massBlockSize[1] = 0;
  return 0;
}

extern "C" uint16_t usb_mass_mal_get_status(uint8_t lun) {
  return sdcard.getErrorCode();
}

extern "C" uint16_t usb_mass_mal_write_memory(uint8_t lun, uint32_t memoryOffset, uint8_t *writebuff, uint16_t transferLength) {
  if (lun != 0) {
    return USB_MASS_MAL_FAIL;
  }
  if (sdcard.writeBlock(memoryOffset / 512, writebuff)) {
    return USB_MASS_MAL_SUCCESS;
  }
  return USB_MASS_MAL_FAIL;
}

extern "C" uint16_t usb_mass_mal_read_memory(uint8_t lun, uint32_t memoryOffset, uint8_t *readbuff, uint16_t transferLength) {
  if (lun != 0) {
    return USB_MASS_MAL_FAIL;
  }
  if (sdcard.readBlock(memoryOffset / 512, readbuff)) {
    return USB_MASS_MAL_SUCCESS;
  }
  return USB_MASS_MAL_FAIL;
}

extern "C" void usb_mass_mal_format() {
}
