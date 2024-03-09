/*
 * DMA_Config.h
 *
 *  Created on: Feb 17, 2024
 *      Author: ahmed nour
 */

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

/* u can choose from the following :
 * single_brust
 * data4_brust
 * data8_brust
 * data16_brust*/

#define  Mem_Brust_data		single_brust
#define  Pre_Brust_data		single_brust

/*in double buffer select the target to the first location or second
 * 0 for first
 * 1 for sec */

#define		CT		0

/* select DMA mode :
 *  Circular or Direct */

#define mode	Direct

/* select FIFO Threshold
 * Quarter_FIFO
 * Half_FIFO
 * Three_Quarter_FIFO
 * Full_FIFO*/

#define FIFO_threshold		Quarter_FIFO


#endif /* DMA_CONFIG_H_ */
