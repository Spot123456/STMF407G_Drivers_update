/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "Math.h"
#include "STD_Type.h"
#include "RCC_Interface.h"

#include "../DIO/GPIO_Interface.h"
#include "../NVIC/NVIC_Interface.h"
#include "../STK/STK_Interface.h"
#include "../DMA/DMA_Interface.h"
#include "../DMA/DMA_Private.h"
#include "../UART/UART_Interface.h"
u8 x=10;

/*******************************************
 * 				test projects
 * ******************************************/
#define	Project_DMA			1
#define	Project_DIO			2
#define Project_Uart		3
/*******************************************
 * 				 projects selection
 * ******************************************/
#define	Project			Project_Uart

void led ()
{
	u8  static x=0;
	//GPIO_V_Set_Pin_value(PinA_0_High);
	if(x)
	{
	GPIO_V_Set_Pin_value(PinD_15_High);
	//STK_voidSetBusyWait(100000);
	x=0;
	}
	else
	{
		GPIO_V_Set_Pin_value(PinD_15_Low);
		//STK_voidSetBusyWait(100000);
			x=1;
	}
}

/************************************************************/

#if Project == Project_DMA

int main(void)
{

	RCC_V_InitCLK();
	RCC_V_EnablePer(RCC_DMA2,RCC_AHB1);
	RCC_V_EnablePer(0, 0);
	RCC_V_EnablePer(RCC_GPIOD, RCC_AHB1);
	GPIO_V_PortInterface_Direction();
	NVIC_voidInit();
	//NVIC_voidEnablePerInt(5);
	NVIC_voidEnablePerInt(59);
	//NVIC_voidSetSwIntPriority(5, 0b1101);
//	RCC_V_SetCallBack(led);
	STK_Void_Init();
	//GPIO_V_Set_Pin_value(PinD_13_High);
	//GPIO_V_Set_Pin_value(PinD_14_High);
	//GPIO_V_Set_Pin_value(PinD_13_High);
	DMA2_init(3, 0, 2, const_To_Arr); // 0 for no bufferring mode
	u32 arr[100];
	u32 receive_arr[100];
	u32 x=100;
	for(int i=0;i<100;i++)
	{
		arr[i]=i*1000;
	}

	DMA2_SetcallBack(&led, 3);
	//DMA2_select_channel(3, (u32*)arr, (u32*)receive_arr,(u32*)0, 200);


	DMA2_select_channel(3,  (u32*) x, (u32*)receive_arr,(u32*)0, 100);

//	STK_voidSetBusyWait(20000);

	for(;;)
	{
		GPIO_V_Set_Pin_value(PinD_13_High);
		STK_voidSetBusyWait(200000);
		GPIO_V_Set_Pin_value(PinD_13_Low);
		STK_voidSetBusyWait(200000);
	}
}
#elif Project == Project_DIO

#elif Project == Project_Uart
int main()
{
	RCC_V_InitCLK();

	RCC_V_EnablePer(RCC_GPIOA,RCC_AHB1);
	RCC_V_EnablePer(RCC_GPIOB,RCC_AHB1);
	RCC_V_EnablePer(RCC_GPIOC,RCC_AHB1);
	RCC_V_EnablePer(RCC_GPIOD,RCC_AHB1);
	RCC_V_EnablePer(RCC_UART3_APB1, RCC_APB1);
	RCC_V_EnablePer(RCC_UART2_APB1, RCC_APB1);
	/*set port direction */



	GPIO_V_PortInterface_Direction();
	//GPIO_V_Config_MODE_GPIOA(pin2, AF);
	//GPIO_V_Config_MODE_GPIOA(pin3, AF);
	//GPIO_V_Set_Pin_value(PinD_13_High);

	/***************************/

	DIO_voidSetPinDirection(PORTA, pin2, AF, No_pull_up, Output_push_pull); // uart2 tx
		AF_Select_pin_Fun(PORTA, pin2, AF_UART1_3);
		//DIO_voidSetPinSpeed(PORTA, pin2,Very_high_speed );

		DIO_voidSetPinDirection(PORTA, pin3, AF,No_pull_up, Output_push_pull); // uart2 rx
		AF_Select_pin_Fun(PORTA, pin3, AF_UART1_3);
	//	DIO_voidSetPinSpeed(PORTA, pin3,Very_high_speed );


		DIO_voidSetPinDirection(PORTB, pin11, AF, No_pull_up, Output_push_pull); // uart3 rx
		AF_Select_pin_Fun(PORTB, pin11, AF_UART1_3);
	//	DIO_voidSetPinSpeed(PORTB, pin11,Very_high_speed );



/********************************************/

	u8 receive_data=0;
	UART_Init(2);
	UART_Send_byte(2, 'A');
	u8 send[10]="ahmed";
	UART_Send_Arr(2,send);
	u8 rec[10]={0};
	u8 x=0;
	while(1)
	{
		//UART_Receive_byte(2, &receive_data);
		//UART_Send_byte(2,receive_data);

		UART_Receive_Arr(2, rec);
		UART_Send_Arr(2,rec);
		if (receive_data=='A')
			{
			x^=1;
			if(x)
			GPIO_V_Set_Pin_value(PinD_13_High);

			else
				GPIO_V_Set_Pin_value(PinD_13_Low);
			}
	}
}

#endif
