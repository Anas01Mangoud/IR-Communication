/**************************************************************/
/*AUthor :                                                    */
/*Date   :                                                    */
/*Version: V01                                                */
/**************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define GPIOA	0
#define GPIOB	1
#define GPIOC	2

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

#define output_10MHZ_PUSH_PULL		0b0001
#define output_10MHZ_OPEN_DRAIN		0b0101
#define output_10MHZ_ALTERN_PP		0b1001
#define output_10MHZ_ALTERN_OD		0b1101

#define output_2MHZ_PUSH_PULL		0b0010
#define output_2MHZ_OPEN_DRAIN		0b0110
#define output_2MHZ_ALTERN_PP		0b1010
#define output_2MHZ_ALTERN_OD		0b1110

#define output_50MHZ_PUSH_PULL		0b0011
#define output_50MHZ_OPEN_DRAIN		0b0111
#define output_50MHZ_ALTERN_PP		0b1011
#define output_50MHZ_ALTERN_OD		0b1111
 
#define INPUT_ANALOG				0b0000
#define INPUT_FLOATING				0b0100
#define INPUT_PULL_DOWN_UP			0b1000



void MGPIO_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Mode);

void MGPIO_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Value);

u8 MGPIO_u8GetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN);



#endif