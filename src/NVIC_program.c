/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31)
	{
		NVIC_ISER0 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else if(Copy_u8IntNumber <=59)
	{
			Copy_u8IntNumber -= 32;
			NVIC_ISER1 =(1 << Copy_u8IntNumber);	//writing 0 has no effect so we use =  not set_bit 
	}
	else
	{
		//return error
	}
}

void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31)
	{
		NVIC_ICER0 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else
	{
		//return error
	}
}


void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31)
	{
		NVIC_ISPR0 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else
	{
		//return error
	}
}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31)
	{
		NVIC_ICPR0 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 =(1 << Copy_u8IntNumber);		//writing 0 has no effect so we use =  not set_bit 
	}
	else
	{
		//return error
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if(Copy_u8IntNumber <=31)
	{
		Local_u8Result =GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result =GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		//return error
	}
	return Local_u8Result;
}

void NVIC_VoidSetPriorty(s8 Copy_s8IntID , u8 Copy_u8GroupPriorty , u8 Copy_u8SubPriorty , 	u32 Copy_u32GROUP)
{
	u8 Local_u8Priorty =  Copy_u8SubPriorty|(Copy_u8GroupPriorty<<((Copy_u32GROUP - 0x05FA0300)/256));
	//Core Peripheral
	
	
	//External peripheral
	if(Copy_s8IntID >=0)
	{
		NVIC_IPR[Copy_s8IntID] =Local_u8Priorty << 4;
	}
	SCB_AIRCR =Copy_u32GROUP ;
	
}
