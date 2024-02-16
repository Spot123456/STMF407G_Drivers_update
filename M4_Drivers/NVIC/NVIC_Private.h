/*
 * NVIC_Config.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Ahmed Nour
 */


#ifndef		NVIC_PRIVATE_H_
#define 	NVIC_PRIVATE_H_


#define 	NVIC_BaseADDRESS		(0xE000E100)


typedef struct
{
	u32 NVIC_ISER[8]; // Interrupt Set Enable Registers
	u32 RESERVED0[24]; // Reserved addresses
	u32 NVIC_ICER[8]; // Interrupt Clear Enable Registers
	u32 RESERVED1[24];
	u32 NVIC_ISPR[8]; // Interrupt Set Pending Registers
	u32 RESERVED5[24]; // Reserved addresses
	u32 NVIC_ICPR[8]; // Interrupt Clear Pending Registers
	u32 RESERVED6[24];
	u32 NVIC_IABR[8]; // Interrupt Active Bit Registers
	u32 RESERVED2[56]; // Reserved addresses
	u32 NVIC_IPR[60]; // Interrupt Priority Registers
	u32 RESERVED3[644]; // Reserved addresses
	u32 STIR; // Software Trigger Interrupt Register
}NVIC_ST;

#define 	NVIC_REG 	((NVIC_ST*)(NVIC_BaseADDRESS))

	// first we need write to regester so we rite a key for it
	// the second we need to select the periority in the second half of word
	// so let say the first 4 bits (half word) is a key and the 3bit (half byte is for periority)


#define		GRB_16_SUB_0			(0x5FA00300)		//half key half periority
#define		GRB_8_SUB_2				(0x5FA00400)
#define		GRB_4_SUB_4				(0x5FA00500)
#define		GRB_2_SUB_8				(0x5FA00600)
#define		GRB_0_SUB_16			(0x5FA00700)

/*  VIP Rag3 3leha point to u8 to access byte in word register */
// no * bec it pointer to array
//#define			NVIC_IPR				((u8*)(NVIC_BASE_ADD+0x400))	// the name of array is a pointer to array

#endif



