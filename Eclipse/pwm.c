#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle){


	TCNT0 = 0;
	OCR0 = (duty_cycle*255) / 100;
	TCCR0 |= 0x6D; // fast PWM mode, non-inverting, 1024 Pre-Scaler,

	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

}
