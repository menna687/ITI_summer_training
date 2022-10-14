#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define PRESCALAR_2     (0x01)
#define PRESCALAR_4     (0x02) 
#define PRESCALAR_8     (0x03)
#define PRESCALAR_16    (0x04)
#define PRESCALAR_32    (0x05)
#define PRESCALAR_64    (0x06)
#define PRESCALAR_128   (0x07)


void ADC_voidInit(void);
u16  ADC_u16GetResult(void);
void ADC_voidConvertChannel(u8 channel);

#endif


