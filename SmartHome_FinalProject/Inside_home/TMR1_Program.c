#include "STD_TYPES.h"
#include "BitMath.h"
#include "TMR1_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "TMR1_Config.h"
#include "TMR1_Interface.h"

void (*TMR1_GlobalPtr)(void) = '\0';

void TMR1_SetCallBack(void (*Ptr)(void))
{
	TMR1_GlobalPtr = Ptr;
}

void TMR1_voidInit(void)
{
	/**********************************TMR1 Prescaler******************************/
#if TMR1_Prescaler == TMR1_NO_Prescaler
	SetBit(TCCR1B , CS10);
	ClrBit(TCCR1B , CS11);
	ClrBit(TCCR1B , CS12);
#elif TMR1_Prescaler == TMR1_Prescaler_8
	ClrBit(TCCR1B , CS10);
	SetBit(TCCR1B , CS11);
	ClrBit(TCCR1B , CS12);
#elif TMR1_Prescaler == TMR1_Prescaler_64
	SetBit(TCCR1B , CS10);
	SetBit(TCCR1B , CS11);
	ClrBit(TCCR1B , CS12);
#elif TMR1_Prescaler == TMR1_Prescaler_256
	ClrBit(TCCR1B , CS10);
	ClrBit(TCCR1B , CS11);
	SetBit(TCCR1B , CS12);
#elif TMR1_Prescaler == TMR1_Prescaler_1024
	SetBit(TCCR1B , CS10);
	ClrBit(TCCR1B , CS11);
	SetBit(TCCR1B , CS12);
#endif

/************************************compare match******************************/
#if TMR1_CompareOutputMode == OC1A_OC1B_disconnected
	ClrBit(TCCR1A , COM1B0);
	ClrBit(TCCR1A , COM1A0);
	ClrBit(TCCR1A , COM1B1);
	ClrBit(TCCR1A , COM1A1);
#elif TMR1_CompareOutputMode == Toggle_OC1A_OC1B
	SetBit(TCCR1A , COM1B0);
    SetBit(TCCR1A , COM1A0);
	ClrBit(TCCR1A , COM1B1);
	ClrBit(TCCR1A , COM1A1);
#elif TMR1_CompareOutputMode == Clear_OC1A_OC1B
	ClrBit(TCCR1A , COM1B0);
    ClrBit(TCCR1A , COM1A0);
	SetBit(TCCR1A , COM1B1);
	SetBit(TCCR1A , COM1A1);
#elif TMR1_CompareOutputMode == Set_OC1A_OC1B
	SetBit(TCCR1A , COM1B0);
    SetBit(TCCR1A , COM1A0);
	SetBit(TCCR1A , COM1B1);
	SetBit(TCCR1A , COM1A1);
#endif
/******************************************TMR1 Modes*********************************/
#if TMR1_Mode == Normal
	ClrBit(TCCR1A , WGM10);
	ClrBit(TCCR1A , WGM11);
	ClrBit(TCCR1B , WGM12);
	ClrBit(TCCR1B , WGM13);
	/*overflow interrupt enable*/
	//SetBit(TIMSK , TOIE1);
	/*capture event*/
	SetBit(TIMSK , TICIE1);
#elif TMR1_Mode == PhaseCorrectPWM
	ClrBit(TCCR1A , WGM10);
	SetBit(TCCR1A , WGM11);
	ClrBit(TCCR1B , WGM12);
	SetBit(TCCR1B , WGM13);
	ICR1 = 20000;   //for servo
#elif TMR1_Mode == CTC
	ClrBit(TCCR1A , WGM10);
	ClrBit(TCCR1A , WGM11);
	SetBit(TCCR1B , WGM12);
	SetBit(TCCR1B , WGM13);
	/*Output Compare Match Interrupt Enable*/
	SetBit(TIMSK , OCIE1A);
	//SetBit(TIMSK , OCIE1B);
#elif TMR1_Mode == FastPWM
	ClrBit(TCCR1A , WGM10);
	SetBit(TCCR1A , WGM11);
	SetBit(TCCR1B , WGM12);
	SetBit(TCCR1B , WGM13);
	ICR1 = 20000;     //for servo
#endif

}

void TMR1_voidOCR1A(u16 Copy_u16OCR1AValue)
{
	OCR1A = Copy_u16OCR1AValue;
}

void TMR1_voidPreload(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

u16 TMR1_u16ICR1(void)
{
	return ICR1;
}

void TMR1_voidICU_EdgeSelect(u16 Copy_u16EdgeSelect)
{
	switch(Copy_u16EdgeSelect)
	{
	case RisingEdge :
		SetBit(TCCR1B , ICES1);
		break;
	case FallingEdge :
		ClrBit(TCCR1B , ICES1);
	}
}
void __vector_9()__attribute__((signal));     //overflow
void __vector_9()
{
	if(TMR1_GlobalPtr != '\0')
	{
		TMR1_GlobalPtr();
	}
}

void __vector_7()__attribute__((signal));      //compare
void __vector_7()
{
	if(TMR1_GlobalPtr != '\0')
	{
		TMR1_GlobalPtr();
	}
}

void __vector_6()__attribute__((signal));     //capture event
void __vector_6()
{
	if(TMR1_GlobalPtr != '\0')
	{
		TMR1_GlobalPtr();
	}
}


