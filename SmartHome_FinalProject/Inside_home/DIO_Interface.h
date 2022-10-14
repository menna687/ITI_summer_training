#ifndef _DIO_INTERFACE_H            //header file guard
#define _DIO_INTERFACE_H

                        /*Functions Prototypes*/
void DIO_voidSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection);
void DIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue);

void DIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortDirection);
void DIO_voidSetPortValue(u8 Copy_u8PortID , u8 Copy_u8PortValue);

void DIO_voidTogglePinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);


#endif