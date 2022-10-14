#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

void EXT_voidGIE_Enable(void)
{
	SetBit(SREG , pin7);
}

void EXT_voidGIE_Disable(void)
{
	ClrBit(SREG , pin7);
}
