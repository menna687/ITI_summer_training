#ifndef _USART_PRIVATE_H
#define _USART_PRIVATE_H

#define  UCSRA     *((volatile u8*)0x2B)
#define  UCSRB     *((volatile u8*)0x2A)

#define  UBRRL     *((volatile u8*)0x29)
#define  UBRRH     *((volatile u8*)0x40)
#define  UCSRC     *((volatile u8*)0x40)

#define  UDR     *((volatile u8*)0x2C)



#endif
