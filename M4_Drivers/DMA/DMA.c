/*
 * DMA.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Ahmed Nour
 */


#include "../Inc/STD_Type.h"
#include "../Inc/Math.h"

#include "DMA_Private.h"
#include "DMA_Config.h"
#include "DMA_Interface.h"

static void (* DMA2_CallBack[7])(void) = {NULL} ;
static u8 Global_stream= NULL;

void DMA2_init(u8 stream , u8 DMA_Mode ,u8 channel,u8 from_to  )
{
	/*we need to disable the peripheral and clear the interrupt*/

	/* select the channel */
	DMA2_Reg->channel[stream].DMA_SCR|=(channel<<25);
	/* data brust */
	DMA2_Reg->channel[stream].DMA_SCR|=(Mem_Brust_data<<23);
	DMA2_Reg->channel[stream].DMA_SCR|=(Pre_Brust_data<<21);
	/* select DMA mode */
	DMA2_Reg->channel[stream].DMA_SCR|=(DMA_Mode<<18);
	DMA2_Reg->channel[stream].DMA_SCR|=(CT<<19);
	/* select the DMA work for ?*/
	switch(from_to)
	{
		case Pre_To_Arr :DMA2_Reg->channel[stream].DMA_SCR|=(00<<6);
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);
						 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
						 break;
		case Arr_To_Pre :DMA2_Reg->channel[stream].DMA_SCR|=(0b01<<6);
						 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
						 break;
		case Arr_To_Arr :DMA2_Reg->channel[stream].DMA_SCR|=(0b10<<6);
						 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);
						 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
						break;
		case Pre_To_Pre :DMA2_Reg->channel[stream].DMA_SCR|=(00<<6);
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
						 break;

		case const_To_Const :DMA2_Reg->channel[stream].DMA_SCR|=(0b10<<6);
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);				// memory
						 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
						 break;

		case const_To_Arr :DMA2_Reg->channel[stream].DMA_SCR|=(0b10<<6);
								 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,10);				// memory
								 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,9);
								 break;
	}

	/*circular mode or direct mode */
#if	mode == circular
	SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,8);
	SET_Bit(DMA2_Reg->channel[stream].DMA_SFCR, 2);
#elif mode == direct
	 CLR_Bit(DMA2_Reg->channel[stream].DMA_SCR,8);
	 CLR_Bit(DMA2_Reg->channel[stream].DMA_SFCR, 2);
#endif

	/* Transfer complete interrupt enable*/
	 SET_Bit(DMA2_Reg->channel[stream].DMA_SCR,4);

}

void DMA2_select_channel(u8 channel,u32 *send_to,u32 *receive_from,u32 *receive_from2_double , u16 total_transfer)
{
	/* select channel and make sure that disable*/
	CLR_Bit(DMA2_Reg->channel[channel].DMA_SCR,0);
	/*select total transfer*/
	DMA2_Reg->channel[channel].DMA_SNDTR=total_transfer;
	/*select send address */
	DMA2_Reg->channel[channel].DMA_SPAR= (u32)send_to;
	/*receive address*/
	DMA2_Reg->channel[channel].DMA_SM0AR =(u32) receive_from;
	/*check if it double mode or not if not write zero*/
	if (receive_from2_double== (u32*)0)
	{
		// do nothing
	}
	else
	{
	DMA2_Reg->channel[channel].DMA_SM1AR =(u32) receive_from2_double;
	}
	/*set FIFO threshold Selection */
	DMA2_Reg->channel[channel].DMA_SFCR|= (FIFO_threshold<<0);
	/*Enable DMA*/
	DMA2_Reg->channel[channel].DMA_SCR|=1;

}

void DMA2_SW_change_periority(u8 channel ,u8 periority )
{
	DMA2_Reg->channel[channel].DMA_SCR |= (periority<<16);
}

void DMA2_SetcallBack(void (*notification) (void) , u8 number_of_stream)
{
	if(notification!=NULL)
	{
		DMA2_CallBack[number_of_stream]=notification;
		Global_stream= number_of_stream;
	}

}


#define  busy	1 // state of set call back function
#define	 free	0
static	u8 state; // use to handle the state of call back

void	DMA2_Stream0_IRQHandler()
{
	state = free;
	if(0== Global_stream && state == free )
	{
		state= busy ;
		if(DMA2_CallBack!=NULL)
		{
			DMA2_CallBack[0]();
		}
		/*clear transfer complete*/
		DMA2_Reg->DMA_LIFCR|=1<<5;
	}
}

void	DMA2_Stream1_IRQHandler()
{
	state = free;
	if(1== Global_stream  && state == free )
	{
		if(DMA2_CallBack!=NULL)
		{
			DMA2_CallBack[1]();
		}
	}

}
void	DMA2_Stream3_IRQHandler()
{
	state = free;
	if(3== Global_stream  && state == free )
	{
		if(DMA2_CallBack!=NULL)
		{
			state= busy ;
			DMA2_CallBack[3]();
		}
		/*clear transfer complete*/
	//	DMA2_Reg->DMA_LIFCR|=1<<27;
	}
	DMA2_Reg->DMA_LIFCR|=1<<27;
	DMA2_Reg->channel[Global_stream].DMA_SCR&=~1;
}
void	DMA2_Stream4_IRQHandler()
{
	state = free;
	if(4== Global_stream)
	{
		if(DMA2_CallBack!=NULL  && state == free )
		{
			DMA2_CallBack[4]();
		}
	}
}
