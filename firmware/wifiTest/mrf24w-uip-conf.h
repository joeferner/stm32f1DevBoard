
#ifndef MRF24W_UIP_CONF_H
#define	MRF24W_UIP_CONF_H

#ifdef	__cplusplus
extern "C" {
#endif

void echo_appcall(void);
#define UIP_APPCALL     echo_appcall

struct echo_state {
  uint8_t state;
};

typedef struct echo_state uip_tcp_appstate_t;

#ifdef	__cplusplus
}
#endif

#endif	/* MRF24W_UIP_CONF_H */

