#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"

void UART_voidInit()
{
	SET_BIT(UCSRB, 3);    // Transmitter enable
	SET_BIT(UCSRB, 4);    // Receiver enable
	
	u8 LOC_UCSRC_Val;

	SET_BIT(LOC_UCSRC_Val, 7);  // Register select
	CLR_BIT(LOC_UCSRC_Val, 6);  // Asynchronous

	// Parity disable
	CLR_BIT(LOC_UCSRC_Val, 5);
	CLR_BIT(LOC_UCSRC_Val, 4);

	// Stop bit (1 bit)
	CLR_BIT(LOC_UCSRC_Val, 3);

	// Character size (8)
	SET_BIT(LOC_UCSRC_Val, 2);
	SET_BIT(LOC_UCSRC_Val, 1);
	
	UCSRC = LOC_UCSRC_Val;
	UBRRL = 51;
}


void UART_voidSendData(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;
	while(!GET_BIT(UCSRA, 6));
	SET_BIT(UCSRA, 6);   // Clear flag
}


void UART_voidSendString(u8 Copy_u8String[])
{
	u8 i = 0;
	while(Copy_u8String[i] != '\0')
	{
		UART_voidSendData(Copy_u8String[i]);
		i++;
	}
}


void UART_voidSendDigits(u32 Copy_u32Num)
{
	u8 size=0, i, c;
	u8 arr[10];
	u32 temp = Copy_u32Num;
	while(temp)
	{
		size++;
		temp /= 10;
	}

	i = size-1;
	while(Copy_u32Num)
	{
		arr[i] = Copy_u32Num % 10;
		Copy_u32Num /= 10;
		i--;
	}

	for(c = 0; c < size; c++)
	{
		UART_voidSendData(arr[c] + 48);
	}
}

u8 UART_u8ReceiveData()
{
	if(GET_BIT(UCSRA, 7))
	{
		CLR_BIT(UCSRA, 7);
		return UDR;
	}
}
