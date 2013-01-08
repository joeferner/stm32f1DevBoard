
#include "g2100.h"

static uint8_t mac[6];
static uint8_t intr_valid;
static uint8_t zg_drv_state;
static uint8_t* zg_buf;
static uint16_t zg_buf_len;

void zg_init() {
  intr_valid = 0;
}

uint8_t* zg_get_mac() {
  return mac;
}

void zg_drv_process() {
  if (intr_valid) {
    switch (zg_buf[1]) {
      case ZG_MAC_TYPE_MGMT_CONFIRM:
        if (zg_buf[3] == ZG_RESULT_SUCCESS) {
          switch (zg_buf[2]) {
            case ZG_MAC_SUBTYPE_MGMT_REQ_GET_PARAM:
              mac[0] = zg_buf[7];
              mac[1] = zg_buf[8];
              mac[2] = zg_buf[9];
              mac[3] = zg_buf[10];
              mac[4] = zg_buf[11];
              mac[5] = zg_buf[12];
              zg_drv_state = DRV_STATE_SETUP_SECURITY;
              break;
          }
        }
        break;
    }
  }
}