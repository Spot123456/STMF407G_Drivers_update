/*
 * STK_Private.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Ahmed Nour
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define STK_BaseAddress				(0xE000E010)

typedef struct
{
	u32	STK_CTRL;
	u32	STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}STK_ST;

#define STK_Reg		((STK_ST*)(STK_BaseAddress))

/* Private config */

#define AHB_Div8			0
#define AHB					1 		//processor speed(clk)
#define single_interval 	0
#define	Multi_interval		1

#endif /* STK_PRIVATE_H_ */
