#ifndef PIN_CONFIG_H_
#define PIN_CONFIG_H_

#define led_PIN (1<<PB7)
#define led_PORT PORTB

#define led_off	led_PORT |= led_PIN
#define led_change	led_PORT ^= led_PIN
#define led_on led_PORT &= ~led_PIN

#define BUTTON_PIN (1<<PD3)

#define Switch1_PIN (1<<PD4)
#define Switch2_PIN (1<<PD0)

#define Switch1_enable_PullUP PORTD |= (Switch1_PIN)
#define Switch1_disble_PullUP PORTD &= ~(Switch1_PIN)
#define Switch2_enable_PullUP PORTD |= (Switch2_PIN)
#define Switch2_disble_PullUP PORTD &= ~(Switch2_PIN)

#define Switch1_HIGH (PIND & Switch1_PIN)
#define Switch2_HIGH (PIND & Switch2_PIN)

#define BUTTON_HIGH (PIND & BUTTON_PIN)

#endif 