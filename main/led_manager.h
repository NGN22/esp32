#ifndef LED_MANAGER_H
#define LED_MANAGER_H

void led_init(void);

void led_red_on(void);
void led_red_off(void);

void led_green_on(void);
void led_green_off(void);

void led_yellow_on(void);
void led_yellow_off(void);

void led_all_off(void);

void led_red_toggle(void);
void led_green_toggle(void);
void led_yellow_toggle(void);

#endif