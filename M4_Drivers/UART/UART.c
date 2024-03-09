/*
 * UART.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Ahmed Nour
 */


#include "../Inc/STD_Type.h"
#include "../Inc/Math.h"
#include "../Inc/ERROR_Type.h"

#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"


static void (*UART_INT[5])(void)= {NULL};

void UART_Init(u8 UART_no)
{
	/*uart number from 1 to 6 (i.e there is no uart 0 */
	UART_no-=1;
	if(UART_no<=6)
	{
		/* last one u need to enable UART ( this is ridiculous )*/
		SET_Bit(UART_Regs[UART_no]->USART_CR1,13);
		/*choose the boudrate of communication  */
		UART_Regs[UART_no]->USART_BRR= ((u32) UART_Clk <<4)|(1);//(DIV_Fraction);
		/*masking the 15 bit then choose the sampling */
		CLR_Bit( UART_Regs[UART_no]->USART_CR1 , 15);
		UART_Regs[UART_no]->USART_CR1|= (oversampling_mode<<15);

		/* set the length of frame */
		CLR_Bit(UART_Regs[UART_no]->USART_CR1,12);
		UART_Regs[UART_no]->USART_CR1 |= (Word_length<<12);

		/*select the parity enable or not */
#if parity == Enable
		UART_Regs[UART_no]->USART_CR1 |= (parity<<10);
		/*select the type of parity*/
		UART_Regs[UART_no]->USART_CR1 |= (parity_type<<9);
#elif parity == Disable
		CLR_Bit(UART_Regs[UART_no]->USART_CR1 ,10);

#endif
		/*select the stop bits */
		UART_Regs[UART_no]->USART_CR2|=(stop_bit_conf<<12);
		/*enable Tx*/
		SET_Bit(UART_Regs[UART_no]->USART_CR1,3);
		/*enable Rx*/
		SET_Bit(UART_Regs[UART_no]->USART_CR1,2);
		/* work clear should clear the status reg ^_^ */
		UART_Regs[UART_no]->USART_SR=0;


	}
	else
	{
		//error handling
	}
}

EN_Error_t UART_Send_byte(u8 UART_no,u8 UART_data)
{
	/*uart number from 1 to 6 (i.e there is no uart 0 */
	UART_no-=1;
	EN_Error_t Local_Error= OK;
	while(!GET_Bit(UART_Regs[UART_no]->USART_SR,7))
	{
		// stuck until empty
	}
	UART_Regs[UART_no]->USART_DR = UART_data;
	/*wait until the tx_send*/
	//while(GET_Bit(UART_Regs[UART_no]->USART_SR,6));

	return Local_Error;
}

EN_Error_t UART_Receive_byte(u8 UART_no,u8 * receive_data)
{
	/*uart number from 1 to 6 (i.e there is no uart 0 */
	UART_no-=1;
	EN_Error_t Local_Error = OK;
	// wait until receive uart frame
	while(GET_Bit(UART_Regs[UART_no]->USART_SR,5)==0);
	*receive_data= UART_Regs[UART_no]->USART_DR;
	//CLR_Bit(UART_Regs[UART_no]->USART_SR,5);
	return Local_Error;
}

EN_Error_t UART_Send_Arr(u8 UART_no,u8* UART_Arr)
{
	EN_Error_t local_error=OK;
	while(*UART_Arr!='\0')
	{
		UART_Send_byte(UART_no, *UART_Arr);
		UART_Arr++;
	}
	return local_error;
}

EN_Error_t UART_Receive_Arr(u8 UART_no,u8* receive_arr_data)
{
	EN_Error_t local_error=OK;
	UART_Receive_byte(UART_no, receive_arr_data);
	while(*receive_arr_data!='\0')
	{
		/*inc the array then receive the value to new location ++ */
		receive_arr_data++;
		//UART_Receive_byte(UART_no, receive_arr_data);
	}

	return local_error;
}

void UART_Interrupt_Enable(u8 UART_no)
{
	/*parity error interrupt*/
	UART_Regs[UART_no]->USART_CR1|=(1<<8);
	/*TXE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1|=(1<<7);
	/*Transmission complete interrupt enable*/
	UART_Regs[UART_no]->USART_CR1|=(1<<6);
	/* RXNE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1|=(1<<5);
	/*IDLE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1|=(1<<4);
}


void UART_Interrupt_Disable(u8 UART_no)
{
	/*parity error interrupt*/
	UART_Regs[UART_no]->USART_CR1&=~(1<<8);
	/*TXE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1&=~(1<<7);
	/*Transmission complete interrupt enable*/
	UART_Regs[UART_no]->USART_CR1&=~(1<<6);
	/* RXNE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1&=~(1<<5);
	/*IDLE interrupt enable*/
	UART_Regs[UART_no]->USART_CR1&=~(1<<4);
}

EN_Error_t UART_InterruptCallBack_RX(u8 UART_no, void (*RX)(void))
{
	EN_Error_t local_error= OK;
	if(RX!=NULL)
	{
		UART_INT[UART_no]=RX;
	}
	else
	{
		local_error=NOK;
	}
	return local_error;

}

void USART1_IRQHandler ()
{

}

void USART2_IRQHandler ()
{

}

void USART3_IRQHandler ()
{

}
void USART4_IRQHandler ()
{

}
void USART5_IRQHandler ()
{

}
void USART6_IRQHandler ()
{

}


