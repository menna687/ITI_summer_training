#ifndef EXTINT_INTERFACE_H
#define EXTINT_INTERFACE_H

//    Interrupt Enable Bits
#define EXT0_EN_BIT    (0x06)
#define EXT1_EN_BIT    (0x07)
#define EXT2_EN_BIT    (0x05)

//    Sense Control
#define EXTI_LOW_LEVEL        (0x00)
#define EXTI_LOGICAL_CHANGE   (0x01)
#define EXTI_FALLING_EDGE     (0x02)
#define EXTI_RISING_EDGE      (0x03)

//    Sense Control Bits
#define EXT0_CONTROL_BIT1   (0x00)
#define EXT0_CONTROL_BIT2   (0x01)

#define EXT1_CONTROL_BIT1   (0x02)
#define EXT1_CONTROL_BIT2	(0x03)

#define EXT2_CONTROL_BIT    (0x06)


/* Functions Prototypes*/
void EXTI0_voidInit(u8 Copy_u8SenseControl_EXT0);
void EXTI1_voidInit(u8 Copy_u8SenseControl_EXT1);
void EXTI2_voidInit(u8 Copy_u8SenseControl_EXT2);

void EXTI0_voidSetCallBack(void(*ptr));
void EXTI1_voidSetCallBack(void(*ptr));
void EXTI2_voidSetCallBack(void(*ptr));

#endif
