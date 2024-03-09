/*
 * STK.C
 *
 *  Created on: Feb 16, 2024
 *      Author: Ahmed Nour
 */


#include "../Inc/STD_Type.h"
#include "../Inc/Math.h"

#include "STK_Private.h"
#include "STK_Config.h"
#include "STK_Interface.h"

static void (*STK_CallBack)(void)=NULL;
u8 STK_u8ModeOfInterval ;
void	STK_Void_Init()
{
#if CLK_Source_Selection == AHB_Div8
	STK_Reg->STK_CTRL&=~(1<<2);
#elif CLK_Source_Selection == AHB
	STK_Reg->STK_CTRL|=(1<<2);
#endif

}
void	STK_voidSetBusyWait(u32	Ticks)
{
	/*load a value of timer */
	STK_Reg->STK_LOAD=Ticks;
	/* start timer */
	STK_Reg->STK_CTRL|=1;
	/*block state because the function we need busy wait */
	while(GET_Bit(STK_Reg->STK_CTRL,16)==0)
	{
		/*assembly op for non optimize */
		asm("NOP");
	}
	/* clear the timer */
	CLR_Bit(STK_Reg -> STK_CTRL , 0);
	STK_Reg ->	STK_LOAD	=	0;
	STK_Reg ->	STK_VAL		=	0;

}

void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void))
{
	/* enable interrupt */
	STK_Reg->STK_CTRL|=(1<<1);
	/* load value of timer */
	STK_Reg->STK_LOAD= Ticks;
	/*enable timer */
	STK_Reg->STK_CTRL|=1;
	/*start the interrupt of call back */
	STK_CallBack=Pf;
	/* select mode as single interval */
	STK_u8ModeOfInterval= single_interval;

}

void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void))
{
	/*enable interrupt */
	STK_Reg->STK_CTRL|=(1<<1);
	/* load the value of timer*/
	STK_Reg->STK_LOAD=Ticks;
	/*start imer*/
	STK_Reg->STK_CTRL|=1;
	/* start the interrupt of call back*/
	STK_CallBack=Pf;
	/*select mode as multi interval */
	STK_u8ModeOfInterval=Multi_interval;
}
void	STK_voidStopInterval()
{
	/*stop interrupt */
	CLR_Bit(STK_Reg->STK_CTRL,1);

	/* reset the register and stop timer*/
	STK_Reg->STK_VAL=0;
	STK_Reg->STK_LOAD=0;
	CLR_Bit( STK_Reg->STK_CTRL,0);
}
u32		STK_u32GetElapsedTime()
{
	u32 local_Elapsed =0;
	local_Elapsed= (STK_Reg->STK_LOAD)-(STK_Reg->STK_VAL);
	return local_Elapsed;
}

u32		STK_u32GetRemainingTime()
{
	u32 reminder =0;
		reminder= (STK_Reg->STK_VAL);
		return reminder;
}


void SysTick_Handler()
{
	u8 x;
	if(STK_CallBack!=NULL)
	{

		if(STK_u8ModeOfInterval==single_interval)
		{

			/*stop interrupt */
			CLR_Bit(STK_Reg->STK_CTRL,1);
			STK_Reg->STK_VAL=0;
			STK_Reg->STK_LOAD=0;
			CLR_Bit( STK_Reg->STK_CTRL,0);

		}
		STK_CallBack();
		/*clear the flag of interrupt*/
		x=GET_Bit(STK_Reg->STK_CTRL,16);

	}
}


