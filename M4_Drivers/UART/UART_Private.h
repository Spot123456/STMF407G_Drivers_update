/*
 * UART_Private.h
 *
 *  Created on: Feb 28, 2024
 *      Author: yahia
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_




#define UART1_BASEAddress  (0x40011000)
#define UART2_BASEAddress  (0x40004400)
#define UART3_BASEAddress  (0x40004800)
#define UART4_BASEAddress  (0x40004C00)
#define UART5_BASEAddress  (0x40005000)
#define UART6_BASEAddress  (0x40011400)

typedef struct
{
    u32 USART_SR;
    u32 USART_DR;
    u32 USART_BRR;
    u32 USART_CR1;
    u32 USART_CR2;
    u32 USART_CR3;
    u32 USART_GTPR;
} UART_ST;

// Define an array of pointers to UART_ST structures
static UART_ST* UART_Regs[] = {
    (UART_ST*)(UART1_BASEAddress),
    (UART_ST*)(UART2_BASEAddress),
    (UART_ST*)(UART3_BASEAddress),
    (UART_ST*)(UART4_BASEAddress),
    (UART_ST*)(UART5_BASEAddress),
    (UART_ST*)(UART6_BASEAddress)
};


/* private config */
#define	sample_16		0
#define sample_8		1

#define data_8			0
#define data_9			1

#define Enable			1
#define Disable			0

#define parity_Even		0
#define parity_Odd		1

/*the config of stop bits */
#define Stop_bit_1			0b00
#define Stop_bit_half		0b01
#define Stop_bit_2			2
#define Stop_bit_one_half	3


/* for config the boud rate of uart (note i use 16 sample for test )*/
#define system_clk		write_no
#define UART_Clk			(((system_clk*1000000)/(UART_boudrate))/(16))
#define DIV_Fraction	(u32)(((UART_Clk)-(u32)UART_Clk)*16)



#endif /* UART_PRIVATE_H_ */
