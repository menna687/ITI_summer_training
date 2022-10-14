#ifndef TMR1_INTERFACE_H
#define TMR1_INTERFACE_H

#define COM1A1_BIT  7
#define COM1A0_BIT  6
#define COM1B1_BIT  5
#define COM1B0_BIT  4

#define WGM13_BIT   4
#define WGM12_BIT   3
#define WGM11_BIT   1
#define WGM10_BIT   0

#define CS10_BIT    0
#define CS11_BIT    1
#define CS12_BIT    2

// Prescalar factors
#define NO_clk    (0x00)
#define clk       (0x01)
#define clk_8     (0x02)
#define clk_64    (0x03)
#define clk_256   (0x04)
#define clk_1024  (0x05)
#define EXT_FALLING_EDGE (0x06)
#define EXT_RISING_EDGE	 (0x07)

#define FAST_PWM       2
#define PHASE_CORRECT  3

#define RISING   1
#define FALLING  2

void TMR1_voidInit();
void TMR1_voidInitICU();

void TMR1_voidLoadCounterTop(u16 copy_u8CounterTop);
void TMR1_voidLoadOCR1A(u16 copy_u8OCRValue);

void TMR1_voidICedgeSelect(u8 edge);
u16  TMR1_voidGetICR1();

void TMR1_voidSetCallBack_OVF(void(*ptr));
void TMR1_voidSetCallBack_CAPT(void(*ptr));

#endif
