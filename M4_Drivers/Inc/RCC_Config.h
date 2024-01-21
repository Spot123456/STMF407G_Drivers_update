/*
 * RCC_Config.h
 *
 *  Created on: Dec 29, 2023
 *      Author: Ahmed Nour
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
 *  for input main clk you can choose :
 *  1- RCC_HSI
 *  2- RCC_HSE
 *  3- RCC_PLL
 */
#define 	InputCLK		RCC_HSE

/*
 *  if you select RCC_PLL as Input CLK
 *  for input PLL you can choose :
 *  1- PLL_HSI
 *  2- PLL_HSE
 */
#define		PLL_Input		PLL_HSI

/*
 *  for input Sec clk you can choose :
 *  1- RCC_LSI
 *  2- RCC_LSE
 */
#define 	Seconed_CLK		RCC_LSI

/*
 *  for interrupt clk you can choose :
 *  1- RCC_Polling
 *  2- RCC_Interrupt
 */

#define 	RCC_Enable_Interrupt	RCC_Interrupt


#define		RCC_AHB_Prescaler		AHB_pre_2

#define		RCC_APB1_Prescaler		APB_AHB_2

#define		RCC_APB2_Prescaler		AHB_pre_2

#endif /* RCC_CONFIG_H_ */
