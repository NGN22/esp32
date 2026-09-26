#include "led_manager.h"
#include "driver/gpio.h"

#include <stdbool.h>

#define LED_RED     GPIO_NUM_32
#define LED_GREEN   GPIO_NUM_33
#define LED_YELLOW  GPIO_NUM_25

static bool red_state = false;
static bool green_state = false;
static bool yellow_state = false;

static void configure_led(gpio_num_t gpio)
{
    gpio_reset_pin(gpio);
    gpio_set_direction(gpio, GPIO_MODE_OUTPUT);
    gpio_set_level(gpio, 0);
}

void led_init(void)
{
    configure_led(LED_RED);
    configure_led(LED_GREEN);
    configure_led(LED_YELLOW);
}

void led_red_on(void)
{
    gpio_set_level(LED_RED, 1);
}

void led_red_off(void)
{
    gpio_set_level(LED_RED, 0);
}

void led_green_on(void)
{
    gpio_set_level(LED_GREEN, 1);
}

void led_green_off(void)
{
    gpio_set_level(LED_GREEN, 0);
}

void led_yellow_on(void)
{
    gpio_set_level(LED_YELLOW, 1);
}

void led_yellow_off(void)
{
    gpio_set_level(LED_YELLOW, 0);
}

void led_all_off(void)
{
    led_red_off();
    led_green_off();
    led_yellow_off();
}

void led_red_toggle(void)
{
    red_state = !red_state;
    gpio_set_level(LED_RED, red_state);
}

void led_green_toggle(void)
{
    green_state = !green_state;
    gpio_set_level(LED_GREEN, green_state);
}

void led_yellow_toggle(void)
{
    yellow_state = !yellow_state;
    gpio_set_level(LED_YELLOW, yellow_state);
}