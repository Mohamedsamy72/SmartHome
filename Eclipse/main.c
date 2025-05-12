#include "adc.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lcd.h"
#include "ldr.h"
#include "led.h"
#include "lm35_sensor.h"
#include "pwm.h"

void initialization(void);
void light_intensity(void);
void fan_speed_control(void);
void fire_detection(void);
void display(void);

int main(void){

	initialization();

	while(1){
		display();
		light_intensity();
		fan_speed_control();
		fire_detection();
	}
}

void initialization(void){
	ADC_init();
	BUZZER_init();
	DC_MOTOR_init();
	FlameSensor_init();
	LCD_init();
	LEDS_init();
}
void light_intensity(void){

	if((int)(LDR_getLightIntensity()) < 15){

		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_on(BLUE_LED);

	}

	else if((int)(LDR_getLightIntensity()) >= 16 && (int)(LDR_getLightIntensity()) <= 50) {

		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_off(BLUE_LED);

	}
	else if((int)(LDR_getLightIntensity()) >= 51 && (int)(LDR_getLightIntensity()) <= 70) {

		LED_on(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);

	}

	else{

		LED_off(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);

	}
}
void fan_speed_control(void){


	    if(LM35_getTemperature()<25){
	         DC_MOTOR_rotate(STOP, 0);

	    }
	    else if(LM35_getTemperature()<30){
	         DC_MOTOR_rotate(CW, 25);
	    }
	    else if(LM35_getTemperature()<35){
	         DC_MOTOR_rotate(CW, 50);
	    }
	    else if(LM35_getTemperature()<40){
	         DC_MOTOR_rotate(CW, 75);
	    }
	    else{
	         DC_MOTOR_rotate(CW, 100);
	    }

}
void fire_detection(void){

	if(FlameSensor_getValue()){
		LCD_clearScreen();
		LCD_displayStringRowColumn(0, 0, "Critical Alert!");
		BUZZER_on();
		while(FlameSensor_getValue());
		LCD_clearScreen();

	}
	else{
		BUZZER_off();
	}


}
void display(void){

	if(LM35_getTemperature()<25){
		 LCD_displayStringRowColumn(0,3,"FAN is OFF");
	}
	else{
		 LCD_displayStringRowColumn(0,3,"FAN is ON ");
	}

	 LCD_displayStringRowColumn(1,0,"Temp=");
	 LCD_intgerToString((int)(LM35_getTemperature()));

	 LCD_displayString(" LDR=");

	 if(LDR_getLightIntensity() != 100){

		 if(LDR_getLightIntensity() < 10){
			 LCD_displayCharacter(' ');
		 }
		 LCD_displayCharacter(' ');

	 }

	 LCD_intgerToString((int)(LDR_getLightIntensity()));
	 LCD_displayCharacter('%');



}
