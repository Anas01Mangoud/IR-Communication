/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI0_CallBack)(void) = NULL;
void MEXTI_voidInit()
{
	#if   EXTI_LINE ==LINE0
			SET_BIT(EXTI ->IMR ,LINE0);
	#elif EXTI_LINE ==LINE1
			SET_BIT(EXTI ->IMR ,LINE1);	
	#elif EXTI_LINE ==LINE2
			SET_BIT(EXTI ->IMR ,LINE2);	
	#elif EXTI_LINE ==LINE3
			SET_BIT(EXTI ->IMR ,LINE3);
	#elif EXTI_LINE ==LINE4
			SET_BIT(EXTI ->IMR ,LINE4);	
	#else
		#error (Wrong External Line choice);
	#endif
	
	
	
	
	
	#if	EXTI_MODE ==RASING
	SET_BIT( EXTI->RTSR , EXTI_LINE );
	#elif	EXTI_MODE ==FALLING
	SET_BIT( EXTI->FTSR , EXTI_LINE );
	#elif	EXTI_MODE ==ON_CHANGE
	SET_BIT( EXTI->RTSR , EXTI_LINE );
	SET_BIT( EXTI->FTSR , EXTI_LINE );
	#else	#error "Wrong mode &Line choice"
	#endif
		//CLR_BIT(EXTI->IMR ,Copy_u8Line );

}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR ,Copy_u8Line );
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR ,Copy_u8Line );
	
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	
	SET_BIT(EXTI->SWIER ,Copy_u8Line );
}
void MEXTI_voidSetSingleLatch(u8 Copy_u8Line ,u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING    :	SET_BIT( EXTI->RTSR , Copy_u8Line );break;
		
		case FALLING   :	SET_BIT( EXTI->FTSR , Copy_u8Line );break;
		
		case ON_CHANGE :	SET_BIT( EXTI->RTSR , Copy_u8Line );
							SET_BIT( EXTI->FTSR , Copy_u8Line );break;
	}
	SET_BIT(EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidSetCallBack(void (*ptr)(void))
{
	EXTI0_CallBack =ptr;
}
void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	//clear pending Bit
	SET_BIT(EXTI->PR ,0);
}
