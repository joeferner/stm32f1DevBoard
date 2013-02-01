
#include <wirish/wirish.h>
#include <mrf24w/mrf24w.h>
#include <string.h>

#define SDCARD_CS           PA0
#define SDCARD_SPI          1

#define WIFI_CS             PB0
#define WIFI_INT            PA4
#define WIFI_CONNECTION_LED PB5
#define WIFI_RESET          PA1
#define WIFI_WP             PB1
#define WIFI_HIBERNATE      PB2
#define WIFI_SPI            SDCARD_SPI

#define ECHO_PORT 8000

uint8_t wifiLocalIp[] = {10, 20, 8, 77};
uint8_t wifiGatewayIp[] = {10, 20, 8, 1};
uint8_t wifiSubnetMask[] = {255, 255, 255, 0};
const char* wifiSSID = "RHE";
const char* wifiSecurityPassphrase = "";
uint8_t wifiSecurityType = ZG_SECURITY_TYPE_NONE;
uint8_t wifiWirelessMode = ZG_WIRELESS_MODE_INFRA;

HardwareSPI spi1(WIFI_SPI);
Mrf24w wifi(spi1, WIFI_CS, WIFI_INT);

void wifiConnected(uint8_t connected);

void setup() {
  Serial1.begin(9600);
  Serial1.println("begin");

  enableDebugPorts();
  //delay(5000);
  //disableDebugPorts();
  
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);
  pinMode(WIFI_CS, OUTPUT);
  digitalWrite(WIFI_CS, HIGH);
  
  pinMode(WIFI_RESET, OUTPUT);
  pinMode(WIFI_HIBERNATE, OUTPUT);
  digitalWrite(WIFI_HIBERNATE, LOW);
  pinMode(WIFI_WP, OUTPUT);
  digitalWrite(WIFI_WP, LOW);
  pinMode(WIFI_CONNECTION_LED, OUTPUT);
  digitalWrite(WIFI_CONNECTION_LED, LOW);
  spi1.begin(SPI_4_5MHZ, MSBFIRST, 0);

  Serial1.println("wifi setup");
  digitalWrite(WIFI_RESET, LOW);
  delay(100);
  digitalWrite(WIFI_RESET, HIGH);

  wifi.setConnectedFn(wifiConnected);
  wifi.setLocalIp(wifiLocalIp);
  wifi.setGatewayIp(wifiGatewayIp);
  wifi.setSubnetMask(wifiSubnetMask);
  wifi.setSSID(wifiSSID);
  wifi.setSecurityPassphrase(wifiSecurityPassphrase);
  wifi.setSecurityType(wifiSecurityType);
  wifi.setWirelessMode(wifiWirelessMode);
  Serial1.println("wifi begin");
  wifi.begin();
  Serial1.println("wifi begin complete");

  uip_listen(HTONS(ECHO_PORT));
}

void loop() {
  wifi.loop();
  
  while(Serial1.available() > 0) {
    uint8_t b = Serial1.read();
    if(b == 'r') {
      Serial1.println("rebooting 1sec");
      delay(1000);
      nvic_sys_reset();
    }
  }
}

extern "C" void echo_appcall() {
  Serial1.println("echo_appcall");

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

void wifiConnected(uint8_t connected) {
  if (connected) {
    digitalWrite(WIFI_CONNECTION_LED, HIGH);
  } else {
    digitalWrite(WIFI_CONNECTION_LED, LOW);
  }
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
