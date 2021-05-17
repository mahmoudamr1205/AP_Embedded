
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
#include "STK_interface.h"
#include "ADC_interface.h"
// ----------------------------------------------------------------------------

#include "LCD2004_interface.h"
#include "ALARM_interface.h"



// ----- main() -----------------------
u16 par =  0b111101001111;
u16 x ;


void main(void)
{

	// initialization clock

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,GPIOA_IP);
	RCC_voidEnableClock(RCC_APB2,GPIOB_IP);


	HLCD_VoidInit();
	// Enable Systic


	MSTK_VoidInit();
	HALARM_VoidInit();
	HLCD_VoidInit();

	//adc

	 MADC_VoidSetPinMode(GPIOA, PIN0);
	 MADC_VoidSetPinMode(GPIOA, PIN7);
	MADC_VoidSet_Clock(RCC_CFGR_ADCPRE_DIV8);

	MADC_VoidInit();





	 HLCD_voidStart_Page("   ==============      ||  S ZONE  ||      ==============          MVM-01.     ");
	while (1)
    {
		HLCD_movecursor(1,1);
		HLCD_send_string("Sensor A : ");
		HLCD_send_number(ReadAnalog( PIN0));

		HLCD_movecursor(3,1);
		HLCD_send_string("Sensor B : ");
		HLCD_send_number(ReadAnalog(PIN7));

		MSTK_voidDelay_ms(500);
		HLCD_clear();




    }

}
/*

void EXTI0_IRQHandler(void){

	MGPIO_VoidSetPinValue(GPIOA, PIN0, LOW);
	MNVIC_voidSetPendingFlag(EXTI1);
	MGPIO_VoidSetPinValue(GPIOA, PIN1, LOW);

}
*/



int ms_s(void){


	 par=par+111;

	return par;

}
