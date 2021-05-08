
/*
 * Interrupt.c
 *
 * Created: 26 septemper 2020
 * Author: Mahmoud AMR
 * Version: V01
 */

// --------------includes library ---------------------------------------------
#include "STD_TYPES.h"
#include "BIT_MATH.h"


// --------------includes library ---------------------------------------------
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
// ----------------------------------------------------------------------------

#include "LCD2004_interface.h"

// ----- main() ---------------------------------------------------------------

void main(void)
{


	// initialization clock

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,GPIOA_IP);

	// Enable Systic


	MSTK_voidInit();
	HLCD_voidInit();




	// enable Interrupt


			HLCD_movecursor(1,1);
			HLCD_send_string("  Dr.ENAS Mustafa       Good Luck!                          M7dsh hyt3lm HNA -_)");

	while (1)
    {


    }






}
/*

void EXTI0_IRQHandler(void){

	MGPIO_VoidSetPinValue(GPIOA, PIN0, LOW);
	MNVIC_voidSetPendingFlag(EXTI1);
	MGPIO_VoidSetPinValue(GPIOA, PIN1, LOW);

}
*/




