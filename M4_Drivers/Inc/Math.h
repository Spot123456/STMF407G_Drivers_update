/*
 * Math.h
 *
 *  Created on: Dec 29, 2023
 *      Author: Ahmed Nour
 */

#ifndef MATH_H_
#define MATH_H_

#define	SET_Bit(Port,pin_no)		Port|=(1<<pin_no)
#define	CLR_Bit(Port,pin_no)		Port&=~(1<<pin_no)
#define	Toggle_Bit(Port,pin_no)		Port^=(1<<pin_no)
#define GET_Bit(Port,Pin_no)		((Port>>Pin_no)&0x01)

#endif /* MATH_H_ */
