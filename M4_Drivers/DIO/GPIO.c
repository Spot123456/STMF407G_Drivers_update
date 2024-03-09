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

#include "GPIO_Config.h"
#include "AF_Config.h"
#include "GPIO_Private.h"
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
	/* GPIO port output type register */
	/* GPIO port pull up / down Registers */
	/* Alternative function registers (high/low) */

#if PORTA_Enable
	//GPIOA_MODER=0;
	//GPIOA->GPIOA_B_X_MODER= GPIOA_State;

	GPIOA_Reg->GPIOx_PUPDR = GPIOA_Pull_Up_Down;
	GPIOA_Reg->GPIOx_OTYPER= GPIOA_output_type;
	GPIOA_Reg->GPIOx_AFRL = AFIOA_set_Low;
	GPIOA_Reg->GPIOx_AFRH = AFIOA_set_High;

#endif
#if PORTB_Enable

	GPIOB_Reg->GPIOx_MODER= GPIOB_State;
	GPIOB_Reg->GPIOx_PUPDR = GPIOB_Pull_Up_Down;
	GPIOB_Reg->GPIOx_OTYPER= GPIOB_output_type;
	GPIOB_Reg->GPIOx_AFRL = AFIOB_set_Low;
	GPIOB_Reg->GPIOx_AFRH = AFIOB_set_High;

#endif
#if PORTC_Enable

	GPIOC_Reg->GPIOx_MODER= GPIOC_State;
	GPIOC_Reg->GPIOx_PUPDR = GPIOC_Pull_Up_Down;
	GPIOC_Reg->GPIOx_OTYPER= GPIOC_output_type;
	GPIOC_Reg->GPIOx_AFRL = AFIOC_set_Low;
	GPIOC_Reg->GPIOx_AFRH = AFIOC_set_High;


#endif

#if PORTD_Enable
	GPIOD_Reg->GPIOx_MODER= GPIOD_State;
	GPIOD_Reg->GPIOx_PUPDR = GPIOD_Pull_Up_Down;
	GPIOD_Reg->GPIOx_OTYPER= GPIOD_output_type;
	GPIOD_Reg->GPIOx_AFRL = AFIOD_set_Low;
	GPIOD_Reg->GPIOx_AFRH = AFIOD_set_High;


#endif

#if PORTE_Enable
	GPIOE_Reg->GPIOx_MODER= GPIOE_State;
#endif

}

/*due to bug in this reg (moderA) so manually config
 * ie bug is word access to reg make shutdown to microcontroller
 * pin_mode = in/out/AF/analog */

void GPIO_V_Config_MODE_GPIOA(u8 pin_no,u8 pin_mode)
{
	GPIOA_Reg->GPIOx_MODER&=~(0b11<<pin_no*2);
	GPIOA_Reg->GPIOx_MODER|=(pin_mode<<pin_no*2);
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


















void	DIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction,u8 direction_type,u8 Out_direction_type)
{
	if((port<=PORTE)&&(pin<=pin15))
	{
		switch(port)
		{
		case	PORTA:
			switch(Direction)
			{
			case	input :	GPIOA->GPIOA_B_X_MODER&=~(0b11<<pin*2);
							GPIOA->GPIOA_B_X_MODER|=(input<<pin*2);
							switch(direction_type)
							{
							// make masking then set
							case No_pull_up:	GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOA->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
							case Pull_up:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
							case Pull_down:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
							}
							break;

			case	output	:	GPIOA->GPIOA_B_X_MODER&=~(0b11<<pin*2);
								GPIOA->GPIOA_B_X_MODER|=(output<<pin*2);
								switch(direction_type)
								{
									// make masking then set
									case No_pull_up:	GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOA->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
									case Pull_up:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
									case Pull_down:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
								}
								switch(Out_direction_type)
								{
									case Output_push_pull:	GPIOA->GPIOx_OTYPER&=~(1<<pin); break;
									case Output_open_drain:	GPIOA->GPIOx_OTYPER|=(1<<pin); break;

								}
								break;

			case	AF :	GPIOA->GPIOA_B_X_MODER&=~(0b11<<pin*2);
							GPIOA->GPIOA_B_X_MODER|=(AF<<pin*2);

							switch(direction_type)
							{
								// make masking then set
								case No_pull_up:	GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOA->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
								case Pull_up:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
								case Pull_down:		GPIOA->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOA->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
							}
							switch(Out_direction_type)
							{
								case Output_push_pull:	GPIOA->GPIOx_OTYPER&=~(1<<pin); break;
								case Output_open_drain:	GPIOA->GPIOx_OTYPER|=(1<<pin); break;

							}
				break;



			case	Analog :	GPIOA->GPIOA_B_X_MODER&=~(0b11<<pin*2);
								GPIOA->GPIOA_B_X_MODER|=(Analog<<pin*2);
								break;
			}
			break;
/*************************************************************************************/
			case	PORTB:
					switch(Direction)
					{
					case	input :	GPIOB->GPIOA_B_X_MODER&=~(0b11<<pin*2);
									GPIOB->GPIOA_B_X_MODER|=(input<<pin*2);
									switch(direction_type)
									{
									// make masking then set
									case No_pull_up:	GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOB->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
									case Pull_up:		GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOB->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
									case Pull_down:		GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOB->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
									}
									break;

					case	output	:	GPIOB->GPIOA_B_X_MODER&=~(0b11<<pin*2);
										GPIOB->GPIOA_B_X_MODER|=(output<<pin*2);
										break;

					case	AF :	GPIOB->GPIOA_B_X_MODER&=~(0b11<<pin*2);
									GPIOB->GPIOA_B_X_MODER|=(AF<<pin*2);
									switch(direction_type)
									{
										// make masking then set
										case No_pull_up:	GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOB->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
										case Pull_up:		GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOB->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
										case Pull_down:		GPIOB->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOB->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
									}
									switch(Out_direction_type)
									{
										case Output_push_pull:	GPIOB->GPIOx_OTYPER&=~(1<<pin); break;
										case Output_open_drain:	GPIOB->GPIOx_OTYPER|=(1<<pin); break;

									}

							break;


					case	Analog :	GPIOB->GPIOA_B_X_MODER&=~(0b11<<pin*2);
										GPIOB->GPIOA_B_X_MODER|=(Analog<<pin*2);
										break;
					}
			break;
/***********************************************************************************/
			case	PORTC:
					switch(Direction)
					{
					case	input :	GPIOC->GPIOA_B_X_MODER&=~(0b11<<pin*2);
									GPIOC->GPIOA_B_X_MODER|=(input<<pin*2);
									switch(direction_type)
									{
									// make masking then set
									case No_pull_up:	GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOC->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
									case Pull_up:		GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOC->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
									case Pull_down:		GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOC->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
									}
									break;


					case	output	:	GPIOC->GPIOA_B_X_MODER&=~(0b11<<pin*2);
										GPIOC->GPIOA_B_X_MODER|=(output<<pin*2);
										break;

					case	AF :	//GPIOC->GPIOA_B_X_MODER&=~(0b11<<pin*2);
									GPIOC->GPIOA_B_X_MODER|=(0b10<<pin*2);
									switch(direction_type)
									{
										// make masking then set
										case No_pull_up:	GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOC->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
										case Pull_up:		GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOC->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
										case Pull_down:		GPIOC->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOC->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
									}
									switch(Out_direction_type)
									{
										case Output_push_pull:	GPIOC->GPIOx_OTYPER&=~(1<<pin); break;
										case Output_open_drain:	GPIOC->GPIOx_OTYPER|=(1<<pin); break;

									}

									break;
					case	Analog :	GPIOC->GPIOA_B_X_MODER&=~(0b11<<pin*2);
										GPIOC->GPIOA_B_X_MODER|=(Analog<<pin*2);
										break;
					}
			break;

/**************************************************************************************/
			case	PORTD:
							switch(Direction)
							{
							case	input :	GPIOD->GPIOA_B_X_MODER&=~(0b11<<pin*2);
											GPIOD->GPIOA_B_X_MODER|=(input<<pin*2);
											switch(direction_type)
											{
											// make masking then set
											case No_pull_up:	GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOD->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
											case Pull_up:		GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOD->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
											case Pull_down:		GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOD->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
											}

											break;

							case	output	:	GPIOD->GPIOA_B_X_MODER&=~(0b11<<pin*2);
												GPIOD->GPIOA_B_X_MODER|=(output<<pin*2);
												break;

							case	AF :	GPIOD->GPIOA_B_X_MODER&=~(0b11<<pin*2);
											GPIOD->GPIOA_B_X_MODER|=(AF<<pin*2);
											switch(direction_type)
											{
												// make masking then set
												case No_pull_up:	GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOD->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
												case Pull_up:		GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOD->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
												case Pull_down:		GPIOD->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOD->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
											}
											switch(Out_direction_type)
											{
												case Output_push_pull:	GPIOD->GPIOx_OTYPER&=~(1<<pin); break;
												case Output_open_drain:	GPIOD->GPIOx_OTYPER|=(1<<pin); break;

											}


											break;

							case	Analog :	GPIOD->GPIOA_B_X_MODER&=~(0b11<<pin*2);
												GPIOD->GPIOA_B_X_MODER|=(Analog<<pin*2);
												break;
							}
					break;


/***************************************************************************************/
					case	PORTE:
							switch(Direction)
							{
							case	input :	GPIOE->GPIOA_B_X_MODER&=~(0b11<<pin*2);
											GPIOE->GPIOA_B_X_MODER|=(input<<pin*2);
											switch(direction_type)
											{
											// make masking then set
											case No_pull_up:	GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOE->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
											case Pull_up:		GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOE->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
											case Pull_down:		GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOE->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
											}
											break;

							case	output	:	GPIOE->GPIOA_B_X_MODER&=~(0b11<<pin*2);
												GPIOE->GPIOA_B_X_MODER|=(output<<pin*2);
												break;

							case	AF :	GPIOE->GPIOA_B_X_MODER&=~(0b11<<pin*2);
											GPIOE->GPIOA_B_X_MODER|=(AF<<pin*2);
											switch(direction_type)
											{
												// make masking then set
												case No_pull_up:	GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin);GPIOE->GPIOA_B_X_PUPDR&=~(No_pull_up<<pin*2); break;
												case Pull_up:		GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOE->GPIOA_B_X_PUPDR|=(Pull_up<<pin*2);break;
												case Pull_down:		GPIOE->GPIOA_B_X_PUPDR&=~(0b11<<pin); GPIOE->GPIOA_B_X_PUPDR|=(Pull_down<<pin*2); break;
											}
											switch(Out_direction_type)
											{
												case Output_push_pull:	GPIOE->GPIOx_OTYPER&=~(1<<pin); break;
												case Output_open_drain:	GPIOE->GPIOx_OTYPER|=(1<<pin); break;

											}
											break;

							case	Analog :	GPIOE->GPIOA_B_X_MODER&=~(0b11<<pin*2);
												GPIOE->GPIOA_B_X_MODER|=(Analog<<pin*2);
												break;
							}
					break;

		}
	}
	else
	{
		// error handling
	}
}




void AF_Select_pin_Fun(u8 port ,u8 pin , u8 Fun)
{
	if(pin<8)
	{
		switch (port)
		{
			case PORTA:	GPIOA->GPIOx_AFRL|=(Fun<<pin*4); break;
			case PORTB:	GPIOB->GPIOx_AFRL|=(Fun<<pin*4); break;
			case PORTC:	GPIOC->GPIOx_AFRL|=(Fun<<pin*4); break;
			case PORTD:	GPIOD->GPIOx_AFRL|=(Fun<<pin*4); break;
			case PORTE:	GPIOE->GPIOx_AFRL|=(Fun<<pin*4); break;
		}
	}
	else if (pin<16)
	{
		pin-=8;
		switch (port)
		{
			case PORTA:	GPIOA->GPIOx_AFRH|=(Fun<<pin*4); break;
			case PORTB:	GPIOB->GPIOx_AFRH|=(Fun<<pin*4); break;
			case PORTC:	GPIOC->GPIOx_AFRH|=(Fun<<pin*4); break;
			case PORTD:	GPIOD->GPIOx_AFRH|=(Fun<<pin*4); break;
			case PORTE:	GPIOE->GPIOx_AFRH|=(Fun<<pin*4); break;

		}
	}
}

