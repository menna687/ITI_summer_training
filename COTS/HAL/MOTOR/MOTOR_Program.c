#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "MOTOR_Interface.h"
#include "MOTOR_Config.h"

void MOTOR_voidInit(void)
{
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN1, PIN_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN2, PIN_OUTPUT);
}


void MOTOR_voidRotate(u8 copy_u8RotationDirection)
{
	switch(copy_u8RotationDirection)
	{
		case STOP:
		{
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
			break;
		}
		case RIGHT:
		{
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_HIGH);
			break;
		}
		case LEFT:
		{
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
			DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_HIGH);
			break;
		}
	}
}
