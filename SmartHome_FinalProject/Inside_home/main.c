/*
 * main.c
 *
 *  Created on: Sep 7, 2022
 *    SMART HOME PROJECT
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "TMR0_Interface.h"
#include "TMR1_Interface.h"
//#include "USART_Interface.h"
#include "avr/delay.h"

int main()
{
	u16 temp , LDR_OUT , LDR_room1 , LDR_room2 , LDR_room3;
	u16 factor , curtain , Room_light;


	ADC_voidInit();      //ADC Initialized
	LCD_voidInitialize();    //LCD Initialized

	EXT_voidGIE_Enable();

	DIO_voidSetPinDirection(portB , pin3 ,pin_output);
	TMR0_voidInit();     //Timer0 Initialized

	DIO_voidSetPinDirection(portD , pin5 ,pin_output);
	TMR1_voidInit();     //Timer1 Initialized

	//USART_voidInitial();
	/*warning led if there is fire*/
	DIO_voidSetPinDirection(portB , pin5 , pin_output);

	/*leds of 3 Rooms*/
	DIO_voidSetPinDirection(portD , pin3 ,pin_output);
	DIO_voidSetPinDirection(portD , pin7 ,pin_output);
	DIO_voidSetPinDirection(portD , pin6 ,pin_output);

	_delay_ms(500);

		while(1){
//_________________________controlling fan using temperature sensor______________________
			/*take analog value from temperature sensor , converting it into degree*/
			temp = ADC_voidStartConversion(ADC0 , factor64);
			temp = ( ((u32)temp*5000)/(u16)1023 ) / 10;         //degree

			/*display tempreture value over an LCD*/
			LCD_voidClear();
			LCD_voidString("Temp = ");
			LCD_voidNumbers(temp);
			LCD_voidString(" C");

			/*control motor of fan depending on the temperature*/
			if ((temp >= 20) && (temp <= 25))
			{
				TMR0_voidOCR0(127);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : half speed");
				DIO_voidSetPinValue(portB , pin5 , pin_low);
			}

			else if ((temp > 25) && (temp <= 30))
			{
				TMR0_voidOCR0(191);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : 75% speed");
				DIO_voidSetPinValue(portB , pin5 , pin_low);
			}

			else if ((temp > 30) && (temp <= 45))   //high temperature
			{
				TMR0_voidOCR0(255);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : full speed");
				DIO_voidSetPinValue(portB , pin5 , pin_low);
			}

			/*very high temperature (fire warning)*/
			else if(temp > 45)
			{
				TMR0_voidOCR0(0);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fire warning!!");
				DIO_voidSetPinValue(portB , pin5 , pin_high);  //red led ON
				//USART_voidSendData('1');
			}

			else
			{
				TMR0_voidOCR0(0);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan OFF");
				DIO_voidSetPinValue(portB , pin5 , pin_low);
			}

			_delay_ms(500);

//__________________controlling a servo motor of the curtain using an LDR___________________

			LDR_OUT = ADC_voidStartConversion(ADC1 , factor64);
			factor = ( (2300-800) / (1023-0) );
			curtain = (LDR_OUT*factor) + 800;
			/*Openning or Closing the curtain*/
			TMR1_voidOCR1A(curtain);
			_delay_ms(200);

//_____________controlling leds of 3 Rooms using 3 LDR (one in each room)__________________
			//___________________________ROOM_1___________________________
			/*take value of LDR of room1 , converting them into m_volt*/
			LDR_room1 = ADC_voidStartConversion(ADC2 , factor64);
			LDR_room1 = ((u32)LDR_room1*5000)/(u16)1023  ; //m-volt

			/*condition for led to turn it ON or OFF depending on readings of LDR of room1*/
			if (LDR_room1 < 2500)
			{
				DIO_voidSetPinValue(portD ,pin3 , pin_high);
			}
			else
			{
				DIO_voidSetPinValue(portD ,pin3 , pin_low);
			}
			//___________________________ROOM_2____________________________
			/*take value of LDR of room2 , converting them into m_volt*/
			LDR_room2 = ADC_voidStartConversion(ADC3 , factor64);
			LDR_room2 = ((u32)LDR_room2*5000)/(u16)1023  ; //m-volt

			/*condition for led to turn it ON or OFF depending on readings of LDR of room2*/
			if (LDR_room2 < 2500)
			{
				DIO_voidSetPinValue(portD ,pin7 , pin_high);
			}
			else
			{
				DIO_voidSetPinValue(portD ,pin7 , pin_low);
			}
			//___________________________ROOM_3____________________________
			/*take value of LDR of room3 , converting them into m_volt*/
			LDR_room3 = ADC_voidStartConversion(ADC4 , factor64);
			LDR_room3 = ((u32)LDR_room3*5000)/(u16)1023  ; //m-volt

			/*condition for led to turn it ON or OFF depending on readings of LDR of room3*/
			if (LDR_room3 < 2500)
			{
				DIO_voidSetPinValue(portD ,pin6 , pin_high);
			}
			else
			{
				DIO_voidSetPinValue(portD ,pin6 , pin_low);
			}

		}


	return 0;
}

