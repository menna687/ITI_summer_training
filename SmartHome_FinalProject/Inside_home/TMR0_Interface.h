#ifndef _TMR0_INTERFACE_H
#define _TMR0_INTERFACE_H

void TMR0_voidInit(void);
void TMR0_voidPreload(u16 Copy_u16Value);
void TMR0_SetCallBack(void (*Ptr)(void));
void TMR0_voidOCR0(u16 Copy_u16OCR0Value);

#endif
