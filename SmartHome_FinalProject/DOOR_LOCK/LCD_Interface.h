#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define CMD_CLEAR    (0x01)


          /*** Functions prototypes ***/
void LCD_voidInit(void);
void LCD_voidSendCMD(u8 Copy_u8CMD);
void LCD_voidDisplayData(u8 Copy_u8Data);
void LCD_voidGoToRowCol(u8 Copy_u8Row, u8 Copy_u8Col);

void LCD_voidDisplayString(u8 Copy_u8String[]);
void LCD_voidDisplayDigits(u32 Copy_u32Num);

void LCD_voidDisplaySpecialChar(u8 Ptr_u8Pattern[],u8 Copy_u8PatternNum);
void LCD_voidClear();

#endif
