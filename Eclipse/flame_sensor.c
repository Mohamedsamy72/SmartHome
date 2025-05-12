#include "flame_sensor.h"
#include "common_macros.h"

void FlameSensor_init(void){

	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_OUTPUT);

}


uint8 FlameSensor_getValue(void){

	uint8 flame_value;

	if(BIT_IS_SET(FLAME_SENSOR_PIN_REG,FLAME_SENSOR_PIN)){
		flame_value = LOGIC_HIGH;
	}
	else{
		flame_value = LOGIC_LOW;
	}

	return flame_value;
}

