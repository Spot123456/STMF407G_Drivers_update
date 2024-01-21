/*
 * GPIO_Config.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Ahmed Nour
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/* Pin Config State:		select
 * 1- input					GPIO_input
 * 2- GPIO Output			GPIO_output
 * 3- Alternate Fun			GPIO_AF
 * 4- Analog				GPIO_Analog
 *
 * */

/* GPIOA */
#define		GPIOA_State_Pin0 		GPIO_input
#define		GPIOA_State_Pin1 		GPIO_input
#define		GPIOA_State_Pin2 		GPIO_input
#define		GPIOA_State_Pin3 		GPIO_input
#define		GPIOA_State_Pin4 		GPIO_input
#define		GPIOA_State_Pin5 		GPIO_input
#define		GPIOA_State_Pin6 		GPIO_input
#define		GPIOA_State_Pin7 		GPIO_input
#define		GPIOA_State_Pin8 		GPIO_input
#define		GPIOA_State_Pin9 		GPIO_input
#define		GPIOA_State_Pin10 		GPIO_input
#define		GPIOA_State_Pin11		GPIO_input
#define		GPIOA_State_Pin12 		GPIO_input
#define		GPIOA_State_Pin13		GPIO_input
#define		GPIOA_State_Pin14		GPIO_input
#define		GPIOA_State_Pin15		GPIO_input

/* GPIOB */
#define		GPIOB_State_Pin0 		GPIO_input
#define		GPIOB_State_Pin1 		GPIO_input
#define		GPIOB_State_Pin2 		GPIO_input
#define		GPIOB_State_Pin3 		GPIO_input
#define		GPIOB_State_Pin4 		GPIO_input
#define		GPIOB_State_Pin5 		GPIO_input
#define		GPIOB_State_Pin6 		GPIO_input
#define		GPIOB_State_Pin7 		GPIO_input
#define		GPIOB_State_Pin8 		GPIO_input
#define		GPIOB_State_Pin9 		GPIO_input
#define		GPIOB_State_Pin10 		GPIO_input
#define		GPIOB_State_Pin11		GPIO_input
#define		GPIOB_State_Pin12 		GPIO_input
#define		GPIOB_State_Pin13		GPIO_input
#define		GPIOB_State_Pin14		GPIO_input
#define		GPIOB_State_Pin15		GPIO_input

/* GPIOC */
#define		GPIOC_State_Pin0 		GPIO_input
#define		GPIOC_State_Pin1 		GPIO_input
#define		GPIOC_State_Pin2 		GPIO_input
#define		GPIOC_State_Pin3 		GPIO_input
#define		GPIOC_State_Pin4 		GPIO_input
#define		GPIOC_State_Pin5 		GPIO_input
#define		GPIOC_State_Pin6 		GPIO_input
#define		GPIOC_State_Pin7 		GPIO_input
#define		GPIOC_State_Pin8 		GPIO_input
#define		GPIOC_State_Pin9 		GPIO_input
#define		GPIOC_State_Pin10 		GPIO_input
#define		GPIOC_State_Pin11		GPIO_input
#define		GPIOC_State_Pin12 		GPIO_input
#define		GPIOC_State_Pin13		GPIO_input
#define		GPIOC_State_Pin14		GPIO_input
#define		GPIOC_State_Pin15		GPIO_input

/* GPIOD */
#define		GPIOD_State_Pin0 	GPIO_input
#define		GPIOD_State_Pin1 	GPIO_input
#define		GPIOD_State_Pin2 	GPIO_input
#define		GPIOD_State_Pin3 	GPIO_input
#define		GPIOD_State_Pin4 	GPIO_input
#define		GPIOD_State_Pin5 	GPIO_input
#define		GPIOD_State_Pin6 	GPIO_input
#define		GPIOD_State_Pin7 	GPIO_input
#define		GPIOD_State_Pin8 	GPIO_input
#define		GPIOD_State_Pin9 	GPIO_input
#define		GPIOD_State_Pin10 	GPIO_input
#define		GPIOD_State_Pin11	GPIO_input
#define		GPIOD_State_Pin12 	GPIO_input
#define		GPIOD_State_Pin13	GPIO_input
#define		GPIOD_State_Pin14	GPIO_input
#define		GPIOD_State_Pin15	GPIO_input

/* GPIOE */
#define		GPIOE_State_Pin0 	GPIO_input
#define		GPIOE_State_Pin1 	GPIO_input
#define		GPIOE_State_Pin2 	GPIO_input
#define		GPIOE_State_Pin3 	GPIO_input
#define		GPIOE_State_Pin4 	GPIO_input
#define		GPIOE_State_Pin5 	GPIO_input
#define		GPIOE_State_Pin6 	GPIO_input
#define		GPIOE_State_Pin7 	GPIO_input
#define		GPIOE_State_Pin8 	GPIO_input
#define		GPIOE_State_Pin9 	GPIO_input
#define		GPIOE_State_Pin10 	GPIO_input
#define		GPIOE_State_Pin11	GPIO_input
#define		GPIOE_State_Pin12 	GPIO_input
#define		GPIOE_State_Pin13	GPIO_input
#define		GPIOE_State_Pin14	GPIO_input
#define		GPIOE_State_Pin15	GPIO_input

/* GPIOF */
#define		GPIOF_State_Pin0 	GPIO_input
#define		GPIOF_State_Pin1 	GPIO_input
#define		GPIOF_State_Pin2 	GPIO_input
#define		GPIOF_State_Pin3 	GPIO_input
#define		GPIOF_State_Pin4 	GPIO_input
#define		GPIOF_State_Pin5 	GPIO_input
#define		GPIOF_State_Pin6 	GPIO_input
#define		GPIOF_State_Pin7 	GPIO_input
#define		GPIOF_State_Pin8 	GPIO_input
#define		GPIOF_State_Pin9 	GPIO_input
#define		GPIOF_State_Pin10 	GPIO_input
#define		GPIOF_State_Pin11	GPIO_input
#define		GPIOF_State_Pin12 	GPIO_input
#define		GPIOF_State_Pin13	GPIO_input
#define		GPIOF_State_Pin14	GPIO_input
#define		GPIOF_State_Pin15	GPIO_input

/*****************************************************************************************************/

/* GPIO port output type register :
 * Output_push_pull	 (reset state)
 * Output_open-drain
 */

/* GPIOA */
#define		GPIOA_output_type_Pin0	 			Output_push_pull
#define		GPIOA_output_type_Pin1 				Output_push_pull
#define		GPIOA_output_type_Pin2 				Output_push_pull
#define		GPIOA_output_type_Pin3				Output_push_pull
#define		GPIOA_output_type_Pin4 				Output_push_pull
#define		GPIOA_output_type_Pin5				Output_push_pull
#define		GPIOA_output_type_Pin6 			Output_push_pull
#define		GPIOA_output_type_Pin7 			Output_push_pull
#define		GPIOA_output_type_Pin8 			Output_push_pull
#define		GPIOA_output_type_Pin9 			Output_push_pull
#define		GPIOA_output_type_Pin10 			Output_push_pull
#define		GPIOA_output_type_Pin11				Output_push_pull
#define		GPIOA_output_type_Pin12 			Output_push_pull
#define		GPIOA_output_type_Pin13			Output_push_pull
#define		GPIOA_output_type_Pin14			Output_push_pull
#define		GPIOA_output_type_Pin15			Output_push_pull

/* GPIOB */
#define		GPIOB_output_type_Pin0	 			Output_push_pull
#define		GPIOB_output_type_Pin1 				Output_push_pull
#define		GPIOB_output_type_Pin2 				Output_push_pull
#define		GPIOB_output_type_Pin3				Output_push_pull
#define		GPIOB_output_type_Pin4 				Output_push_pull
#define		GPIOB_output_type_Pin5				Output_push_pull
#define		GPIOB_output_type_Pin6 			Output_push_pull
#define		GPIOB_output_type_Pin7 			Output_push_pull
#define		GPIOB_output_type_Pin8 			Output_push_pull
#define		GPIOB_output_type_Pin9 			Output_push_pull
#define		GPIOB_output_type_Pin10 			Output_push_pull
#define		GPIOB_output_type_Pin11				Output_push_pull
#define		GPIOB_output_type_Pin12 			Output_push_pull
#define		GPIOB_output_type_Pin13			Output_push_pull
#define		GPIOB_output_type_Pin14			Output_push_pull
#define		GPIOB_output_type_Pin15			Output_push_pull

/* GPIOC */
#define		GPIOC_output_type_Pin0	 			Output_push_pull
#define		GPIOC_output_type_Pin1 			Output_push_pull
#define		GPIOC_output_type_Pin2 			Output_push_pull
#define		GPIOC_output_type_Pin3				Output_push_pull
#define		GPIOC_output_type_Pin4 				Output_push_pull
#define		GPIOC_output_type_Pin5				Output_push_pull
#define		GPIOC_output_type_Pin6 			Output_push_pull
#define		GPIOC_output_type_Pin7 			Output_push_pull
#define		GPIOC_output_type_Pin8 			Output_push_pull
#define		GPIOC_output_type_Pin9 			Output_push_pull
#define		GPIOC_output_type_Pin10 			Output_push_pull
#define		GPIOC_output_type_Pin11				Output_push_pull
#define		GPIOC_output_type_Pin12 			Output_push_pull
#define		GPIOC_output_type_Pin13			Output_push_pull
#define		GPIOC_output_type_Pin14			Output_push_pull
#define		GPIOC_output_type_Pin15			Output_push_pull

/* GPIOD */
#define		GPIOD_output_type_Pin0	 			Output_push_pull
#define		GPIOD_output_type_Pin1 			Output_push_pull
#define		GPIOD_output_type_Pin2 			Output_push_pull
#define		GPIOD_output_type_Pin3				Output_push_pull
#define		GPIOD_output_type_Pin4 				Output_push_pull
#define		GPIOD_output_type_Pin5				Output_push_pull
#define		GPIOD_output_type_Pin6 			Output_push_pull
#define		GPIOD_output_type_Pin7 			Output_push_pull
#define		GPIOD_output_type_Pin8 			Output_push_pull
#define		GPIOD_output_type_Pin9 			Output_push_pull
#define		GPIOD_output_type_Pin10 			Output_push_pull
#define		GPIOD_output_type_Pin11				Output_push_pull
#define		GPIOD_output_type_Pin12 			Output_push_pull
#define		GPIOD_output_type_Pin13			Output_push_pull
#define		GPIOD_output_type_Pin14			Output_push_pull
#define		GPIOD_output_type_Pin15			Output_push_pull

/*******************************************************************************/

/*GPIO port pull-up/pull-down register (GPIOx_PUPDR)
 * No pull-up( pull-down)
 * Pull-up
 * Pull-down
 * */

/* GPIOA */

#define		GPIOA_Pull_Up_Down_Pin0				Pull_up
#define		GPIOA_Pull_Up_Down_Pin1				Pull_up
#define		GPIOA_Pull_Up_Down_Pin2				Pull_up
#define		GPIOA_Pull_Up_Down_Pin3				Pull_up
#define		GPIOA_Pull_Up_Down_Pin4				Pull_up
#define		GPIOA_Pull_Up_Down_Pin5				Pull_up
#define		GPIOA_Pull_Up_Down_Pin6				Pull_up
#define		GPIOA_Pull_Up_Down_Pin7				Pull_up
#define		GPIOA_Pull_Up_Down_Pin8				Pull_up
#define		GPIOA_Pull_Up_Down_Pin9				Pull_up
#define		GPIOA_Pull_Up_Down_Pin10			Pull_up
#define		GPIOA_Pull_Up_Down_Pin11			Pull_up
#define		GPIOA_Pull_Up_Down_Pin12			Pull_up
#define		GPIOA_Pull_Up_Down_Pin13			Pull_up
#define		GPIOA_Pull_Up_Down_Pin14			Pull_up
#define		GPIOA_Pull_Up_Down_Pin15			Pull_up

/* GPIOB */

#define		GPIOB_Pull_Up_Down_Pin0				Pull_up
#define		GPIOB_Pull_Up_Down_Pin1				Pull_up
#define		GPIOB_Pull_Up_Down_Pin2				Pull_up
#define		GPIOB_Pull_Up_Down_Pin3				Pull_up
#define		GPIOB_Pull_Up_Down_Pin4				Pull_up
#define		GPIOB_Pull_Up_Down_Pin5				Pull_up
#define		GPIOB_Pull_Up_Down_Pin6				Pull_up
#define		GPIOB_Pull_Up_Down_Pin7				Pull_up
#define		GPIOB_Pull_Up_Down_Pin8				Pull_up
#define		GPIOB_Pull_Up_Down_Pin9				Pull_up
#define		GPIOB_Pull_Up_Down_Pin10			Pull_up
#define		GPIOB_Pull_Up_Down_Pin11			Pull_up
#define		GPIOB_Pull_Up_Down_Pin12			Pull_up
#define		GPIOB_Pull_Up_Down_Pin13			Pull_up
#define		GPIOB_Pull_Up_Down_Pin14			Pull_up
#define		GPIOB_Pull_Up_Down_Pin15			Pull_up

/* GPIOC */

#define		GPIOC_Pull_Up_Down_Pin0				Pull_up
#define		GPIOC_Pull_Up_Down_Pin1				Pull_up
#define		GPIOC_Pull_Up_Down_Pin2				Pull_up
#define		GPIOC_Pull_Up_Down_Pin3				Pull_up
#define		GPIOC_Pull_Up_Down_Pin4				Pull_up
#define		GPIOC_Pull_Up_Down_Pin5				Pull_up
#define		GPIOC_Pull_Up_Down_Pin6				Pull_up
#define		GPIOC_Pull_Up_Down_Pin7				Pull_up
#define		GPIOC_Pull_Up_Down_Pin8				Pull_up
#define		GPIOC_Pull_Up_Down_Pin9				Pull_up
#define		GPIOC_Pull_Up_Down_Pin10			Pull_up
#define		GPIOC_Pull_Up_Down_Pin11			Pull_up
#define		GPIOC_Pull_Up_Down_Pin12			Pull_up
#define		GPIOC_Pull_Up_Down_Pin13			Pull_up
#define		GPIOC_Pull_Up_Down_Pin14			Pull_up
#define		GPIOC_Pull_Up_Down_Pin15			Pull_up

/* GPIOD */

#define		GPIOD_Pull_Up_Down_Pin0				Pull_up
#define		GPIOD_Pull_Up_Down_Pin1				Pull_up
#define		GPIOD_Pull_Up_Down_Pin2				Pull_up
#define		GPIOD_Pull_Up_Down_Pin3				Pull_up
#define		GPIOD_Pull_Up_Down_Pin4				Pull_up
#define		GPIOD_Pull_Up_Down_Pin5				Pull_up
#define		GPIOD_Pull_Up_Down_Pin6				Pull_up
#define		GPIOD_Pull_Up_Down_Pin7				Pull_up
#define		GPIOD_Pull_Up_Down_Pin8				Pull_up
#define		GPIOD_Pull_Up_Down_Pin9				Pull_up
#define		GPIOD_Pull_Up_Down_Pin10			Pull_up
#define		GPIOD_Pull_Up_Down_Pin11			Pull_up
#define		GPIOD_Pull_Up_Down_Pin12			Pull_up
#define		GPIOD_Pull_Up_Down_Pin13			Pull_up
#define		GPIOD_Pull_Up_Down_Pin14			Pull_up
#define		GPIOD_Pull_Up_Down_Pin15			Pull_up


#endif /* GPIO_CONFIG_H_ */
