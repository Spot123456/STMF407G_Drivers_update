/*
 * NVIC.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Ahmed Nour Eldin
 */
#include "../Inc/STD_Type.h"
#include "../Inc/Math.h"
#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"

void		NVIC_voidInit()
{
	//use system control block to access the NVIC
#ifndef SCB_BaseAddress
#define SCB_BaseAddress		(0xE000ED00)
#define	SCB_AIRCR			*((u32*)(SCB_BaseAddress+0x0C))
#endif

	// first we need write to regester so we rite a key for it
	// the second we need to select the periority in the second half of word
	// so let say the first 4 bits (half word) is a key and the 3bit (half byte is for periority)

	SCB_AIRCR=NVIC_GRP_SUB_per;

}

void		NVIC_voidEnablePerInt(u8 NVIC_Num)
{
	if(NVIC_Num<32)
	{
		NVIC_REG->NVIC_ISER[0]=(1<<NVIC_Num);
	}
	else if(NVIC_Num<64)
	{
		NVIC_Num-=32;
		NVIC_REG->NVIC_ISER[1]=(1<<NVIC_Num);

	}
	else
	{
		//error handling
	}
}
void		NVIC_voidDisablePerInt(u8 NVIC_Num)
{
	if (NVIC_Num<32)
	{
		NVIC_REG->NVIC_ICER[0]=(1<<NVIC_Num);
	}
	else if (NVIC_Num<64)
	{
		NVIC_Num-=32;
		NVIC_REG->NVIC_ICER[1]=(1<<NVIC_Num);
	}
	else
	{
		//error handling
	}
}
void		NVIC_voidSetPendingFlag(u8 NVIC_Num)
{
	if (NVIC_Num<32)
		{
			NVIC_REG->NVIC_ISPR[0]=(1<<NVIC_Num);
		}
		else if (NVIC_Num<64)
		{
			NVIC_Num-=32;
			NVIC_REG->NVIC_ISPR[1]=(1<<NVIC_Num);
		}
		else
		{
			//error handling
		}
}

void		NVIC_voidClrPendingFlag(u8 NVIC_Num)
{
	if (NVIC_Num<32)
		{
			NVIC_REG->NVIC_ICPR[0]=(1<<NVIC_Num);
		}
		else if (NVIC_Num<64)
		{
			NVIC_Num-=32;
			NVIC_REG->NVIC_ICPR[1]=(1<<NVIC_Num);
		}
		else
		{
			//error handling
		}
}

u8			NVIC_u8ReadActiveFlag(u8 NVIC_Num)
{
	u8 Result_Active_Flag;
	if (NVIC_Num<32)
		{
			Result_Active_Flag=( NVIC_REG->NVIC_IABR[0]&(1<<NVIC_Num));
		}
		else if (NVIC_Num<64)
		{
			NVIC_Num-=32;
			Result_Active_Flag =(NVIC_REG->NVIC_IABR[1]&(1<<NVIC_Num));
		}
		else
		{
			//error handling
		}
	return Result_Active_Flag;

}

void	NVIC_voidSetSwIntPriority(u8 NVIC_Num , u8 priority)
{
	/* let say i need access the sec byte of register , and remember that one address array
	 * has four location so when i need to access the sec byte in ipr[0] we need to define location
	 * where location = nvic_num/4 let make this example :
	 * location = 1/4 = 0 --> this is location
	 * and i need to shift 1 byte to set periority so use nvic num for shift
	 *
	 * OR
	 *
	 * another solution make this register access one byte (u8)* and set with nvic location without
	 * shifting of=r make avariable ( remember bit pading in struct may set a problem )
	 *  */
	u8 location;
	if(NVIC_Num<32)
	{
		location = NVIC_Num/4;
		NVIC_REG->NVIC_IPR[location]|=(priority<< 4 * NVIC_Num);
	}
	else if(NVIC_Num<64)
	{
		location = NVIC_Num/4; // cal location
		NVIC_Num-=32; // then cal the nvic -32
		NVIC_REG->NVIC_IPR[location]|=(priority<< 4 * NVIC_Num);
	}
	else if(NVIC_Num<96)
	{
		location = NVIC_Num/4; // cal location
		NVIC_Num-=64; // then cal the nvic -32
		NVIC_REG->NVIC_IPR[location]|=(priority<< 4 * NVIC_Num);
	}

}


