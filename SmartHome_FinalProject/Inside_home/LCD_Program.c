#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "util/delay.h"

//___________________________________________initialize LCD____________________________________
void LCD_voidInitialize(void)
{
	 /*set pin direction (called only one time)*/
	DIO_voidSetPinDirection(RS_Write_EN_port , RS , pin_output);     //RS
	DIO_voidSetPinDirection(RS_Write_EN_port , Write , pin_output);     //R/W
	DIO_voidSetPinDirection(RS_Write_EN_port , EN , pin_output);     //Enable
	          /*set port direction*/
	DIO_voidSetPortDirection(LCD_port , All_port_output);
	
	_delay_ms(30);
    LCD_voidWriteCommand(FunctionSet);     //send command function set
	_delay_ms(2);
	LCD_voidWriteCommand(Display_ON_OFF);     //send command display on/off
	_delay_ms(2);
	LCD_voidWriteCommand(CLR_Display);     //send command clear display
}
//___________________________________________write command____________________________________-
void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/*RS = 0*/
	DIO_voidSetPinValue(RS_Write_EN_port , RS , pin_low);
	/*R/W = 0*/
	DIO_voidSetPinValue(RS_Write_EN_port , Write , pin_low);
	/*send command*/
	DIO_voidSetPortValue(LCD_port , Copy_u8Command);
	/*Enable pulse*/
	DIO_voidSetPinValue(RS_Write_EN_port , EN , pin_high);
	_delay_ms(2);
	DIO_voidSetPinValue(RS_Write_EN_port , EN , pin_low);
}

//____________________________________________write data______________________________________
void LCD_voidWriteData(u8 Copy_u8Data)
{
	/*RS = 1*/
	DIO_voidSetPinValue(RS_Write_EN_port , RS , pin_high);
	/*R/W = 0*/
	DIO_voidSetPinValue(RS_Write_EN_port , Write , pin_low);
	/*send data*/
	DIO_voidSetPortValue(LCD_port , Copy_u8Data);
	/*Enable pulse*/
	DIO_voidSetPinValue(RS_Write_EN_port , EN , pin_high);
	_delay_ms(2);
	DIO_voidSetPinValue(RS_Write_EN_port , EN , pin_low);
}
//__________________________________________specify position___________________________________
void LCD_voidGoToXY(u8 Copy_u8Digits , u8 Copy_u8Line)
{
	if (Copy_u8Line == 1)
	{
		LCD_voidWriteCommand( DDRAM_Address + Copy_u8Digits );
	}

	else if(Copy_u8Line == 2)
	{
		LCD_voidWriteCommand( DDRAM_Address + LineOne + Copy_u8Digits );
	}
}
//____________________________________________display string____________________________________
void LCD_voidString(u8 * Copy_u8Data)
{
	while( (*Copy_u8Data) != '\0' )
	{
		LCD_voidWriteData(*Copy_u8Data);
		Copy_u8Data++;
	}
}
//____________________________________________display numbers_________________________________
void LCD_voidNumbers(u32 Copy_u32Number)
{
		u8 arr[15];
		u8 digits = 0;
		while(Copy_u32Number != 0)
		{
			arr[digits] = (Copy_u32Number % 10) + ZeroASCIICode ;
			Copy_u32Number /= 10 ;
			digits++;
		}
		for(s8 j=digits-1 ; j>=0 ; j--)
		{
			LCD_voidWriteData(arr[j]);
		}
}
//_____________________________________________write special character_________________________
void LCD_voidWriteSpecialCharacter(u8 *pattern , u8 Copy_u8Character , u8 Col , u8 Row)
{
	LCD_voidWriteCommand(64 + (Copy_u8Character*8));     //CGRAM_Address
	for(u8 i=0 ; i<8 ; i++)
	{
		LCD_voidWriteData(pattern[i]);
	}
	LCD_voidGoToXY(Col , Row);
	LCD_voidWriteData(Copy_u8Character);
}

//_______________________________________________Clear LCD_____________________________________
void LCD_voidClear(void)
{
	LCD_voidWriteCommand(CLR_Display);
}

