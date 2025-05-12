#include "led.h"
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"

void LEDS_init(void){

	GPIO_setupPinDirection(PORTB_ID, RED_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, GREEN_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, BLUE_LED, PIN_OUTPUT);

	LED_off(RED_LED);
	LED_off(GREEN_LED);
	LED_off(BLUE_LED);

}

void LED_on(LED_ID id){

	GPIO_writePin(PORTB_ID, id, LOGIC_HIGH);

}

void LED_off(LED_ID id){

	GPIO_writePin(PORTB_ID, id, LOGIC_LOW);

}
