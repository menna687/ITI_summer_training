#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KYP_Interface.h"
#include "KYP_Config.h"
#include "avr/delay.h"

void KYP_voidInit(void)
{
	DIO_voidSetPortDirection(KYP_PORT, IN_PIN4_TO_7);
	DIO_voidSetPortValue(KYP_PORT, ALL_PORT_OUTPUT);         // inputs are pullup
}


u8 KYP_u8GetPressedKey(void)
{
	u8 LOC_SWs[KYP_ROWS][KYP_COLS] = {{'7', '8', '9', '/'},
									  {'4', '5', '6', '*'},
									  {'1', '2', '3', '-'},
									  {'c', '0', '=', '+'}};

	u8 LOC_PressedSwitch = ALL_NOT_PRESSED ;  // initial value out of range
	u8 LOC_CheckPress = SWITCH_NOT_PRESSED;
	u8 LOC_ROW, LOC_COL;
	
	for(LOC_COL = COL_START; LOC_COL<=COL_END; LOC_COL++)
	{
		// Activate current column
		DIO_voidSetPinValue(KYP_PORT, LOC_COL, PIN_LOW);

		for(LOC_ROW = ROW_START; LOC_ROW<=ROW_END; LOC_ROW++)
		{
			LOC_CheckPress = DIO_u8GetPinValue(KYP_PORT, LOC_ROW);

			if(LOC_CheckPress == SWITCH_PRESSED)
			{
				LOC_PressedSwitch = LOC_SWs[LOC_ROW - ROW_START][LOC_COL - COL_START];
				while(LOC_CheckPress == SWITCH_PRESSED)
				{
					LOC_CheckPress = DIO_u8GetPinValue(KYP_PORT, LOC_ROW);
				}
				_delay_ms(50);
				return LOC_PressedSwitch;
			}
		}

		// Deactivate current column
		DIO_voidSetPinValue(KYP_PORT, LOC_COL, PIN_HIGH);
	}
	return LOC_PressedSwitch;
}
