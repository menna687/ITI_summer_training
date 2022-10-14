#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "TMR1_Private.h"
#include "TMR1_Config.h"
#include "TMR1_Interface.h"

void TMR1_voidInit()
{
#if MODE == NORMAL
	CLR_BIT(TCCR1A, WGM10_BIT);
	CLR_BIT(TCCR1A, WGM11_BIT);
	CLR_BIT(TCCR1B, WGM12_BIT);
	CLR_BIT(TCCR1B, WGM13_BIT);
	// Overflow interrupt enable
	SET_BIT(TIMSk, 2);

#elif MODE == FAST_PWM
	CLR_BIT(TCCR1A, WGM10_BIT);
	SET_BIT(TCCR1A, WGM11_BIT);
	SET_BIT(TCCR1B, WGM12_BIT);
	SET_BIT(TCCR1B, WGM13_BIT);
	
// phase correct
#elif MODE == PHASE_CORRECT
	CLR_BIT(TCCR1A, WGM10_BIT);
	SET_BIT(TCCR1A, WGM11_BIT);
	CLR_BIT(TCCR1B, WGM12_BIT);
	SET_BIT(TCCR1B, WGM13_BIT);

#endif

	// Non inverting
	SET_BIT(TCCR1A, COM1A1_BIT);
	SET_BIT(TCCR1A, COM1B1_BIT);
	
	CLR_BIT(TCCR1A, COM1A0_BIT);
	CLR_BIT(TCCR1A, COM1B0_BIT);
	
	// Select prescalar (/8)
	CLR_BIT(TCCR1B, CS10_BIT);
	SET_BIT(TCCR1B, CS11_BIT);
	CLR_BIT(TCCR1B, CS12_BIT);
}


void TMR1_voidInitICU()
{
	CLR_BIT(TCCR1A, WGM10_BIT);
	CLR_BIT(TCCR1A, WGM11_BIT);
	CLR_BIT(TCCR1B, WGM12_BIT);
	CLR_BIT(TCCR1B, WGM13_BIT);
	// input capture interrupt enable
	SET_BIT(TIMSk, 5);

	// Select prescalar (/8)
	CLR_BIT(TCCR1B, CS10_BIT);
	SET_BIT(TCCR1B, CS11_BIT);
	CLR_BIT(TCCR1B, CS12_BIT);
}

void TMR1_voidLoadCounterTop(u16 copy_u8CounterTop)
{
	ICR1 = copy_u8CounterTop;
}


void TMR1_voidLoadOCR1A(u16 copy_u8OCRValue)
{
	OCR1A = copy_u8OCRValue;
}


void TMR1_voidICedgeSelect(u8 edge)
{
	switch (edge)
	{
	case RISING:
		SET_BIT(TCCR1B, 6);
		break;

	case FALLING:
		CLR_BIT(TCCR1B, 6);
		break;
	}
}


u16 TMR1_voidGetICR1()
{
	return ICR1;
}

void(*TMR1_GPFun_OVF)(void) = '\0';

void TMR1_voidSetCallBack_OVF(void(*ptr))
{
	TMR1_GPFun_OVF = ptr;
}

void __vector_9()__attribute__((signal));
void __vector_9()
{
	if(TMR1_GPFun_OVF != '\0')
	{
		TMR1_GPFun_OVF();
	}
}


void(*TMR1_GPFun_CAPT)(void) = '\0';

void TMR1_voidSetCallBack_CAPT(void(*ptr))
{
	TMR1_GPFun_CAPT = ptr;
}

void __vector_6()__attribute__((signal));
void __vector_6()
{
	if(TMR1_GPFun_CAPT != '\0')
	{
		TMR1_GPFun_CAPT();
	}
}
