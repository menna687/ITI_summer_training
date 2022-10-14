#include "STD_TYPES.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"

void LCD_voidSendCMD(u8 Copy_u8CMD)   // can be static function (not used outside this file)
{	
	DIO_voidSetPinValue(LCD_PORT_CONTROL, RS_PIN, PIN_LOW);   // RS = 0
	DIO_voidSetPinValue(LCD_PORT_CONTROL, RW_PIN, PIN_LOW);   // RW = 0
	
	DIO_voidSetPortValue(LCD_PORT_DATA, Copy_u8CMD);    // Write command to port B
	
	// Enable pulse high for 2 sec
	DIO_voidSetPinValue(LCD_PORT_CONTROL, EN_PIN, PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, EN_PIN, PIN_LOW);
}


void LCD_voidDisplayData(u8 Copy_u8Data)
{	
	DIO_voidSetPinValue(LCD_PORT_CONTROL, RS_PIN, PIN_HIGH);    // RS = 0
	DIO_voidSetPinValue(LCD_PORT_CONTROL, RW_PIN, PIN_LOW);     // RW = 1
	
	DIO_voidSetPortValue(LCD_PORT_DATA, Copy_u8Data);           // Write data to port B
	
	// Enable pulse
	DIO_voidSetPinValue(LCD_PORT_CONTROL, EN_PIN, PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, EN_PIN, PIN_LOW);
}


void LCD_voidInit(void)
{
	// Set RS, RW, EN directions
	DIO_voidSetPinDirection(LCD_PORT_CONTROL, RS_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_PORT_CONTROL, RW_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_PORT_CONTROL, EN_PIN, PIN_OUTPUT);

	// Set data pins directions
	DIO_voidSetPortDirection(LCD_PORT_DATA, ALL_PORT_OUTPUT);
	_delay_ms(30);

	// Function set
	LCD_voidSendCMD(0b00111000);
	_delay_ms(2);

	// Display ON/OFF control
	LCD_voidSendCMD(0b00001100);
	_delay_ms(2);

	// clear
	LCD_voidSendCMD(CMD_CLEAR);
}


// Start from specific location
void LCD_voidGoToRowCol(u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 LOC_Default = 0x80;
	if(Copy_u8Row == 0)
	{
		LOC_Default = LOC_Default + Copy_u8Col;
	}

	else if(Copy_u8Row == 1)
	{
		LOC_Default = LOC_Default + 0x40 + Copy_u8Col;
	}
	LCD_voidSendCMD(LOC_Default);
}



// print string as separated characters
void LCD_voidDisplayString(u8 Copy_u8String[])
{
	u8 i = 0;
	while(Copy_u8String[i] != '\0' && i<16)
	{
		LCD_voidDisplayData(Copy_u8String[i]);
		i++;
	}

	// print in other row in case of overflow
	if(i>=16)
	{
		LCD_voidGoToRowCol(1, 0);
		while(Copy_u8String[i] != '\0')
		{
			LCD_voidDisplayData(Copy_u8String[i]);
			i++;
		}
	}
}



// split number into separate digits then display these digits
void LCD_voidDisplayDigits(u32 Copy_u32Num)
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
		LCD_voidDisplayData(arr[c] + 48);
	}
}



// input: pattern array from main, pattern num
void LCD_voidDisplaySpecialChar(u8 Ptr_u8Pattern[],u8 Copy_u8PatternNum)
{
	u8 Loc_CGRAM = 64 + Copy_u8PatternNum*8;
	LCD_voidSendCMD(Loc_CGRAM);

	for(u8 i = 0; i < 8 ;i++)
	{
		LCD_voidDisplayData(Ptr_u8Pattern[i]);
	}
	LCD_voidDisplayData(Copy_u8PatternNum);
}


void LCD_voidClear()
{
	LCD_voidSendCMD(CMD_CLEAR);
}
