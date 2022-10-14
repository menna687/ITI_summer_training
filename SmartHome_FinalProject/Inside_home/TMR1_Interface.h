#ifndef _TMR1_INTERFACE_H
#define _TMR1_INTERFACE_H

void TMR1_voidInit(void);
void TMR1_SetCallBack(void (*Ptr)(void));
void TMR1_voidOCR1A(u16 Copy_u16OCR1AValue);
void TMR1_voidPreload(u16 Copy_u16Value);

#endif



