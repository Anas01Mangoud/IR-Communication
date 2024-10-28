/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void NVIC_VoidSetPriorty(s8 Copy_s8IntID , u8 Copy_u8GroupPriorty , u8 Copy_u8SubPriorty , 	u32 Copy_u32GROUP);

#define GROUP3		0x05FA0300		//4bit for gourp (IPR)
#define GROUP4		0x05FA0400		//3bit for gourp &one bit for sub (IPR)
#define GROUP5		0x05FA0500		//2bit for gourp & 2 bit for sub (IPR)
#define GROUP6		0x05FA0600		//1bit for gourp & 3 bit for sub (IPR)
#define GROUP7		0x05FA0700		//4 bit for sub (IPR)






#endif