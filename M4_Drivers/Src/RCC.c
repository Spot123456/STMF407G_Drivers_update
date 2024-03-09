/*
 * RCC.C
 *
 *  Created on: Dec 29, 2023
 *      Author: Ahmed Nour
 */

#include "ERROR_Type.h"
#include "../Inc/STD_Type.h"
#include "Math.h"

#include "RCC_Private.h"
#include "RCC_Config.h"

#include "RCC_Interface.h"


static void(*Handler_RCC)(void);

void RCC_V_InitCLK(void)
{
#if InputCLK == RCC_HSI
	// init the RCC CLK ( Set HSI OSC )
	RCC_Reg->RCC_CR=0x1;
	RCC_Reg->RCC_CFGR&=~(1<<2);
	#if RCC_Enable_Interrupt== RCC_Polling
		// wait until clk is ready
		while(GET_Bit(RCC_Reg->RCC_CR,1)==0);
	#elif RCC_Enable_Interrupt == RCC_Interrupt
		//enable interrupt flag
		RCC_Reg->RCC_CIR|=(1<<10);
		SET_Bit(RCC_Reg->RCC_CR,19);		//clk security
	#endif

#elif InputCLK == RCC_HSE
	SET_Bit(RCC_Reg->RCC_CR,16);
	//SET_Bit(RCC_Reg->RCC_CR,19);		//clk security
	SET_Bit(RCC_Reg->RCC_CR,18);		// by pass HSE

	#if RCC_Enable_Interrupt== RCC_Polling
		while(GET_Bit(RCC_Reg->RCC_CR,17)==0); // wait until HSE clk work
	#elif RCC_Enable_Interrupt == RCC_Interrupt

		SET_Bit(RCC_Reg->RCC_CIR,11); // enable interrupt

	#endif

#endif
}

void RCC_V_EnablePer(u8 peripheral,u8 Bus_ID)
{
	if(Bus_ID<5 && peripheral<32)
	{
		/* prescaler for AHB Bus */
		RCC_Reg->RCC_CFGR&=~(AHB_Pre_Mask<<4);
		RCC_Reg->RCC_CFGR|=(RCC_AHB_Prescaler<<4);

		/* prescaler for APB1 Bus */
		RCC_Reg->RCC_CFGR&=~(APB_Mask<<10);
		RCC_Reg->RCC_CFGR|=(RCC_APB1_Prescaler<<10);

		/* Prescaler for APB2 BUS */
		RCC_Reg->RCC_CFGR&=~(APB_Mask<<13);
		RCC_Reg->RCC_CFGR|=(RCC_APB2_Prescaler<<13);
		switch (Bus_ID)
		{
		case RCC_AHB1 : RCC_Reg->RCC_AHB1ENR|=(1<<peripheral); break;
		case RCC_AHB2 :	RCC_Reg->RCC_AHB2ENR|=(1<<peripheral); break;
		case RCC_AHB3 :	RCC_Reg->RCC_AHB3ENR|=(1<<peripheral); break;
		case RCC_APB1 :	RCC_Reg->RCC_APB1ENR|=(1<<peripheral); break;
		case RCC_APB2 :	RCC_Reg->RCC_APB2ENR|=(1<<peripheral); break;

		}
	}
	else
	{
		// do nothing
	}
}

EN_Error_t RCC_V_DisablePer(u8 peripheral,u8 Bus_ID)
{
	EN_Error_t Local_State = OK;
	if(peripheral<32 && Bus_ID<5)
	{
		switch (Bus_ID)
		{
		case RCC_AHB1 : RCC_Reg->RCC_AHB1RSTR = (1<<peripheral); break;
		case RCC_AHB2 :	RCC_Reg->RCC_AHB2RSTR =(1<<peripheral); break;
		case RCC_AHB3 :	RCC_Reg->RCC_AHB3RSTR =(1<<peripheral); break;
		case RCC_APB1 :	RCC_Reg->RCC_APB1RSTR =(1<<peripheral); break;
		case RCC_APB2 :	RCC_Reg->RCC_APB2RSTR =(1<<peripheral); break;

		}
	}
	else
	{
		Local_State=NOK;
	}
	return Local_State;

}

EN_Error_t RCC_V_EnablePerLowPower(u8 peripheral,u8 Bus_ID)
{
	EN_Error_t Local_State = OK;
	if(peripheral<32 && Bus_ID<5)
	{
		switch(Bus_ID)
		{
		case RCC_AHB1 : RCC_Reg->RCC_AHB1LPENR |=(1<<peripheral); break;
		case RCC_AHB2 :	RCC_Reg->RCC_AHB2LPENR |=(1<<peripheral); break;
		case RCC_AHB3 :	RCC_Reg->RCC_AHB3LPENR |=(1<<peripheral); break;
		case RCC_APB1 :	RCC_Reg->RCC_APB1LPENR |=(1<<peripheral); break;
		case RCC_APB2 :	RCC_Reg->RCC_APB2LPENR |=(1<<peripheral); break;
		}
	}
	else
	{
		 Local_State = NOK;
	}
	return Local_State;
}

void RCC_V_SetCallBack(void(*Notification)(void))
{
	if (*Notification!=NULL)
	{
		Handler_RCC=Notification;
	}
}

void RCC_IRQHandler ()
{
	if(Handler_RCC!=NULL)
	{
		if (GET_Bit(RCC_Reg->RCC_CIR , 2)==1) //HSI
		{
			Handler_RCC();
			// clear the flag
			SET_Bit(RCC_Reg->RCC_CIR,18);

			//should open led for check
		}
		else if(GET_Bit(RCC_Reg->RCC_CIR , 3)==1) // HSE
		{
			Handler_RCC();
			// clear the flag
			SET_Bit(RCC_Reg->RCC_CIR,19);
			CLR_Bit(RCC_Reg->RCC_CIR,11);
		}
		// do any thing
	}
	else
	{
		// do nothing
	}
}
