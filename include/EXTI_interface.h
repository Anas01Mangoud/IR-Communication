/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSingleLatch(u8 Copy_u8Line ,u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void (*ptr)(void));





#endif