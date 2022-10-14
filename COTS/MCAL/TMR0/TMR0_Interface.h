#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H

// Wave generation mode bits
#define WGM0_BIT0   6
#define WGM0_BIT1   3

// Clock source bits (prescalar)
#define CS0_BIT0    0
#define CS0_BIT1    1
#define CS0_BIT2    2

// Prescalar factors
#define NO_clk    (0x00)
#define clk       (0x01)
#define clk_8     (0x02)
#define clk_64    (0x03)
#define clk_256   (0x04)
#define clk_1024  (0x05)
#define EXT_FALLING_EDGE (0x06)
#define EXT_RISING_EDGE	 (0x07)


// Overflow interrupt enable bits
#define TOIE0_BIT   0
#define OCIE0_BIT   1

// Modes
#define NORMAL        0
#define CTC           1
#define FAST_PWM      2
#define PHASE_CORRECT 3

void TMR0_voidInit();
void TMR0_voidLoadCounter(u8 copy_u8CounterValue);
void TMR0_voidSetCallBack_OVF(void(*ptr));
void TMR0_voidSetCallBack_COMP(void(*ptr));
void TMR0_voidLoadOCR(u8 copy_u8CompareValue);
u8   TMR0_u8GetTCNT0();

#endif
