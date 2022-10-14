#ifndef TMR2_PRIVATE_H
#define TMR2_PRIVATE_H

#define TCCR2  *((volatile u8*)0x45)
#define TCNT2  *((volatile u8*)0x44)
#define OCR2   *((volatile u8*)0x43)
#define TIMSK  *((volatile u8*)0x59)

#endif
