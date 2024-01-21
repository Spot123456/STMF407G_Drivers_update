/*
 * RCC_Private.h
 *
 *  Created on: Dec 29, 2023
 *      Author: Ahmed Nour
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* base address and name of register */
#define		RCC_BASEADD			(0x40023800)

typedef struct
{
	u32 RCC_CR;
	u32	RCC_PLLCFGR;
	u32	RCC_CFGR;
	u32	RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32	RCC_AHB2RSTR;
	u32	RCC_AHB3RSTR;
	u32	res;
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32	res1;
	u32	res2;
	u32	RCC_AHB1ENR;
	u32	RCC_AHB2ENR;
	u32	RCC_AHB3ENR;
	u32	res3;
	u32 RCC_APB1ENR;
	u32 RCC_APB2ENR;
	u32	res4;
	u32	res5;
	u32	RCC_AHB1LPENR;
	u32	RCC_AHB2LPENR;
	u32	RCC_AHB3LPENR;
	u32	res6;
	u32	RCC_APB1LPENR;
	u32	RCC_APB2LPENR;
	u32	res7;
	u32	res8;
	u32 RCC_BDCR;
	u32 RCC_CSR;
	u32	res9;
	u32	res10;
	u32 RCC_SSCGR;
	u32 RCC_PLLI2SCFGR;

}RCC_ST;

#define 	RCC_Reg		((RCC_ST*)(RCC_BASEADD))

/************************************************************************************/

/* main buses(CLK) in MC */
#define	 	RCC_HSI		0
#define		RCC_HSE		1
#define		RCC_PLL		2
/* sec CLK in MC use for external WDT or RTC */
#define 	RCC_LSI		3
#define		RCC_LSE		4

/* PLL Input CLK */
#define 	PLL_HSI		0
#define 	PLL_HSE		1

/* for clk interrupt */
#define 	RCC_Polling		0
#define 	RCC_Interrupt 	1


/* for AHB Prescaler */
#define 	AHB_NoPre		0
#define 	AHB_pre_2		8
#define 	AHB_Pre_4		9
#define		AHB_Pre_8		10
#define		AHB_Pre_16		11
#define 	AHB_Pre_64		12
#define 	AHB_Pre_128		13
#define 	AHB_Pre_256		14
#define 	AHB_Pre_512		15

#define 	AHB_Pre_Mask	0b1111

/* APB1& APB2 prescaler
 * it depends on AHB CLK
 * for APB1 CLK don't exceed 42Mhz
 * for APB2 CLK don't exceed 84MHZ
 * prescaler depends on AHB bus / 2 ,4,8,16
 * */

#define 	APB_AHB_NOPre		0
#define 	APB_AHB_2			4
#define 	APB_AHB_4			5
#define 	APB_AHB_8			6
#define 	APB_AHB_16			7

#define 	APB_Mask			0b111









#endif /* RCC_PRIVATE_H_ */
