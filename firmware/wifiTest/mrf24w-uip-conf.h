
#ifndef MRF24W_UIP_CONF_H
#define	MRF24W_UIP_CONF_H

#ifdef	__cplusplus
extern "C" {
#endif

  void echo_appcall(void);
  void uip_log(char *msg);
  void zg_LEDConn_off();
  void zg_LEDConn_on();
#define UIP_APPCALL     echo_appcall

  typedef enum echo_state_enum_t {
    ECHO_STATE_WELCOME_SENT,
    ECHO_STATE_WELCOME_ACKED
  } echo_state_enum;

  struct echo_state {
    echo_state_enum state;
  };

  typedef struct echo_state* uip_tcp_appstate_t;

#ifdef	__cplusplus
}
#endif

#endif	/* MRF24W_UIP_CONF_H */

