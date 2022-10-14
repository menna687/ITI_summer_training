#ifndef _TMR0_CONFIG_H
#define _TMR0_CONFIG_H



/************************prescaler**********************/
#define TMR0_NO_Prescaler        1
#define TMR0_Prescaler_8         8
#define TMR0_Prescaler_64        64
#define TMR0_Prescaler_256       256
#define TMR0_Prescaler_1024      1024

#define CS00     0
#define CS01     1
#define CS02     2

#define TMR0_Prescaler   TMR0_Prescaler_8

/****************************Modes*****************************/
#define Normal               0
#define PhaseCorrectPWM      1
#define CTC                  2
#define FastPWM              3

#define COM00    4
#define COM01    5

#define WGM01     3
#define WGM00     6

#define TOIE0     0
#define OCIE0     1


#define TMR0_Mode   FastPWM

#endif
