/*
 * UART_Config.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Ahmed Nour
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*select the boud_rate
 * u can choose */

/*write number use of system clk u write as example 8
 * this means it 8 Mh/s*/
#define	write_no		8
#define UART_boudrate	9600



/* u can choose between
 * sample_16 or sample_8
 *
 * Oversampling by 8 is not available in the Smartcard, IrDA and LIN modes: when
SCEN=1,IREN=1 or LINEN=1 then OVER8 is forced to ‘0 by hardware */

#define 	oversampling_mode	sample_16

/* set the data length :
 *  choose between data_8 or  data_9 */

#define 	Word_length			data_8

/* Enable parity or Disable */

#define 	parity 	Disable
/*if select parity enable u can shoose between:
 *  parity_Even
 *  parity_Odd */

#define 	parity_type		parity_Even

/* use to configer the stop bits u can choose from :
 *  Stop_bit_1
 *  Stop_bit_half
 *  Stop_bit_2
 *  Stop_bit_one_half */

#define stop_bit_conf	Stop_bit_2

#endif /* UART_CONFIG_H_ */


