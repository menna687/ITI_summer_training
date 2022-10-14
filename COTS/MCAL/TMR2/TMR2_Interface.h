#ifndef TMR2_INTERFACE_H
#define TMR2_INTERFACE_H

// Wave generation mode bits
#define WGM2_BIT0   6
#define WGM2_BIT1   3

// Clock source bits (prescalar)
#define NO_clk    (0x00)
#define clk       (0x01)
#define clk_8     (0x02)
#define clk_64    (0x03)
#define clk_256   (0x04)
#define clk_1024  (0x05)
#define EXT_FALLING_EDGE (0x06)
#define EXT_RISING_EDGE	 (0x07)

// Overflow interrupt enable bits
#define TOIE2_BIT   6
#define OCIE2_BIT   7

// Modes
#define NORMAL        0
#define CTC           1
#define FAST_PWM      2
#define PHASE_CORRECT 3

void TMR2_voidInit();
void TMR2_voidLoadCounter(u8 copy_u8CounterValue);
void TMR2_voidSetCallBack_OF(void(*ptr));
void TMR2_voidSetCallBack_CTC(void(*ptr));
void TMR2_voidLoadOCR(u8 copy_u8PreloadValue);
u8   TMR2_u8GetCounter();

#endif
