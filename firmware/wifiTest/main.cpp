
#include <stdint.h>
#include "g2100.h"
#include "uip-conf.h"

uint8_t local_ip[] = {192, 168, 0, 99};
uint8_t gateway_ip[] = {192, 168, 0, 1};
uint8_t subnet_mask[] = {255, 255, 255, 0};

int main(int argc, char** argv) {
  zg_init();

  return 0;
}

void appcall() {

}

void udp_appcall() {
  
}

void uip_log(char *msg) {
  
}