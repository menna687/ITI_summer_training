#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "EXTINT_Interface.h"
#include "EXTINT_Private.h"
#include "EXTINT_Config.h"


void EXTI0_voidInit(u8 Copy_u8SenseControl_EXT0)
{
	// Interrupt pin input PULLUP
	DIO_voidSetPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID, PIN2_ID, PIN_HIGH);

	// Set sense control bits
	switch(Copy_u8SenseControl_EXT0)
	{
	case EXTI_RISING_EDGE:
		SET_BIT(MCUC_REG, EXT0_CONTROL_BIT1);
		SET_BIT(MCUC_REG, EXT0_CONTROL_BIT2);
		break;

	case EXTI_FALLING_EDGE:
		CLR_BIT(MCUC_REG, EXT0_CONTROL_BIT1);
		SET_BIT(MCUC_REG, EXT0_CONTROL_BIT2);
		break;

	case EXTI_LOW_LEVEL:
		CLR_BIT(MCUC_REG, EXT0_CONTROL_BIT1);
		CLR_BIT(MCUC_REG, EXT0_CONTROL_BIT2);
		break;

	case EXTI_LOGICAL_CHANGE:
		SET_BIT(MCUC_REG, EXT0_CONTROL_BIT1);
		CLR_BIT(MCUC_REG, EXT0_CONTROL_BIT2);
		break;
	}

	// Enable EXT0 (General interrupt control)
	SET_BIT(GIC_REG, EXT0_EN_BIT);
}



void EXTI1_voidInit(u8 Copy_u8SenseControl_EXT1)
{
	// Interrupt pin input PULLUP
	DIO_voidSetPinDirection(PORTD_ID, PIN3_ID, PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID, PIN3_ID, PIN_HIGH);

	// Set sense control bits
	switch(Copy_u8SenseControl_EXT1)
	{
		case EXTI_RISING_EDGE:
			SET_BIT(MCUC_REG, EXT1_CONTROL_BIT1);
			SET_BIT(MCUC_REG, EXT1_CONTROL_BIT2);
			break;

		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUC_REG, EXT1_CONTROL_BIT1);
			SET_BIT(MCUC_REG, EXT1_CONTROL_BIT2);
			break;

		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUC_REG, EXT1_CONTROL_BIT1);
			CLR_BIT(MCUC_REG, EXT1_CONTROL_BIT2);
			break;

		case EXTI_LOGICAL_CHANGE:
			SET_BIT(MCUC_REG, EXT1_CONTROL_BIT1);
			CLR_BIT(MCUC_REG, EXT1_CONTROL_BIT2);
			break;
	}

	// Enable EXT1 (General interrupt control)
	SET_BIT(GIC_REG, EXT1_EN_BIT);
}



void EXTI2_voidInit(u8 Copy_u8SenseControl_EXT2)
{
	// Interrupt pin input PULLUP
	DIO_voidSetPinDirection(PORTB_ID, PIN2_ID, PIN_INPUT);
	DIO_voidSetPinValue(PORTB_ID, PIN2_ID, PIN_HIGH);

	// Set sense control bits
	switch(Copy_u8SenseControl_EXT2)
	{
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCS_REG, EXT2_CONTROL_BIT);
			break;

		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCS_REG, EXT2_CONTROL_BIT);
			break;
	}

	// Enable EXT2 (General interrupt control)
	SET_BIT(GIC_REG, EXT2_EN_BIT);
}

	 /* Set Callback */
void(*EXTI0_GPFun)(void) = '\0';
void(*EXTI1_GPFun)(void) = '\0';
void(*EXTI2_GPFun)(void) = '\0';
	 
void EXTI0_voidSetCallBack(void(*ptr))
{
	EXTI0_GPFun = ptr;
} 


void EXTI1_voidSetCallBack(void(*ptr))
{
	EXTI1_GPFun = ptr;
}


void EXTI2_voidSetCallBack(void(*ptr))
{
	EXTI2_GPFun = ptr;
}


     /* INTERRUPT SERVICE ROUTINES */
void __vector_1()__attribute__((signal));
void __vector_1()
{
	if(EXTI0_GPFun != '\0')
	{
		EXTI0_GPFun();
	}
}



void __vector_2()__attribute__((signal));
void __vector_2()
{
	if(EXTI1_GPFun != '\0')
	{
		EXTI1_GPFun();
	}
}



void __vector_3()__attribute__((signal));
void __vector_3()
{
	if(EXTI2_GPFun != '\0')
	{
		EXTI2_GPFun();
	}
}


