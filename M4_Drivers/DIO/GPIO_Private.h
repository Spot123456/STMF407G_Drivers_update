/*
 * GPIO_Private.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Ahmed Nour
 */
/*
 * GPIO main features :
 * Output states: push-pull or open drain + pull-up/down
 * Input states: floating, pull-up/down, analog
 * Speed selection for each I/O
 * Fast toggle capable of changing every two clock cycles
 * */
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define 	GPIOA_BaseAdd			(0x40020000)
#define 	GPIOB_BaseAdd			(0x40020400)
#define 	GPIOC_BaseAdd			(0x40020800)
#define 	GPIOD_BaseAdd			(0x40020C00)
#define 	GPIOE_BaseAdd			(0x40021000)
#define 	GPIOF_BaseAdd			(0x40021400)
#define 	GPIOG_BaseAdd			(0x40021800)

typedef struct
{
	u32		GPIOx_MODER;  /* note GPIOA & B have defferent init value ie(Reg not = 0 */
	u32		GPIOx_OTYPER;
	u32		GPIOx_OSPEEDR; /*GPIOB is the only different*/
	u32		GPIOx_PUPDR; /*A&B diff*/
	u32		GPIOx_IDR;
	u32		GPIOx_ODR;
	u32		GPIOx_BSRR;
	u32		GPIOx_LCKR;
	u32		GPIOx_AFRL;
	u32		GPIOx_AFRH;
}GPIO_ST;

#define		GPIOA_Reg 	((GPIO_ST*)(GPIOA_BaseAdd))
#define 	GPIOB_Reg	((GPIO_ST*)(GPIOB_BaseAdd))
#define		GPIOC_Reg 	((GPIO_ST*)(GPIOC_BaseAdd))
#define 	GPIOD_Reg	((GPIO_ST*)(GPIOD_BaseAdd))
#define		GPIOE_Reg 	((GPIO_ST*)(GPIOE_BaseAdd))
#define 	GPIOF_Reg	((GPIO_ST*)(GPIOF_BaseAdd))
#define		GPIOG_Reg 	((GPIO_ST*))(GPIOG_BaseAdd))


/*	GPIO State Private*/
#define		GPIO_input		00
#define		GPIO_output		01
#define		GPIO_AF			10
#define 	GPIO_Analog		11

/* GPIO port output type register */

#define  Output_push_pull	 	0
#define  Output_open_drain		1


/* Private Calc */

#define 	GPIO_Check			16
#define 	PORTA				0
#define 	PORTB				1
#define 	PORTC				2
#define 	PORTD				3
#define 	PIN_Shifting_Low	16 	/* it is the sec half of register */


/*GPIO PORT PUll_up / Pull Down reg*/
#define 	No_Pull_up		00
#define		Pull_up			01
#define 	Pull_down		10


/* ALternative function pins declaration */


#define 	AF_system				0000
#define		AF_T1_T2				0001
#define 	AF_T3_T4_T5				0010
#define 	AF_T8_T9_T10_T11		0011
#define 	AF_I2C_All				0100
#define 	AF_SPI_1_2				0101
#define 	AF_SPI_3				0110
#define 	AF_UART_1_2_3			0111
#define 	AF_UART_4_5_6			1000
#define 	AF_CAN_1_2				1001
#define 	AF_T_12_13_14			1001 // the same
#define		AF_OTG_FS_HS			1010
#define 	AF_ETH					1011
#define 	AF_FSMC					1100
#define 	AF_SDIO					1100	// same
#define 	AF_OTG_HS_1				1100	// same
#define		AF_DCMI					1101
#define		AF_EVENTOUT				1111











/* concat  */

#define		CONCAT(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)	CONCAT_Helper(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define 	CONCAT_Helper(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) 0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define  	CON_Half_Port(b7,b6,b5,b4,b3,b2,b1,b0)				CON_Half_Port_Helper(b7,b6,b5,b4,b3,b2,b1,b0)
#define  	CON_Half_Port_Helper(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

/* concat Port state */
#define 	GPIOA_State		CONCAT(GPIOA_State_Pin15,GPIOA_State_Pin14,GPIOA_State_Pin13,GPIOA_State_Pin12,GPIOA_State_Pin11,GPIOA_State_Pin10,GPIOA_State_Pin9,GPIOA_State_Pin8,GPIOA_State_Pin7,GPIOA_State_Pin6,GPIOA_State_Pin5,GPIOA_State_Pin4,GPIOA_State_Pin3,GPIOA_State_Pin2,GPIOA_State_Pin1,GPIOA_State_Pin0)
#define 	GPIOB_State		CONCAT(GPIOB_State_Pin15,GPIOB_State_Pin14,GPIOB_State_Pin13,GPIOB_State_Pin12,GPIOB_State_Pin11,GPIOB_State_Pin10,GPIOB_State_Pin9,GPIOB_State_Pin8,GPIOB_State_Pin7,GPIOB_State_Pin6,GPIOB_State_Pin5,GPIOB_State_Pin4,GPIOB_State_Pin3,GPIOB_State_Pin2,GPIOB_State_Pin1,GPIOB_State_Pin0)
#define 	GPIOC_State		CONCAT(GPIOC_State_Pin15,GPIOC_State_Pin14,GPIOC_State_Pin13,GPIOC_State_Pin12,GPIOC_State_Pin11,GPIOC_State_Pin10,GPIOC_State_Pin9,GPIOC_State_Pin8,GPIOC_State_Pin7,GPIOC_State_Pin6,GPIOC_State_Pin5,GPIOC_State_Pin4,GPIOC_State_Pin3,GPIOC_State_Pin2,GPIOC_State_Pin1,GPIOC_State_Pin0)
#define 	GPIOD_State		CONCAT(GPIOD_State_Pin15,GPIOD_State_Pin14,GPIOD_State_Pin13,GPIOD_State_Pin12,GPIOD_State_Pin11,GPIOD_State_Pin10,GPIOD_State_Pin9,GPIOD_State_Pin8,GPIOD_State_Pin7,GPIOD_State_Pin6,GPIOD_State_Pin5,GPIOD_State_Pin4,GPIOD_State_Pin3,GPIOD_State_Pin2,GPIOD_State_Pin1,GPIOD_State_Pin0)
#define 	GPIOE_State		CONCAT(GPIOE_State_Pin15,GPIOE_State_Pin14,GPIOE_State_Pin13,GPIOE_State_Pin12,GPIOE_State_Pin11,GPIOE_State_Pin10,GPIOE_State_Pin9,GPIOE_State_Pin8,GPIOE_State_Pin7,GPIOE_State_Pin6,GPIOE_State_Pin5,GPIOE_State_Pin4,GPIOE_State_Pin3,GPIOE_State_Pin2,GPIOE_State_Pin1,GPIOE_State_Pin0)

/* concat Port output type register */
#define 	GPIOA_output_type		CONCAT(GPIOA_output_type_Pin15,GPIOA_output_type_Pin14,GPIOA_output_type_Pin13,GPIOA_output_type_Pin12,GPIOA_output_type_Pin11,GPIOA_output_type_Pin10,GPIOA_output_type_Pin9,GPIOA_output_type_Pin8,GPIOA_output_type_Pin7,GPIOA_output_type_Pin6,GPIOA_output_type_Pin5,GPIOA_output_type_Pin4,GPIOA_output_type_Pin3,GPIOA_output_type_Pin2,GPIOA_output_type_Pin1,GPIOA_output_type_Pin0)
#define 	GPIOB_output_type		CONCAT(GPIOB_output_type_Pin15,GPIOB_output_type_Pin14,GPIOB_output_type_Pin13,GPIOB_output_type_Pin12,GPIOB_output_type_Pin11,GPIOB_output_type_Pin10,GPIOB_output_type_Pin9,GPIOB_output_type_Pin8,GPIOB_output_type_Pin7,GPIOB_output_type_Pin6,GPIOB_output_type_Pin5,GPIOB_output_type_Pin4,GPIOB_output_type_Pin3,GPIOB_output_type_Pin2,GPIOB_output_type_Pin1,GPIOB_output_type_Pin0)
#define 	GPIOC_output_type		CONCAT(GPIOC_output_type_Pin15,GPIOC_output_type_Pin14,GPIOC_output_type_Pin13,GPIOC_output_type_Pin12,GPIOC_output_type_Pin11,GPIOC_output_type_Pin10,GPIOC_output_type_Pin9,GPIOC_output_type_Pin8,GPIOC_output_type_Pin7,GPIOC_output_type_Pin6,GPIOC_output_type_Pin5,GPIOC_output_type_Pin4,GPIOC_output_type_Pin3,GPIOC_output_type_Pin2,GPIOC_output_type_Pin1,GPIOC_output_type_Pin0)
#define 	GPIOD_output_type		CONCAT(GPIOD_output_type_Pin15,GPIOD_output_type_Pin14,GPIOD_output_type_Pin13,GPIOD_output_type_Pin12,GPIOD_output_type_Pin11,GPIOD_output_type_Pin10,GPIOD_output_type_Pin9,GPIOD_output_type_Pin8,GPIOD_output_type_Pin7,GPIOD_output_type_Pin6,GPIOD_output_type_Pin5,GPIOD_output_type_Pin4,GPIOD_output_type_Pin3,GPIOD_output_type_Pin2,GPIOD_output_type_Pin1,GPIOD_output_type_Pin0)

/* concat port Pull up / down register */
#define 	GPIOA_Pull_Up_Down		CONCAT(GPIOA_Pull_Up_Down_Pin15,GPIOA_Pull_Up_Down_Pin14,GPIOA_Pull_Up_Down_Pin13,GPIOA_Pull_Up_Down_Pin12,GPIOA_Pull_Up_Down_Pin11,GPIOA_Pull_Up_Down_Pin10,GPIOA_Pull_Up_Down_Pin9,GPIOA_Pull_Up_Down_Pin8,GPIOA_Pull_Up_Down_Pin7,GPIOA_Pull_Up_Down_Pin6,GPIOA_Pull_Up_Down_Pin5,GPIOA_Pull_Up_Down_Pin4,GPIOA_Pull_Up_Down_Pin3,GPIOA_Pull_Up_Down_Pin2,GPIOA_Pull_Up_Down_Pin1,GPIOA_Pull_Up_Down_Pin0)
#define 	GPIOB_Pull_Up_Down		CONCAT(GPIOB_Pull_Up_Down_Pin15,GPIOB_Pull_Up_Down_Pin14,GPIOB_Pull_Up_Down_Pin13,GPIOB_Pull_Up_Down_Pin12,GPIOB_Pull_Up_Down_Pin11,GPIOB_Pull_Up_Down_Pin10,GPIOB_Pull_Up_Down_Pin9,GPIOB_Pull_Up_Down_Pin8,GPIOB_Pull_Up_Down_Pin7,GPIOB_Pull_Up_Down_Pin6,GPIOB_Pull_Up_Down_Pin5,GPIOB_Pull_Up_Down_Pin4,GPIOB_Pull_Up_Down_Pin3,GPIOB_Pull_Up_Down_Pin2,GPIOB_Pull_Up_Down_Pin1,GPIOB_Pull_Up_Down_Pin0)
#define 	GPIOC_Pull_Up_Down		CONCAT(GPIOC_Pull_Up_Down_Pin15,GPIOC_Pull_Up_Down_Pin14,GPIOC_Pull_Up_Down_Pin13,GPIOC_Pull_Up_Down_Pin12,GPIOC_Pull_Up_Down_Pin11,GPIOC_Pull_Up_Down_Pin10,GPIOC_Pull_Up_Down_Pin9,GPIOC_Pull_Up_Down_Pin8,GPIOC_Pull_Up_Down_Pin7,GPIOC_Pull_Up_Down_Pin6,GPIOC_Pull_Up_Down_Pin5,GPIOC_Pull_Up_Down_Pin4,GPIOC_Pull_Up_Down_Pin3,GPIOC_Pull_Up_Down_Pin2,GPIOC_Pull_Up_Down_Pin1,GPIOC_Pull_Up_Down_Pin0)
#define 	GPIOD_Pull_Up_Down		CONCAT(GPIOD_Pull_Up_Down_Pin15,GPIOD_Pull_Up_Down_Pin14,GPIOD_Pull_Up_Down_Pin13,GPIOD_Pull_Up_Down_Pin12,GPIOD_Pull_Up_Down_Pin11,GPIOD_Pull_Up_Down_Pin10,GPIOD_Pull_Up_Down_Pin9,GPIOD_Pull_Up_Down_Pin8,GPIOD_Pull_Up_Down_Pin7,GPIOD_Pull_Up_Down_Pin6,GPIOD_Pull_Up_Down_Pin5,GPIOD_Pull_Up_Down_Pin4,GPIOD_Pull_Up_Down_Pin3,GPIOD_Pull_Up_Down_Pin2,GPIOD_Pull_Up_Down_Pin1,GPIOD_Pull_Up_Down_Pin0)

/* concat alternative functions register */
#define		AFIOA_set_High				CON_Half_Port(AFIOA_set_pin8,AFIOA_set_pin9,AFIOA_set_pin10,AFIOA_set_pin11,AFIOA_set_pin12,AFIOA_set_pin13,AFIOA_set_pin14,AFIOA_set_pin15)
#define		AFIOB_set_High				CON_Half_Port(AFIOB_set_pin8,AFIOB_set_pin9,AFIOB_set_pin10,AFIOB_set_pin11,AFIOB_set_pin12,AFIOB_set_pin13,AFIOB_set_pin14,AFIOB_set_pin15)
#define		AFIOC_set_High				CON_Half_Port(AFIOC_set_pin8,AFIOC_set_pin9,AFIOC_set_pin10,AFIOC_set_pin11,AFIOC_set_pin12,AFIOC_set_pin13,AFIOC_set_pin14,AFIOC_set_pin15)
#define		AFIOD_set_High				CON_Half_Port(AFIOD_set_pin8,AFIOD_set_pin9,AFIOD_set_pin10,AFIOD_set_pin11,AFIOD_set_pin12,AFIOD_set_pin13,AFIOD_set_pin14,AFIOD_set_pin15)

#define		AFIOA_set_Low				CON_Half_Port(AFIOA_set_pin0,AFIOA_set_pin1,AFIOA_set_pin2,AFIOA_set_pin3,AFIOA_set_pin4,AFIOA_set_pin5,AFIOA_set_pin6,AFIOA_set_pin7)
#define		AFIOB_set_Low				CON_Half_Port(AFIOB_set_pin0,AFIOB_set_pin1,AFIOB_set_pin2,AFIOB_set_pin3,AFIOB_set_pin4,AFIOB_set_pin5,AFIOB_set_pin6,AFIOB_set_pin7)
#define		AFIOC_set_Low				CON_Half_Port(AFIOC_set_pin0,AFIOC_set_pin1,AFIOC_set_pin2,AFIOC_set_pin3,AFIOC_set_pin4,AFIOC_set_pin5,AFIOC_set_pin6,AFIOC_set_pin7)
#define		AFIOD_set_Low				CON_Half_Port(AFIOD_set_pin0,AFIOD_set_pin1,AFIOD_set_pin2,AFIOD_set_pin3,AFIOD_set_pin4,AFIOD_set_pin5,AFIOD_set_pin6,AFIOD_set_pin7)


#endif /* GPIO_PRIVATE_H_ */











