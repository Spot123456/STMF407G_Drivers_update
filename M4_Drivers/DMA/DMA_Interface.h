/*
 * DMA_Interface.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Ahmed nour
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA2_init(u8 stream , u8 DMA_Mode ,u8 channel,u8 from_to  );
void DMA2_select_channel(u8 channel,u32 *send_to,u32 *receive_from,u32 *receive_from2_double , u16 total_transfer);

void DMA2_SW_change_periority(u8 channel ,u8 periority );

void DMA2_SetcallBack(void (*notification) (void) , u8 number_of_stream);

#endif /* DMA_INTERFACE_H_ */
