#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H

void USART_voidInitial(void);
void USART_voidSendData(u16 Copy_u16Data);
u16 USART_u16RecieveData(void);
void USART_voidSendString(u8 *Copy_u8String);
void USART_voidSendNumbers(u8 Copy_u8Number);

#endif
