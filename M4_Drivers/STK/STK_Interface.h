/*
 * STK_Interface.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Ahmed Nour Eldin Hassan
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void	STK_Void_Init();
void	STK_voidSetBusyWait(u32	Ticks);
void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void));
void	STK_voidStopInterval();
u32		STK_u32GetElapsedTime();
u32		STK_u32GetRemainingTime();



#endif /* STK_INTERFACE_H_ */
