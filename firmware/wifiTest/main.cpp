
#include <wirish/wirish.h>
#include <mrf24w/mrf24w.h>
#include <string.h>

#define WIFI_CS             D11
#define WIFI_INT            D12
#define WIFI_CONNECTION_LED D13
#define WIFI_SPI            1

#define ECHO_PORT 8000

uint8_t wifiLocalIp[] = {192, 168, 0, 99};
uint8_t wifiGatewayIp[] = {192, 168, 0, 1};
uint8_t wifiSubnetMask[] = {255, 255, 255, 0};
const char* wifiSSID = "Test";
const char* wifiSecurityPassphrase = "Test";
uint8_t wifiSecurityType = ZG_SECURITY_TYPE_NONE;
uint8_t wifiWirelessMode = WIRELESS_MODE_INFRA;

HardwareSPI spi1(WIFI_SPI);
Mrf24w wifi(spi1, WIFI_CS, WIFI_INT);

void setup() {
  delay(1000); // not needed just easier to debug
  pinMode(WIFI_CONNECTION_LED, OUTPUT);
  Serial1.begin(9600);
  Serial1.println("begin");
  spi1.begin(SPI_4_5MHZ, MSBFIRST, 0);

  wifi.setLocalIp(wifiLocalIp);
  wifi.setGatewayIp(wifiGatewayIp);
  wifi.setSubnetMask(wifiSubnetMask);
  wifi.setSSID(wifiSSID);
  wifi.setSecurityPassphrase(wifiSecurityPassphrase);
  wifi.setSecurityType(wifiSecurityType);
  wifi.setWirelessMode(wifiWirelessMode);
  wifi.begin();

  uip_listen(HTONS(ECHO_PORT));
}

void loop() {
  wifi.loop();
}

extern "C" void echo_appcall() {
  if (uip_conn->lport == HTONS(ECHO_PORT)) {
    struct echo_state* s = uip_conn->appstate;

    if (uip_connected()) {
      s->state = ECHO_STATE_WELCOME_SENT;
      uip_send("start echo!", strlen("start echo!"));
    }

    if (uip_acked() && s->state == ECHO_STATE_WELCOME_SENT) {
      s->state = ECHO_STATE_WELCOME_ACKED;
    }

    if (uip_newdata()) {
      uip_send(uip_appdata, uip_datalen());
    }

    if (uip_rexmit()) {
      switch (s->state) {
        case ECHO_STATE_WELCOME_SENT:
          uip_send("start echo!", strlen("start echo!"));
          break;
        case ECHO_STATE_WELCOME_ACKED:
          // don't have the data anymore
          break;
      }
    }
  }
}

extern "C" void uip_log(char *msg) {
  Serial1.println(msg);
}

extern "C" void zg_LEDConn_off() {
  digitalWrite(WIFI_CONNECTION_LED, LOW);
}

extern "C" void zg_LEDConn_on() {
  digitalWrite(WIFI_CONNECTION_LED, HIGH);
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
