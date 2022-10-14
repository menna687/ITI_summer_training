#include "STD_TYPES.h"
#include "BitMath.h"
#include "ADC_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"

void ADC_voidInit(void)
{
	/*AVCC & AREF*/
	SetBit(ADMUX , pin6);
	ClrBit(ADMUX , pin7);
	/*Right Adjust*/
	ClrBit(ADMUX , pin5);
}

u16 ADC_voidStartConversion(u16 Copy_u16SelectChannel , u8 Copy_u8DivisionFactor)
{
	/*channel selection*/
	switch(Copy_u16SelectChannel)
	{
	case ADC0 :
		ClrBit(ADMUX , pin0);
		ClrBit(ADMUX , pin1);
		ClrBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC1 :
		SetBit(ADMUX , pin0);
		ClrBit(ADMUX , pin1);
		ClrBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC2 :
		ClrBit(ADMUX , pin0);
		SetBit(ADMUX , pin1);
		ClrBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC3 :
		SetBit(ADMUX , pin0);
		SetBit(ADMUX , pin1);
		ClrBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC4 :
		ClrBit(ADMUX , pin0);
		ClrBit(ADMUX , pin1);
		SetBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC5 :
		SetBit(ADMUX , pin0);
		ClrBit(ADMUX , pin1);
		SetBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC6 :
		ClrBit(ADMUX , pin0);
		SetBit(ADMUX , pin1);
		SetBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;

	case ADC7 :
		SetBit(ADMUX , pin0);
		SetBit(ADMUX , pin1);
		SetBit(ADMUX , pin2);
		ClrBit(ADMUX , pin3);
		ClrBit(ADMUX , pin4);
		break;
	}
	/*pre_scaler*/
	ADCSRA = Copy_u8DivisionFactor;
	/*ADC Enable*/
	SetBit(ADCSRA , pin7);
	/*Start conversion*/
	SetBit(ADCSRA , pin6);

	while(GetBit(ADCSRA , pin6) != 0);

	return ADC;
}
