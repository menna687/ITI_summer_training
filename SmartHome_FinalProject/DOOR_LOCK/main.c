/*
 * main.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Menna
 */

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KYP_Interface.h"
#include "LCD_Interface.h"
#include "TMR1_Interface.h"
//#include "UART_Interface.h"
#include "avr/delay.h"

int main()
{
	u8 input, i=0, wrong = 0, warning = 0;
	u8 currentPass[] = "1567";

	// Initialization
	LCD_voidInit();
	KYP_voidInit();
	TMR1_voidInit();
	UART_voidInit();

	// Servo motor setup
	TMR1_voidLoadCounterTop(20000);
	DIO_voidSetPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT);

	// Warning LED
	//DIO_voidSetPinDirection(PORTA_ID, PIN5_ID, PIN_OUTPUT);

	LCD_voidDisplayString("Enter password");

	while(1)
	{
		/*warning = UART_u8ReceiveData();
		if(warning == '1')
		{
			DIO_voidSetPinValue(PORTA_ID, PIN5_ID, PIN_HIGH);
		}*/

		input = KYP_u8GetPressedKey();
		if(input != ALL_NOT_PRESSED)
		{
			/* Reset key is pressed
			 * Reset password characters counter and reset flag
			 * Reset warning LED
			 */
			if (input == 'c')
			{
				i = 0;
				wrong = 0;
				warning = 0;
				DIO_voidSetPinValue(PORTA_ID, PIN5_ID, PIN_LOW);
				continue;
			}

			/* Check the pressed input with the relative character in the reserved password
			 * Set the flag to 1 in case of wrong input
			 */
			if(input != currentPass[i])
			{
				wrong = 1;
			}
			i++;

			// Check the flag and display the output on the LCD
			if (i == 4)
			{
				LCD_voidClear();
				if (wrong == 0)
				{
					LCD_voidDisplayString("Welcome");
					TMR1_voidLoadOCR1A(1499);
					_delay_ms(2000);
					TMR1_voidLoadOCR1A(980);
					LCD_voidClear();
					LCD_voidDisplayString("Enter password");
				}

				else
				{
					LCD_voidDisplayString("Re-enter password");
				}

				// Reset variables to start a new loop (Ask for password again)
				i = 0;
				wrong = 0;
			}
		}
	}

	return 0;
}
