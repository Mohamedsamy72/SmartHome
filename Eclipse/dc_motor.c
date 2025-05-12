#include "dc_motor.h"
#include "pwm.h"

void DC_MOTOR_init(void){

	GPIO_setupPinDirection(DC_MOTOR_PIN1_PORT, DC_MOTOR_IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PIN2_PORT, DC_MOTOR_IN2_PIN, PIN_OUTPUT);

	DC_MOTOR_rotate(STOP, 0);

}


void DC_MOTOR_rotate(DC_MOTOR_state state, uint8 speed){

	PWM_Timer0_Start(speed);

	if(state == CW){
		GPIO_writePin(DC_MOTOR_PIN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PIN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);
	}

	else if(state == ACW){
		GPIO_writePin(DC_MOTOR_PIN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PIN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_HIGH);
	}

	else{
		GPIO_writePin(DC_MOTOR_PIN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PIN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);

	}


}
