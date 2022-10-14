#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

void ADC_voidInit()
{
	// AVCC, AREF
	SET_BIT(ADMUX_REG, 6);
	CLR_BIT(ADMUX_REG, 7);
	
	// Right adjust
	CLR_BIT(ADMUX_REG, 5);
	
	// Select channel
	CLR_BIT(ADMUX_REG, 0);
	CLR_BIT(ADMUX_REG, 1);
	CLR_BIT(ADMUX_REG, 2);
	CLR_BIT(ADMUX_REG, 3);
	CLR_BIT(ADMUX_REG, 4);
	
	// Prescalar (64)
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	CLR_BIT(ADCSRA, 0);
	
	// ADC Enable
	SET_BIT(ADCSRA, 7);
	
	// ADC start conversion	
	SET_BIT(ADCSRA, 6);
}

u16  ADC_u16GetResult()
{
	return ADC;
}