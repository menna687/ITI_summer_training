#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"

void SPI_voidSlaveInit()
{

	// SPI interrupt enable
	SET_BIT(SPCR, 7);
	// SPI enable
	SET_BIT(SPCR, 6);
	// LSB first 
	SET_BIT(SPCR, 5);	
	// Slave
	CLR_BIT(SPCR, 4);
}

void SPI_voidMasterInit()
{
	// SPI interrupt enable
	SET_BIT(SPCR, 7);
	// SPI enable
	SET_BIT(SPCR, 6);
	// LSB first 
	SET_BIT(SPCR, 5);	
	// Slave
	SET_BIT(SPCR, 4);
}


void SPI_voidTransceiver(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	if(GETBIT(SPSR, 7))
	{
		return SPDR;
	}
}
