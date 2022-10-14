#ifndef TMR1_PRIVATE_H
#define TMR1_PRIVATE_H

#define TCCR1A  *((volatile u8*) 0x4F)
#define TCCR1B  *((volatile u8*) 0x4E)
#define ICR1    *((volatile u16*)0x46)
#define OCR1A   *((volatile u16*)0x4A)
#define TIMSk   *((volatile u8*) 0x59)

#endif
