#include "STD_TYPES.h"
#include "BitMath.h"
#include "TMR0_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"

void (*GlobalPtr)(void) = '\0';

void TMR0_SetCallBack(void (*Ptr)(void))
{
	GlobalPtr = Ptr;
}

void TMR0_voidInit(void)
{
	/**********************************TMR0 Prescaler******************************/
#if TMR0_Prescaler == TMR0_NO_Prescaler
	SetBit(TCCR0 , CS00);
	ClrBit(TCCR0 , CS01);
	ClrBit(TCCR0 , CS02);
#elif TMR0_Prescaler == TMR0_Prescaler_8
	ClrBit(TCCR0 , CS00);
	SetBit(TCCR0 , CS01);
	ClrBit(TCCR0 , CS02);
#elif TMR0_Prescaler == TMR0_Prescaler_64
	SetBit(TCCR0 , CS00);
	SetBit(TCCR0 , CS01);
	ClrBit(TCCR0 , CS02);
#elif TMR0_Prescaler == TMR0_Prescaler_256
	ClrBit(TCCR0 , CS00);
	ClrBit(TCCR0 , CS01);
	SetBit(TCCR0 , CS02);
#elif TMR0_Prescaler == TMR0_Prescaler_1024
	SetBit(TCCR0 , CS00);
	ClrBit(TCCR0 , CS01);
	SetBit(TCCR0 , CS02);
#endif

/******************************************TMR0 Modes*********************************/
#if TMR0_Mode == Normal
	ClrBit(TCCR0 , WGM01);
	ClrBit(TCCR0 , WGM00);
	/*overflow interrupt enable*/
	SetBit(TIMSK , TOIE0);
#elif TMR0_Mode == PhaseCorrectPWM
	ClrBit(TCCR0 , WGM01);
	SetBit(TCCR0 , WGM00);
	/*************OC0 Compare match*********/
	ClrBit(TCCR0 , COM00);
	SetBit(TCCR0 , COM01);
#elif TMR0_Mode == CTC
	SetBit(TCCR0 , WGM01);
	ClrBit(TCCR0 , WGM00);
	/*************OC0 Compare match*********/
	SetBit(TCCR0 , COM00);
	ClrBit(TCCR0 , COM01);
	/*Output Compare Match Interrupt Enable*/
	SetBit(TIMSK , OCIE0);
#elif TMR0_Mode == FastPWM
	SetBit(TCCR0 , WGM01);
	SetBit(TCCR0 , WGM00);
	/*************OC0 Compare match*********/
	ClrBit(TCCR0 , COM00);
	SetBit(TCCR0 , COM01);
#endif

}

void TMR0_voidOCR0(u16 Copy_u16OCR0Value)
{
	OCR0 = Copy_u16OCR0Value;
}


void TMR0_voidPreload(u16 Copy_u16Value)
{
	TCNT0 = Copy_u16Value;
}


void __vector_11()__attribute__((signal));
void __vector_11()
{
	static u16 count = 0;
	if (count == 3907)
	{
		if(GlobalPtr != '\0')
		{
		    GlobalPtr();
		    count = 0;
		}
	}
	else
	{
		count ++;
	}

}

void __vector_10()__attribute__((signal));
void __vector_10()
{
	static u16 count = 0;
	if (count == 4000)
	{
		if(GlobalPtr != '\0')
		{
		    GlobalPtr();
		    count = 0;
		}
	}
	else
	{
		count ++;
	}
}

