
#include <uip.h>
#include <timer.h>
#include <uip_arp.h>
#include "g2100.h"

static struct timer periodic_timer, arp_timer, self_arp_timer;

void stack_init() {
  uip_ipaddr_t ipaddr;

  struct uip_eth_addr mac;

  uint8_t* mac_addr = zg_get_mac();

  mac.addr[0] = mac_addr[0];
  mac.addr[1] = mac_addr[1];
  mac.addr[2] = mac_addr[2];
  mac.addr[3] = mac_addr[3];
  mac.addr[4] = mac_addr[4];
  mac.addr[5] = mac_addr[5];

  timer_set(&periodic_timer, CLOCK_SECOND / 2);
  timer_set(&arp_timer, CLOCK_SECOND * 10);
  timer_set(&self_arp_timer, CLOCK_SECOND * 30);

  uip_init();

  uip_setethaddr(mac);

  uip_ipaddr(ipaddr, local_ip[0], local_ip[1], local_ip[2], local_ip[3]);
  uip_sethostaddr(ipaddr);
  uip_ipaddr(ipaddr, gateway_ip[0], gateway_ip[1], gateway_ip[2], gateway_ip[3]);
  uip_setdraddr(ipaddr);
  uip_ipaddr(ipaddr, subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
  uip_setnetmask(ipaddr);
}