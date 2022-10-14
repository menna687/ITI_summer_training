#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"

void GIE_voidExtIntEnable()
{
	SET_BIT(S_REG, EXTI_BIT);
}

void GIE_voidExtIntDisable()
{
	CLR_BIT(S_REG, EXTI_BIT);
}
