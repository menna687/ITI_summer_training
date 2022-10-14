#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#define STOP   (0x00)
#define RIGHT  (0x01)
#define LEFT   (0x02)

							/* Functions Prototypes */
void MOTOR_voidInit(void);
void MOTOR_voidRotate(u8 copy_u8RotationDirection);

#endif
