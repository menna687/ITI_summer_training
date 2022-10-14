#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#define FunctionSet        (0b00111000)
#define Display_ON_OFF     (0b00001100)
#define CLR_Display        (0b00000001)

#define RS_Write_EN_port     portB
#define LCD_port             portC

#define RS       pin0
#define Write    pin1     //R\W
#define EN       pin2

#define DDRAM_Address      (0x80)
#define LineOne            (0x40)

#define ZeroASCIICode       48


#endif
