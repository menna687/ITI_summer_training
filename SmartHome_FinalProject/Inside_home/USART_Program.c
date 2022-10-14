#include "STD_TYPES.h"
#include "BitMath.h"
#include "USART_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "USART_Config.h"
#include "USART_Interface.h"
//#include "avr/delay.h"

void USART_voidInitial(void)
{
	SetBit(UCSRB , TXEN);
	SetBit(UCSRB , RXEN);

	UCSRC = Temp;
	UBRRL = 51;
}

void USART_voidSendData(u16 Copy_u16Data)
{
	while(GetBit(UCSRA , UDRE) == 0);
	UDR = Copy_u16Data;
	//while(GetBit(UCSRA , TXC) == 0);
}

u16 USART_u16RecieveData(void)
{
	while(GetBit(UCSRA , RXC) == 0);
	return UDR;
}

void USART_voidSendString(u8 *Copy_u8String)
{
	while( (*Copy_u8String) != '\0' )
		{
		    USART_voidSendData(*Copy_u8String);
		   // while(GetBit(UCSRA , TXC) == 0);
			Copy_u8String++;
		}
}

void USART_voidSendNumbers(u8 Copy_u8Number)
{
		u8 arr[15];
		u8 digits = 0;
		while(Copy_u8Number != 0)
		{
			arr[digits] = (Copy_u8Number % 10) + ZeroASCIICode ;
			Copy_u8Number /= 10 ;
			digits++;
		}
		for(s8 j=digits-1 ; j>=0 ; j--)
		{
			USART_voidSendData(arr[j]);
		}
}
