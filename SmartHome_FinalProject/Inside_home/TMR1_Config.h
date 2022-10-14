#ifndef _TMR1_CONFIG_H
#define _TMR1_CONFIG_H

/*TCCRA1*/
#define COM1B0    4
#define COM1B1    5
#define COM1A0    6
#define COM1A1    7

#define WGM10     0
#define WGM11     1

/*CompareOutputMode*/
#define OC1A_OC1B_disconnected       0         //Normal port operation
#define Toggle_OC1A_OC1B             1
#define Clear_OC1A_OC1B              2        //Set output to low level
#define Set_OC1A_OC1B                3        //Set output to high level

#define  TMR1_CompareOutputMode         Clear_OC1A_OC1B

/*TCCRB1*/
/*prescaler*/
#define TMR1_NO_Prescaler        1
#define TMR1_Prescaler_8         8
#define TMR1_Prescaler_64        64
#define TMR1_Prescaler_256       256
#define TMR1_Prescaler_1024      1024

#define CS10     0
#define CS11     1
#define CS12     2

#define TMR1_Prescaler     TMR1_Prescaler_8

#define WGM12    3
#define WGM13    4

#define ICES1    6      // Input Capture Edge Select
#define RisingEdge    0
#define FallingEdge   1


/*TIMSK*/
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5


/*TMR1_MOde*/
#define Normal               0
#define PhaseCorrectPWM      1
#define CTC                  2
#define FastPWM              3

#define TMR1_Mode    FastPWM

#endif
