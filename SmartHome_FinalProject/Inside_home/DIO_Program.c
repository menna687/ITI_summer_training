#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

                                      /*Functions Implementation*/
//____________________________________________Pin direction________________________________________________				   
void DIO_voidSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection)
{
	        /*Output Mode*/
	if(Copy_u8PinDirection == 1)     
	{
		switch(Copy_u8PortID)
		{
			case portA :
			SetBit(DDRA_REG , Copy_u8PinID);
			break;
			
			case portB :
			SetBit(DDRB_REG , Copy_u8PinID);
			break;
			
			case portC :
			SetBit(DDRC_REG , Copy_u8PinID);
			break;
			
			case portD :
			SetBit(DDRD_REG , Copy_u8PinID);
			break;
		}
	}
	        /*Input Mode*/
	else if (Copy_u8PinDirection == 0)
	{
		switch(Copy_u8PortID)
		{
			case portA :
			ClrBit(DDRA_REG , Copy_u8PinID);
			break;
			
			case portB :
			ClrBit(DDRB_REG , Copy_u8PinID);
			break;
			
			case portC :
			ClrBit(DDRC_REG , Copy_u8PinID);
			break;
			
			case portD :
			ClrBit(DDRD_REG , Copy_u8PinID);
			break;
		}
	}
}

//______________________________________Pin value________________________________________
// After determining pin direction , we need to determine if value high or low
void DIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue)
{
	        /*Output is high*/
	if(Copy_u8PinValue == 1)     
	{
		switch(Copy_u8PortID)
		{
			case portA :
			SetBit(PORTA_REG , Copy_u8PinID);
			break;
			
			case portB :
			SetBit(PORTB_REG , Copy_u8PinID);
			break;
			
			case portC :
			SetBit(PORTC_REG , Copy_u8PinID);
			break;
			
			case portD :
			SetBit(PORTD_REG , Copy_u8PinID);
			break;
		}
	}
	        /*Output is low*/
	else if (Copy_u8PinValue == 0)
	{
		switch(Copy_u8PortID)
		{
			case portA :
			ClrBit(PORTA_REG , Copy_u8PinID);
			break;
			
			case portB :
			ClrBit(PORTB_REG , Copy_u8PinID);
			break;
			
			case portC :
			ClrBit(PORTC_REG , Copy_u8PinID);
			break;
			
			case portD :
			ClrBit(PORTD_REG , Copy_u8PinID);
			break;
		}
	}
}

//_____________________________________________Port direction__________________________________
void DIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortDirection)
{
	      /*Input or Output Mode*/
	switch(Copy_u8PortID)
	{
		case portA :
		DDRA_REG = Copy_u8PortDirection;
		break;
		
		case portB :
		DDRB_REG = Copy_u8PortDirection;
		break;
		
		case portC :
		DDRC_REG = Copy_u8PortDirection;
		break;
		
		case portD :
		DDRD_REG = Copy_u8PortDirection;
		break;
	}
}

//_______________________________________________Port Value_________________________________________
void DIO_voidSetPortValue(u8 Copy_u8PortID , u8 Copy_u8PortValue)
{
	      /*Output port high or low*/
	switch(Copy_u8PortID)
	{
		case portA :
		PORTA_REG = Copy_u8PortValue;
		break;
		
		case portB :
		PORTB_REG = Copy_u8PortValue;
		break;
		
		case portC :
		PORTC_REG = Copy_u8PortValue;
		break;
		
		case portD :
		PORTD_REG = Copy_u8PortValue;
		break;
	}
}

//________________________________________________Toggle Pin_____________________________________
void DIO_voidTogglePinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	switch(Copy_u8PortID)
	{
		case portA :
		ToggleBit(PORTA_REG , Copy_u8PinID);
		break;
		
		case portB :
		ToggleBit(PORTB_REG , Copy_u8PinID);
		break;
		
		case portC :
		ToggleBit(PORTC_REG , Copy_u8PinID);
		break;
		
		case portD :
		ToggleBit(PORTD_REG , Copy_u8PinID);
		break;
	}
}

//_______________________________________________Get pin________________________________________
u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	u8 Copy_u8PinValue;
	switch(Copy_u8PortID)
	{
		case portA :
		Copy_u8PinValue = GetBit(PINA_REG , Copy_u8PinID);
		break;
		
		case portB :
		Copy_u8PinValue = GetBit(PINB_REG , Copy_u8PinID);
		break;
		
		case portC :
		Copy_u8PinValue = GetBit(PINC_REG , Copy_u8PinID);
		break;
		
		case portD :
		Copy_u8PinValue = GetBit(PIND_REG , Copy_u8PinID);
		break;
	}
	return Copy_u8PinValue;
}





