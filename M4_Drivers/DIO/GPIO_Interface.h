/*
 * GPIO_Interface.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Ahmed Nour
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

void GPIO_V_PortInterface_Direction();
void GPIO_V_Config_MODE_GPIOA(u8 pin_no,u8 mode);	// config the port_A FOR: AF / OUT / IN / ANALOG
void GPIO_V_Set_Pin_value(u8 pin);
void GPIO_V_Set_Pin_Speed(u8 pin,u8 Speed);
void GPIO_V_Get_pin_Value(u8 pin,u8*value);
void GPIO_V_Toggle_pin(u8 pin);

/* pin config value
 *  pin
 *  port
 *  num
 *  value
 * */

/* PIN LOW PORT A */
#define PinA_0_Low			0
#define PinA_1_Low			1
#define PinA_2_Low			2
#define PinA_3_Low			3
#define PinA_4_Low			4
#define PinA_5_Low			5
#define PinA_6_Low			6
#define PinA_7_Low			7
#define PinA_8_Low			8
#define PinA_9_Low			9
#define PinA_10_Low			10
#define PinA_11_Low			11
#define PinA_12_Low			12
#define PinA_13_Low			13
#define PinA_14_Low			14
#define PinA_15_Low			15

#define PinB_0_Low			16
#define PinB_1_Low			17
#define PinB_2_Low			18
#define PinB_3_Low			19
#define PinB_4_Low			20
#define PinB_5_Low			21
#define PinB_6_Low			22
#define PinB_7_Low			23
#define PinB_8_Low			24
#define PinB_9_Low			25
#define PinB_10_Low			26
#define PinB_11_Low			27
#define PinB_12_Low			28
#define PinB_13_Low			29
#define PinB_14_Low			30
#define PinB_15_Low			31

#define PinC_0_Low			32
#define PinC_1_Low			33
#define PinC_2_Low			34
#define PinC_3_Low			35
#define PinC_4_Low			36
#define PinC_5_Low			37
#define PinC_6_Low			38
#define PinC_7_Low			39
#define PinC_8_Low			40
#define PinC_9_Low			41
#define PinC_10_Low			42
#define PinC_11_Low			43
#define PinC_12_Low			44
#define PinC_13_Low			45
#define PinC_14_Low			46
#define PinC_15_Low			47

#define PinD_0_Low			48
#define PinD_1_Low			49
#define PinD_2_Low			50
#define PinD_3_Low			51
#define PinD_4_Low			52
#define PinD_5_Low			53
#define PinD_6_Low			54
#define PinD_7_Low			55
#define PinD_8_Low			56
#define PinD_9_Low			57
#define PinD_10_Low			58
#define PinD_11_Low			59
#define PinD_12_Low			60
#define PinD_13_Low			61
#define PinD_14_Low			62
#define PinD_15_Low			63

/* pin port num HIGH*/

#define PinA_0_High				100
#define PinA_1_High				101
#define PinA_2_High				102
#define PinA_3_High				103
#define PinA_4_High				104
#define PinA_5_High				105
#define PinA_6_High				106
#define PinA_7_High				107
#define PinA_8_High				108
#define PinA_9_High				109
#define PinA_10_High			110
#define PinA_11_High			111
#define PinA_12_High			112
#define PinA_13_High			113
#define PinA_14_High			114
#define PinA_15_High			115

#define PinB_0_High				116
#define PinB_1_High				117
#define PinB_2_High				118
#define PinB_3_High				119
#define PinB_4_High				120
#define PinB_5_High				121
#define PinB_6_High				122
#define PinB_7_High				123
#define PinB_8_High				124
#define PinB_9_High				125
#define PinB_10_High			126
#define PinB_11_High			127
#define PinB_12_High			128
#define PinB_13_High			129
#define PinB_14_High			130
#define PinB_15_High			131

#define PinC_0_High				132
#define PinC_1_High				133
#define PinC_2_High				134
#define PinC_3_High				135
#define PinC_4_High				136
#define PinC_5_High				137
#define PinC_6_High				138
#define PinC_7_High				139
#define PinC_8_High				140
#define PinC_9_High				141
#define PinC_10_High			142
#define PinC_11_High			143
#define PinC_12_High			144
#define PinC_13_High			145
#define PinC_14_High			146
#define PinC_15_High			147

#define PinD_0_High				148
#define PinD_1_High				149
#define PinD_2_High				150
#define PinD_3_High				151
#define PinD_4_High				152
#define PinD_5_High				153
#define PinD_6_High				154
#define PinD_7_High				155
#define PinD_8_High				156
#define PinD_9_High				157
#define PinD_10_High			158
#define PinD_11_High			159
#define PinD_12_High			160
#define PinD_13_High			161
#define PinD_14_High			162
#define PinD_15_High			163

/* for speed , value ,any */

#define PinA_0					0
#define PinA_1					1
#define PinA_2					2
#define PinA_3					3
#define PinA_4					4
#define PinA_5					5
#define PinA_6					6
#define PinA_7					7
#define PinA_8					8
#define PinA_9					9
#define PinA_10					10
#define PinA_11					11
#define PinA_12					12
#define PinA_13					13
#define PinA_14					14
#define PinA_15					15

#define PinB_0					16
#define PinB_1					17
#define PinB_2					18
#define PinB_3					19
#define PinB_4					20
#define PinB_5					21
#define PinB_6					22
#define PinB_7					23
#define PinB_8					24
#define PinB_9					25
#define PinB_10					26
#define PinB_11					27
#define PinB_12					28
#define PinB_13					29
#define PinB_14					30
#define PinB_15					31

#define PinC_0					32
#define PinC_1					33
#define PinC_2					34
#define PinC_3					35
#define PinC_4					36
#define PinC_5					37
#define PinC_6					38
#define PinC_7					39
#define PinC_8					40
#define PinC_9					41
#define PinC_10					42
#define PinC_11					43
#define PinC_12					44
#define PinC_13					45
#define PinC_14					46
#define PinC_15					47

#define PinD_0					48
#define PinD_1					49
#define PinD_2					50
#define PinD_3					51
#define PinD_4					52
#define PinD_5					53
#define PinD_6					54
#define PinD_7					55
#define PinD_8					56
#define PinD_9					57
#define PinD_10					58
#define PinD_11					59
#define PinD_12					60
#define PinD_13					61
#define PinD_14					62
#define PinD_15					63

/* speed config */

#define	Low_Speed				0
#define midium_Speed			1
#define High_Speed				2
#define Very_High_Speed			3



void	DIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction,u8 direction_type,u8 Out_direction_type);
void AF_Select_pin_Fun(u8 port ,u8 pin , u8 Fun);


#define		pin0	0
#define		pin1	1
#define		pin2	2
#define		pin3	3

#define		pin4	4
#define		pin5	5
#define		pin6	6
#define		pin7	7

#define		pin8	8
#define		pin9	9
#define		pin10	10
#define		pin11	11

#define		pin12	12
#define		pin13	13
#define		pin14	14
#define		pin15	15

#define PORTA		0
#define PORTB		1
#define PORTC		2
#define PORTD		3
#define PORTE		4

#define	High		1
#define Low			0

/****************************/
/*		pin_mode				*/

#define	input	0
#define	output	1
#define	AF		2
#define Analog	3

/********************************************/
/*		GPIO port output type register 		*/


#define Output_push_pull		0
#define	Output_open_drain		1

/********************************************/
/*				speed register				*/

#define Low_speed			0
#define	Medium_speed		1
#define	High_speed			2
#define Very_high_speed		3

/***********************************************/
/*				Input Type Reg					*/

#define No_pull_up		0


/****************************************************/
/*					GPIO alternate function			*/


#define AF_Timer1_2			1
#define AF_Timer3_5			2
#define AF_Timer8_11		3
#define AF_I2C1_3			4
#define AF_SPI1_2			5
#define AF_SPI3				6
#define AF_UART1_3			7
#define AF_UART4_6			8
#define AF_CAN_Tim12_14		9
#define AF_OTG				10
//#define AF_ETH				11
#define AF_FSIMC			12
//#define AF_DCMI				13
#define AF_EventOut			15

/**************************************************/




#endif /* GPIO_INTERFACE_H_ */
