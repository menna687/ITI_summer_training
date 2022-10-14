#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_interface.h"


                 /**************    Functions    ***************/
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir)
{
	if(Copy_u8PinDir == PIN_OUTPUT)      
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID: SET_BIT(DDRA_REG, Copy_u8PinID); break;
			case PORTB_ID: SET_BIT(DDRB_REG, Copy_u8PinID); break;
			case PORTC_ID: SET_BIT(DDRC_REG, Copy_u8PinID); break;
			case PORTD_ID: SET_BIT(DDRD_REG, Copy_u8PinID); break;
		}
	}
	
	else if(Copy_u8PinDir == PIN_INPUT)     
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID: CLR_BIT(DDRA_REG, Copy_u8PinID); break;
			case PORTB_ID: CLR_BIT(DDRB_REG, Copy_u8PinID); break;
			case PORTC_ID: CLR_BIT(DDRC_REG, Copy_u8PinID); break;
			case PORTD_ID: CLR_BIT(DDRD_REG, Copy_u8PinID); break;
		}
	}
}


void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
	if(Copy_u8PinValue == PIN_HIGH)      
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID: SET_BIT(PORTA_REG, Copy_u8PinID); break;
			case PORTB_ID: SET_BIT(PORTB_REG, Copy_u8PinID); break;
			case PORTC_ID: SET_BIT(PORTC_REG, Copy_u8PinID); break;
			case PORTD_ID: SET_BIT(PORTD_REG, Copy_u8PinID); break;
		}
	}
	
	else if(Copy_u8PinValue == PIN_LOW)     
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID: CLR_BIT(PORTA_REG, Copy_u8PinID); break;
			case PORTB_ID: CLR_BIT(PORTB_REG, Copy_u8PinID); break;
			case PORTC_ID: CLR_BIT(PORTC_REG, Copy_u8PinID); break;
			case PORTD_ID: CLR_BIT(PORTD_REG, Copy_u8PinID); break;
		}
	}
}


void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir)
{
	switch(Copy_u8PortID)
	{
		case PORTA_ID: DDRA_REG = Copy_u8PortDir; break;
		case PORTB_ID: DDRB_REG = Copy_u8PortDir; break;
		case PORTC_ID: DDRC_REG = Copy_u8PortDir; break;
		case PORTD_ID: DDRD_REG = Copy_u8PortDir; break;
	}
}


void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortID)
	{
		case PORTA_ID: PORTA_REG = Copy_u8PortValue; break;
		case PORTB_ID: PORTB_REG = Copy_u8PortValue; break;
		case PORTC_ID: PORTC_REG = Copy_u8PortValue; break;
		case PORTD_ID: PORTD_REG = Copy_u8PortValue; break;
	}
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 LOC_val;
	switch(Copy_u8PortID)
	{
		case PORTA_ID: LOC_val = GET_BIT(PINA_REG, Copy_u8PinID); break;
		case PORTB_ID: LOC_val = GET_BIT(PINB_REG, Copy_u8PinID); break;
		case PORTC_ID: LOC_val = GET_BIT(PINC_REG, Copy_u8PinID); break;
		case PORTD_ID: LOC_val = GET_BIT(PIND_REG, Copy_u8PinID); break;
	}
	return LOC_val;
}


void DIO_voidTogglePinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	switch(Copy_u8PortID)
	{
		case PORTA_ID: TOGGLE_BIT(PORTA_REG, Copy_u8PinID); break;
		case PORTB_ID: TOGGLE_BIT(PORTB_REG, Copy_u8PinID); break;
		case PORTC_ID: TOGGLE_BIT(PORTC_REG, Copy_u8PinID); break;
		case PORTD_ID: TOGGLE_BIT(PORTD_REG, Copy_u8PinID); break;
	}
}
