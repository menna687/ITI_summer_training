#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void main()
{
	u8 x = 5, b = 1;
	printf("get: %d\n", getBit(x, b));
	printf("set: %d\n", setBit(x, b));
	printf("clear: %d\n", clearBit(x, b));
	printf("toggle: %d\n", toggleBit(x, b));
}