#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "7SEG_Interface.h"

void _7SegDisplay(u8 Copy_u8PortID, u8 Copy_u8Num, u8 Copy_u8Connection)
{
	u8 decoder[10] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001,
			            0b00010010, 0b00000010, 0b01111000, 0b00000000, 0b00010000};
	DIO_voidSetPortDirection(Copy_u8PortID, ALL_PORT_OUTPUT);
	
	if(Copy_u8Connection == COMMON_CATHODE)
	{
		DIO_voidSetPortValue(PortID, decoder[num]);
	}
	else if(Copy_u8Connection == COMMON_ANODE)
	{
		DIO_voidSetPortValue(Copy_u8PortID, ~decoder[num]);
	}
}