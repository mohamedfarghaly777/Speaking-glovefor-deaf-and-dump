
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"

volatile u8* DIO_OutRegsArr[4] = {PORTA_Reg,PORTB_Reg,PORTC_Reg,PORTD_Reg};
volatile u8* DIO_InRegsArr[4]  = {PINA_Reg,PINB_Reg,PINC_Reg,PIND_Reg};
volatile u8* DIO_DirRegsArr[4] = {DDRA_Reg,DDRB_Reg,DDRC_Reg,DDRD_Reg};

void DIO_vidSetPinValue(u8 u8PortId , u8 u8PinId , u8 u8PinVal)
{
	if((u8PortId <= PortD) && (u8PinId <= Pin7))
	{
		if(u8PinVal == High)
		{
			SET_BIT((*DIO_OutRegsArr[u8PortId]),u8PinId);
		}
		else if(u8PinVal == Low)
		{
			CLR_BIT((*DIO_OutRegsArr[u8PortId]),u8PinId);
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Invalid Inputs */
	}
}

u8   DIO_u8GetPinValue(u8 u8PortId , u8 u8PinId)
{
	if((u8PortId <= PortD) && (u8PinId <= Pin7))
	{
		return(GET_BIT((*DIO_InRegsArr[u8PortId]),u8PinId));
	}
	else
	{
		return INVALID_INPUT;
	}
}

void DIO_vidSetPinDirection(u8 u8PortId , u8 u8PinId , u8 u8PinDir)
{
	if((u8PortId <= PortD) && (u8PinId <= Pin7))
	{
		if(u8PinDir == Output)
		{
			SET_BIT((*DIO_DirRegsArr[u8PortId]),u8PinId);
		}
		else if(u8PinDir == Input)
		{
			CLR_BIT((*DIO_DirRegsArr[u8PortId]),u8PinId);
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Invalid Inputs */
	}
}

/* Port Interfaces */
void DIO_vidSetPortValue(u8 u8PortId ,u8 u8PortVal)
{
	if(u8PortId <= PortD)
	{
		*DIO_OutRegsArr[u8PortId] = u8PortVal;
	}
	else
	{
		/* Invalid Inputs */
	}
}

void DIO_vidSetPortDir(u8 u8PortId , u8 u8PortDir)
{
	if(u8PortId <= PortD)
	{
		*DIO_DirRegsArr[u8PortId] = u8PortDir;
	}
	else
	{
		/* Invalid Inputs */
	}
}


u8 dio_u8GetPortValue(u8 u8portid){


	return *DIO_InRegsArr[u8portid];

}






