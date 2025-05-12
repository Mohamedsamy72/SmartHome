#include "ldr.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void){

	uint16 lightIntensity = 0;
	uint16 adc_value = 0;

	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL);
	lightIntensity = (((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * LDR_SENSOR_MAX_VOLT) / (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT));


	return lightIntensity;
}

