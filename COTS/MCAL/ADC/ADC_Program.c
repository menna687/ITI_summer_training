#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "avr/delay.h"


void ADC_voidInit(void)
{
	// voltage reference: AVCC, capacitor at AREF
	SET_BIT(ADMUX_REG, 6);
	CLR_BIT(ADMUX_REG, 7);
	
	// Right adjust result
	CLR_BIT(ADMUX_REG, 5);
	
	// Left adjust result
	//SET_BIT(ADMUX_REG, 5);

	// Set default channel   
	ADMUX_REG = ADMUX_REG | DEFAULT_CHANNEL;
	
	// Prescalar 
	ADCSRA = ADCSRA | PRESCALAR_FACTOR;
	
	// ADC Enable
	SET_BIT(ADCSRA, 7);
	
	// ADC start conversion	
	// SET_BIT(ADCSRA, 6);
}


void ADC_voidConvertChannel(u8 channel)
{
	// Set channel bits and keep other register bits
	ADMUX_REG = (ADMUX_REG & (0xE0)) | channel;
}


u16  ADC_u16GetResult(void)
{
	// ADC start conversion
	SET_BIT(ADCSRA, 6);

	// wait until conversion is complete
	while(GET_BIT(ADCSRA, 6))
	{

	}
	return ADC;
}
