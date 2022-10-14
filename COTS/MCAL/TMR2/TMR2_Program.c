#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "TMR2_Private.h"
#include "TMR2_Config.h"
#include "TMR2_Interface.h"

void TMR2_voidInit()
{
#if MODE == NORMAL
	// Select mode
	CLR_BIT(TCCR2, WGM2_BIT0);
	CLR_BIT(TCCR2, WGM2_BIT1);

	// Interrupt
	SET_BIT(TIMSK, TOIE2_BIT);

#elif MODE == PHASE_CORRECT
	// Select mode
	SET_BIT(TCCR2, WGM2_BIT0);
	CLR_BIT(TCCR2, WGM2_BIT1);

	// non inverting
	CLR_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);


#elif MODE == CTC
	CLR_BIT(TCCR2, WGM2_BIT0);
	SET_BIT(TCCR2, WGM2_BIT1);
	// Interrupt
	SET_BIT(TIMSK, OCIE2_BIT);

	CLR_BIT(TCCR2, 4);
	CLR_BIT(TCCR2, 5);
	
#elif MODE == FAST_PWM
	// Select mode
	SET_BIT(TCCR2, WGM2_BIT0);
	SET_BIT(TCCR2, WGM2_BIT1);

	CLR_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);

#endif

	// Select prescalar (/8)
	TCCR2 = TCCR2 | PRESCALAR;
}


// Load counter value to TCNT2 register (start first count from this value instead of 0)
void TMR2_voidLoadCounter(u8 copy_u8CounterValue)
{
	TCNT2 = copy_u8CounterValue;
}


// Load output compare match value to OCR register (max count for CTC mode)
void TMR2_voidLoadOCR(u8 copy_u8CompareValue)
{
	OCR2 = copy_u8CompareValue;
}


u8 TMR2_u8GetCounter()
{
	return TCNT2;
}



void(*TMR2_GPFun_OVF)(void) = '\0';

void TMR2_voidSetCallBack_OVF(void(*ptr))
{
	TMR2_GPFun_OVF = ptr;
}

void __vector_5()__attribute__((signal));
void __vector_5()
{
	if(TMR2_GPFun_OVF != '\0')
	{
		TMR2_GPFun_OVF();
	}
}


void(*TMR2_GPFun_COMP)(void) = '\0';

void TMR2_voidSetCallBack_COMP(void(*ptr))
{
	TMR2_GPFun_COMP = ptr;
}

void __vector_4()__attribute__((signal));
void __vector_4()
{
	if(TMR2_GPFun_COMP != '\0')
	{
		TMR2_GPFun_COMP();
	}
}
