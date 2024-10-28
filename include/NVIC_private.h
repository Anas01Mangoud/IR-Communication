/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0		*((u32*)0xE000E100) 					//Enable External Interrupt from 0 to 31 
#define NVIC_ISER1		*((u32*)0xE000E104) 					//Enable External Interrupt from 32 to 63 

#define NVIC_ICER0		*((u32*)0xE000E180) 					//Disable External Interrupt from 0 to 31 
#define NVIC_ICER1		*((u32*)0xE000E184) 					//Disable External Interrupt from 32 to 63

#define NVIC_ISPR0		*((u32*)0xE000E200)						//Set Pending flag from 0 to 31 
#define NVIC_ISPR1		*((u32*)0xE000E204)						//Set Pending flag from 32 to 63 

#define NVIC_ICPR0		*((u32*)0xE000E280)						//Clear Pending flag from 0 to 31 
#define NVIC_ICPR1		*((u32*)0xE000E284)						//Clear Pending flag from 32 to 63 

#define NVIC_IABR0		*((volatile u32*)0xE000E300)			//return the value of active flag from 0 to 31 		read only 
#define NVIC_IABR1		*((volatile u32*)0xE000E304)			//return the value of active flag from 32 to 63 	read only  

#define NVIC_IPR		((volatile u8 *)0xE000E400)

#define SCB_AIRCR		*((volatile u32 *)0xE000ED00+0x0C)

#endif