#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "gpio.h"
#include "std_types.h"

#define DC_MOTOR_PIN1_PORT		PORTB_ID
#define DC_MOTOR_PIN2_PORT		PORTB_ID

#define DC_MOTOR_IN1_PIN		PIN0_ID
#define DC_MOTOR_IN2_PIN		PIN1_ID
#define DC_MOTOR_EN_PIN    		PIN3_ID


typedef enum{
	CW,ACW,STOP
}DC_MOTOR_state;

void DC_MOTOR_init(void);
void DC_MOTOR_rotate(DC_MOTOR_state state, uint8 speed);


#endif /* DC_MOTOR_H_ */
