/*
 * DMA_Private.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Ahmed nour
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA1_BaseAddress	(0x40026000)
#define DMA2_BaseAddress	(0x40026400)

typedef struct
{
	u32	DMA_SCR		;
	u32	DMA_SNDTR	;
	u32	DMA_SPAR	;
	u32	DMA_SM0AR	;
	u32	DMA_SM1AR	;
	u32	DMA_SFCR	;
}DMA_Channel;



typedef struct
{
	u32 DMA_LISR;
	u32	DMA_HISR;
	u32	DMA_LIFCR;
	u32	DMA_HIFCR;
	DMA_Channel channel[7];
}DMA_ST;

#define DMA1_Reg	((DMA_ST*)(DMA1_BaseAddress))
#define DMA2_Reg	((DMA_ST*)(DMA2_BaseAddress))

/*private variable */
/* brust data*/

#define single_brust	00
#define data4_brust		1
#define data8_brust		2
#define data16_brust	3


/**/
#define Pre_To_Arr			0
#define Arr_To_Pre			1
#define Arr_To_Arr			2
#define Pre_To_Pre			3
#define const_To_Const		4
#define const_To_Arr		5

/* dma mode */
#define circular 		0
#define direct			1

/* select FIFO Threshold*/
#define  	Quarter_FIFO			0
#define  	Half_FIFO				1
#define		Three_Quarter_FIFO		2
#define  	Full_FIFO				3



#endif /* DMA_PRIVATE_H_ */
