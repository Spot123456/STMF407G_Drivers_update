/*
 *  file		:	GPIO.c
 *	breif		:	GPIO Driver
 *  Created on	: 	Jan 10, 2024
 *  Author		: 	Ahmed Nour
 */



/***************************************
 	 	 	 INCLUDES
 ***************************************/

#include "../Inc/STD_Type.h"
#include "../Inc/Math.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "AF_Config.h"
#include "GPIO_Interface.h"

/*************************************************
 syntax: void GPIO_V_PortInterface_Direction();

 Description	:	Initialization Mc state , output type , pull up /down , Alternative function
 Synch/Asynch	:	Synchronouse
 Reentrance		:	reeentrant
 parameter in	:	null	(void)
 parameter out	:	null	(void)
 return value	:	void

***************************************************/

void GPIO_V_PortInterface_Direction()
{
	/* Pin Config State */
	GPIOA_Reg->GPIOx_MODER= GPIOA_State;
	GPIOB_Reg->GPIOx_MODER= GPIOB_State;
	GPIOC_Reg->GPIOx_MODER= GPIOC_State;
	GPIOD_Reg->GPIOx_MODER= GPIOD_State;
	GPIOE_Reg->GPIOx_MODER= GPIOE_State;

	/* GPIO port output type register */
	GPIOA_Reg->GPIOx_OTYPER= GPIOA_output_type;
	GPIOB_Reg->GPIOx_OTYPER= GPIOB_output_type;
	GPIOC_Reg->GPIOx_OTYPER= GPIOC_output_type;
	GPIOD_Reg->GPIOx_OTYPER= GPIOD_output_type;

	/* GPIO port pull up / down Registers */

	GPIOA_Reg->GPIOx_PUPDR = GPIOA_Pull_Up_Down;
	GPIOB_Reg->GPIOx_PUPDR = GPIOB_Pull_Up_Down;
	GPIOC_Reg->GPIOx_PUPDR = GPIOC_Pull_Up_Down;
	GPIOD_Reg->GPIOx_PUPDR = GPIOD_Pull_Up_Down;

	/* Alternative function registers (high/low) */
	GPIOA_Reg->GPIOx_AFRH = AFIOA_set_High;
	GPIOB_Reg->GPIOx_AFRH = AFIOB_set_High;
	GPIOC_Reg->GPIOx_AFRH = AFIOC_set_High;
	GPIOD_Reg->GPIOx_AFRH = AFIOD_set_High;

	GPIOA_Reg->GPIOx_AFRL = AFIOA_set_Low;
	GPIOB_Reg->GPIOx_AFRL = AFIOB_set_Low;
	GPIOC_Reg->GPIOx_AFRL = AFIOC_set_Low;
	GPIOD_Reg->GPIOx_AFRL = AFIOD_set_Low;




}


/******************************************************
 	 syntax			:	void GPIO_V_Set_Pin_value(u8 pin)
 	 Description	:	write on the pin  (high or low)

 	 synch/Asynch	:	Synchronouse
 	 Reentrance		:	Reentrant
 	 parameter in	:	pin state High or Low (pin)
 	 parameter out	:	null
 	 return value	:	Void


 ********************************************************/
void GPIO_V_Set_Pin_value(u8 pin)
{
	if (pin<=63)
	{
		u8 GPIO ,PIN_Value_Low;
		GPIO =	pin/ GPIO_Check;		/* Get the number of port */
		PIN_Value_Low= pin%GPIO_Check;	/*	get the number of pin */

		switch(GPIO)
		{
		/* clear the value as atomic access */
		case PORTA:	GPIOA_Reg->GPIOx_BSRR=1<<(PIN_Value_Low+PIN_Shifting_Low);		break;
		case PORTB:	GPIOB_Reg->GPIOx_BSRR=1<<(PIN_Value_Low+PIN_Shifting_Low);		break;
		case PORTC:	GPIOC_Reg->GPIOx_BSRR=1<<(PIN_Value_Low+PIN_Shifting_Low);		break;
		case PORTD:	GPIOD_Reg->GPIOx_BSRR=1<<(PIN_Value_Low+PIN_Shifting_Low);		break;
		default: /* do nothing*/	break;

		}
	}
	else if(pin<=163)
	{
		pin-=100;
		u8 GPIO ,PIN_Value_High;
		GPIO =	pin/ GPIO_Check;	/* Get the number of port */
		PIN_Value_High= pin%GPIO_Check;	/*	get the number of pin */
		switch(GPIO)
		{
		/* set the value as atomic access */
		case PORTA:	GPIOA_Reg->GPIOx_BSRR=1<<(PIN_Value_High);		break;
		case PORTB:	GPIOB_Reg->GPIOx_BSRR=1<<(PIN_Value_High);		break;
		case PORTC:	GPIOC_Reg->GPIOx_BSRR=1<<(PIN_Value_High);		break;
		case PORTD:	GPIOD_Reg->GPIOx_BSRR=1<<(PIN_Value_High);		break;
		default: /* do nothing*/	break;
		}
	}
	else
	{
		// error handling
	}
}

/******************************************************
 	 syntax			:	void GPIO_V_Set_Pin_speed(u8 pin)
 	 Description	:	change speed on the pin  (high or low ,very high ,medium)

 	 synch/Asynch	:	Synchronouse
 	 Reentrance		:	Reentrant
 	 parameter in	:	pin number (pin), speed
 	 parameter out	:	null
 	 return value	:	Void


 ********************************************************/

void GPIO_V_Set_Pin_Speed(u8 pin,u8 Speed)
{

	if(pin<=63)
	{
		u8 GPIO,Pin_num;
		GPIO=pin/GPIO_Check;	/* Get the number of port */
		Pin_num = pin % GPIO_Check;	/*	get the number of pin */
		switch(GPIO)
		{
		/* clear the value of the selected pin (hw) then set it  */
		case PORTA: GPIOA_Reg->GPIOx_OSPEEDR&=~(0b11<<Pin_num*2);
					GPIOA_Reg->GPIOx_OSPEEDR|=(Speed<<Pin_num*2);
					break;
		case PORTB: GPIOB_Reg->GPIOx_OSPEEDR&=~(0b11<<Pin_num*2);
					GPIOB_Reg->GPIOx_OSPEEDR|=(Speed<<Pin_num*2);
					break;
		case PORTC: GPIOC_Reg->GPIOx_OSPEEDR&=~(0b11<<Pin_num*2);
					GPIOC_Reg->GPIOx_OSPEEDR|=(Speed<<Pin_num*2);
					break;

		case PORTD: GPIOD_Reg->GPIOx_OSPEEDR&=~(0b11<<Pin_num*2);
					GPIOD_Reg->GPIOx_OSPEEDR|=(Speed<<Pin_num*2);
					break;
		}

	}

}
/******************************************************
 	 syntax			:	void GPIO_V_Get_Pin_value(u8 pin)
 	 Description	:	Get value of the pin  (high or low)

 	 synch/Asynch	:	Synchronouse
 	 Reentrance		:	Reentrant
 	 parameter in	:	pin number (pin) , pointer to return value
 	 parameter out	:	null
 	 return value	:	Void


 ********************************************************/
void GPIO_V_Get_pin_Value(u8 pin,u8*value)
{
	if(pin<=63)
		{
			u8 GPIO,Pin_num;
			GPIO=pin/GPIO_Check;		/* Get the number of port */
			Pin_num = pin % GPIO_Check;	/*	get the number of pin */
			switch(GPIO)
			{

			case PORTA:
			*value=	GET_Bit(GPIOA_Reg->GPIOx_IDR,Pin_num);
						break;
			case PORTB:
			*value= GET_Bit(GPIOB_Reg->GPIOx_IDR,Pin_num);
						break;
			case PORTC:
			*value= GET_Bit(GPIOC_Reg->GPIOx_IDR,Pin_num);
						break;

			case PORTD:
			*value= GET_Bit(GPIOD_Reg->GPIOx_IDR,Pin_num);
						break;
			}

		}

}

/******************************************************
 	 syntax			:	void GPIO_V_Toggle_pin(u8 pin)
 	 Description	:	toggle value of the pin  (high or low)

 	 synch/Asynch	:	Synchronouse
 	 Reentrance		:	Reentrant
 	 parameter in	:	pin number (pin)
 	 parameter out	:	null
 	 return value	:	Void


 ********************************************************/
void GPIO_V_Toggle_pin(u8 pin)
{
	if (pin<=63)
		{
			u8 GPIO ,PIN_Value;
			GPIO =	pin/ GPIO_Check;	/* Get the number of port */
			PIN_Value= pin%GPIO_Check;	/*	get the number of pin */
			switch(GPIO)
			{
			case PORTA:	Toggle_Bit(GPIOA_Reg->GPIOx_ODR,PIN_Value);		break;
			case PORTB:	GPIOB_Reg->GPIOx_ODR^=1<<(PIN_Value);		break;
			case PORTC:	GPIOC_Reg->GPIOx_ODR^=1<<(PIN_Value);		break;
			case PORTD:	GPIOD_Reg->GPIOx_ODR^=1<<(PIN_Value);		break;
			default: /* do nothing*/	break;

			}
		}

}

