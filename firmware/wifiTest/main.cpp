
#include <wirish/wirish.h>
#include <mrf24w/mrf24w.h>

#define WIFI_CS  D11
#define WIFI_INT D12
#define WIFI_SPI 1

HardwareSPI spi1(WIFI_SPI);
Mrf24w wifi(spi1, WIFI_CS, WIFI_INT);

void setup() {
  delay(1000); // not needed just easier to debug
  Serial1.begin(9600);
  Serial1.println("begin");
  spi1.begin(SPI_4_5MHZ, MSBFIRST, 0);

  wifi.begin();
}

void loop() {
  wifi.loop();
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
