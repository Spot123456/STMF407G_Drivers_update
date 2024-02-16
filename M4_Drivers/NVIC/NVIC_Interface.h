/*
 * NVIC_Interface.h
 *
 *  Created on: Jan 22, 2024
 *      Author: yahia
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void		NVIC_voidInit();

void		NVIC_voidEnablePerInt(u8 NVIC_Num);
void		NVIC_voidDisablePerInt(u8 NVIC_Num);

void		NVIC_voidSetPendingFlag(u8 NVIC_Num);
void		NVIC_voidClrPendingFlag(u8 NVIC_Num);

u8			NVIC_u8ReadActiveFlag(u8 NVIC_Num);

void		NVIC_voidSetSwIntPriority(u8 NVIC_Num , u8 priority);

#endif /* NVIC_INTERFACE_H_ */
