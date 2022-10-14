#ifndef _LCD_INTERFACE_H            //header file guard
#define _LCD_INTERFACE_H

                        /*Functions Prototypes*/
void LCD_voidInitialize(void);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidGoToXY(u8 Copy_u8Digits , u8 Copy_u8Line);
void LCD_voidString(u8 * Copy_u8Data);
void LCD_voidNumbers(u32 Copy_u32Number);
void LCD_voidWriteSpecialCharacter(u8 *pattern , u8 Copy_u8Character , u8 Col , u8 Row);
void LCD_voidClear(void);


#endif
