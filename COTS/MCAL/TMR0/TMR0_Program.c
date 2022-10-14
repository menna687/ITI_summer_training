#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "TMR0_Private.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"

void TMR0_voidInit()
{
#if MODE == NORMAL
	// Select mode
	CLR_BIT(TCCR0, WGM0_BIT0);
	CLR_BIT(TCCR0, WGM0_BIT1);

	// Timer overflow interrupt enable
	SET_BIT(TIMSK, TOIE0_BIT);

#elif MODE == PHASE_CORRECT
	// Select mode
	SET_BIT(TCCR0, WGM0_BIT0);
	CLR_BIT(TCCR0, WGM0_BIT1);

	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);

#elif MODE == CTC
	// Select mode
	CLR_BIT(TCCR0, WGM0_BIT0);
	SET_BIT(TCCR0, WGM0_BIT1);
	// Output compare match interrupt enable
	SET_BIT(TIMSK, OCIE0_BIT);

	// non inverting
	CLR_BIT(TCCR0, 4);      // need to be checked
	CLR_BIT(TCCR0, 5);

#elif MODE == FAST_PWM
	// Select mode
	SET_BIT(TCCR0, WGM0_BIT0);
	SET_BIT(TCCR0, WGM0_BIT1);

	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
#endif
	
	// Select prescalar (selected in config)
	TCCR0 = TCCR0 | PRESCALAR;
}


// Load counter value to TCNT0 register (start first count from this value instead of 0)
void TMR0_voidLoadCounter(u8 copy_u8CounterValue)
{
	TCNT0 = copy_u8CounterValue;
}


// Load output compare match value to OCR register (max count for CTC mode)
void TMR0_voidLoadOCR(u8 copy_u8CompareValue)
{
	OCR0 = copy_u8CompareValue;
}


u8 TMR0_u8GetCounter()
{
	return TCNT0;
}


void(*TMR0_GPFun_OVF)(void) = '\0';
void TMR0_voidSetCallBack_OVF(void(*ptr))
{
	TMR0_GPFun_OVF = ptr;
}

void __vector_11()__attribute__((signal));
void __vector_11()
{
	if(TMR0_GPFun_OVF != '\0')
	{
		TMR0_GPFun_OVF();
	}
}


void(*TMR0_GPFun_COMP)(void) = '\0';
void TMR0_voidSetCallBack_COMP(void(*ptr))
{
	TMR0_GPFun_COMP = ptr;
}

void __vector_10()__attribute__((signal));
void __vector_10()
{
	if(TMR0_GPFun_COMP != '\0')
	{
		TMR0_GPFun_COMP();
	}
}
