#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit();
void UART_voidSendData(u8 Copy_u8Data);
void UART_voidSendString(u8 Copy_u8String[]);
void UART_voidSendDigits(u32 Copy_u32Num);
u8   UART_u8ReceiveData();


#endif
