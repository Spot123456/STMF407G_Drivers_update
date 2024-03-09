/*
 * UART_Interface.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Ahmed Nour
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(u8 UART_no);
void UART_Interrupt_Enable(u8 UART_no);
void UART_Interrupt_Disable(u8 UART_no);

EN_Error_t UART_Send_byte(u8 UART_no,u8 UART_data);
EN_Error_t UART_Send_Arr(u8 UART_no,u8* UART_Arr);

EN_Error_t UART_Receive_byte(u8 UART_no,u8 * receive_data);
EN_Error_t UART_Receive_Arr (u8 UART_no,u8* receive_arr_data);

#endif /* UART_INTERFACE_H_ */
