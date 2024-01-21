/*
 * RCC_Interface.h
 *
 *  Created on: Dec 29, 2023
 *     Author: Ahmed Nour
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "ERROR_Type.h"

void RCC_V_InitCLK();
void RCC_V_EnablePer(u8 peripheral,u8 Bus_ID);
EN_Error_t RCC_V_DisablePer(u8 peripheral,u8 Bus_ID);
EN_Error_t RCC_V_EnablePerLowPower(u8 peripheral,u8 Bus_ID);
void RCC_V_SetCallBack(void(*Notification)(void));

#define 	RCC_AHB1			0
#define 	RCC_AHB2			1
#define 	RCC_AHB3			2
#define 	RCC_APB1			3
#define 	RCC_APB2			4


/* for AHB1 */

#define		RCC_GPIOA		0
#define 	RCC_GPIOB		1
#define 	RCC_GPIOC		2
#define 	RCC_GPIOD		3
#define 	RCC_GPIOE		4
#define 	RCC_GPIOF		5
#define 	RCC_GPIOG		6
#define 	RCC_GPIOH		7
#define 	RCC_GPIOI		8
#define 	RCC_CRCR		12
#define 	RCC_DMA1		21
#define 	RCC_DMA2		22
#define 	RCC_ETHMAC		25
#define 	RCC_OTGHS		29

/* for AHB2 */

#define 	RCC_OTGFS		7
#define 	RCC_ RNG		6
#define 	RCC_HASH		5
#define 	RCC_CRYP		4
#define 	RCC_DCMI		0

/* for AHB3 */

#define 	RCC_FSMC		0





#endif /* RCC_INTERFACE_H_ */



