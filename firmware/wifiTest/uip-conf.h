
#ifndef UIP_CONF_H
#define	UIP_CONF_H

#include <inttypes.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * 8 bit datatype
 *
 * This typedef defines the 8-bit type used throughout uIP.
 *
 * \hideinitializer
 */
typedef uint8_t u8_t;

/**
 * 16 bit datatype
 *
 * This typedef defines the 16-bit type used throughout uIP.
 *
 * \hideinitializer
 */
typedef uint16_t u16_t;

/**
 * Statistics datatype
 *
 * This typedef defines the dataype used for keeping statistics in
 * uIP.
 *
 * \hideinitializer
 */
typedef unsigned short uip_stats_t;

/**
 * Maximum number of TCP connections.
 *
 * \hideinitializer
 */
#define UIP_CONF_MAX_CONNECTIONS 1

/**
 * Maximum number of listening TCP ports.
 *
 * \hideinitializer
 */
#define UIP_CONF_MAX_LISTENPORTS 1

/**
 * uIP buffer size.
 *
 * \hideinitializer
 */
#define UIP_CONF_BUFFER_SIZE     400

/**
 * CPU byte order.
 *
 * \hideinitializer
 */
#define UIP_CONF_BYTE_ORDER      LITTLE_ENDIAN

/**
 * Logging on or off
 *
 * \hideinitializer
 */
#define UIP_CONF_LOGGING         1

/**
 * UDP support on or off
 *
 * \hideinitializer
 */
#define UIP_CONF_UDP             1

/**
 * UDP checksums on or off
 *
 * \hideinitializer
 */
#define UIP_CONF_UDP_CHECKSUMS   0

/**
 * uIP statistics on or off
 *
 * \hideinitializer
 */
#define UIP_CONF_STATISTICS      0

/**
 * Broadcast support.
 *
 * \hideinitializer
 */
#define UIP_CONF_BROADCAST		1

/**
 * The maximum amount of concurrent UDP connections.
 *
 * \hideinitializer
 */
#define UIP_CONF_UDP_CONNS		1

typedef struct uip_tcp_appstate {
  char state;
} uip_tcp_appstate_t;

typedef struct uip_udp_appstateF {
  char state;
} uip_udp_appstate_t;

void appcall();
#define UIP_APPCALL appcall
void udp_appcall();
#define UIP_UDP_APPCALL udp_appcall
void uip_log(char *msg);

extern uint8_t local_ip[];
extern uint8_t gateway_ip[];
extern uint8_t subnet_mask[];

#ifdef	__cplusplus
}
#endif

#endif	/* UIP_CONF_H */

