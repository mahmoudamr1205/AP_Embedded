/*
 * ADC_program.c
 *
 *  Created on: May 9, 2021
 *      Author: Mahmoud Amr
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"


void MADC_VoidInit(void){

	//-------------ADC on-off control------------------
	ADC_CR2 = 0;

	// ENABLE ADC  "ADC ON" First Time
	ADC_CR2 = 0x0001;
	MSTK_voidDelay_ms(100);

	/*	ENABLE ADC  "ADC ON" Second Time
	 * enable calibration - Enable Continuous conversion
	 */
	 SET_BIT(ADC_CR2, CAL);
	 SET_BIT(ADC_CR2, ADON);
	 SET_BIT(ADC_CR2, CONT);

	 // Sample time		100: 41.5 cycles

	 SET_BIT(ADC_SMPR2, 0);
	 SET_BIT(ADC_SMPR2, 1);
	 SET_BIT(ADC_SMPR2, 2);


		//data align 0: Right Alignment
		//	CLR_BIT(ADC_CR2, ALIGN);


}


void MADC_VoidSet_Clock(u8 copy_u8ADCPRE){

	//		ENABLE ClOCK TO ADC Channel
 	 RCC_voidEnableClock(RCC_APB2,ADC1EN_IP);
	 //RCC_voidEnableClock(RCC_APB2,ADC2EN_IP);
 	 // RCC_voidEnableClock(RCC_APB2,ADC3EN_IP);

	 //		 ADC prescaler

		switch(copy_u8ADCPRE)
		{
		case RCC_CFGR_ADCPRE_DIV2 :
					CLR_BIT(RCC_CFGR,  14);
					CLR_BIT(RCC_CFGR,  15);
						break;
		case RCC_CFGR_ADCPRE_DIV4 :
					SET_BIT(RCC_CFGR,  14);
					CLR_BIT(RCC_CFGR,  15);
						break;
		case RCC_CFGR_ADCPRE_DIV6 :
					CLR_BIT(RCC_CFGR,  14);
					SET_BIT(RCC_CFGR,  15);
						break;
		case RCC_CFGR_ADCPRE_DIV8 :
					SET_BIT(RCC_CFGR,  14);
					SET_BIT(RCC_CFGR,  15);
						break;
		default : /*Return Error*/    		     break;


		}

}




void MADC_VoidSetPinMode(u8 copy_u8PORT, u8 copy_u8PIN){


	switch(copy_u8PORT)
	{
	case GPIOA :
			//		Enable GPIO pin clock
		RCC_voidEnableClock(RCC_APB2,GPIOA_IP);
			//	Enable GPIO pin direction input Analog
		MGPIO_VoidSetPinDirection(copy_u8PORT , copy_u8PIN , INPUT_ANLOG);
					break;
	case GPIOB :
			//		Enable GPIO pin clock
		RCC_voidEnableClock(RCC_APB2,GPIOB_IP);
			//	Enable GPIO pin direction input Analog
		MGPIO_VoidSetPinDirection(copy_u8PORT , copy_u8PIN , INPUT_ANLOG);
					break;
	case GPIOC :
			//		Enable GPIO pin clock
		RCC_voidEnableClock(RCC_APB2,GPIOC_IP);
			//	Enable GPIO pin direction input Analog
		MGPIO_VoidSetPinDirection(copy_u8PORT , copy_u8PIN , INPUT_ANLOG);
					break;

	default : /*Return Error*/    		     break;


	}





}


u16 ReadAnalog(u8 copy_u8PIN){

	u16 y;
	//Select Sequence conversion

	ADC_SQR3 = copy_u8PIN;

		if ( GET_BIT(ADC_SR , 1)){
						y= ADC_DR;
			} else {
				y = 0 ;
			}

		return y ;
}










/*
 *
 *
 *		ADC config
 *		-------------------------------------------------------------
 *		1- type of channel (Regular - ijected) 						 |
 *		2- type of trigger (Software- timer - ........)				 |
 *		-------------------------------------------------------------
 *		> GPIO Mode >INPUT_ANLOG
 *		> Enable Clock From RCC TO PORT
 *		> Enable Clock From RCC TO ADC  from ADC1EN - RCC_ABP2
 *
 *		 Bits 15:14 ADCPRE: ADC prescaler page 102
 *		 7.3.4 APB2 peripheral reset register (RCC_APB2RSTR)  P.106 -
 *		  7.3.7 APB2 peripheral clock enable register (RCC_APB2ENR) p.112-

 *
 *
 *		  > prescaler  from PCLK2
 *		  > Data Right Aligment
 *		  > config Trigger
 *		  > select channal
 *		  >
 *		  **if 	ijected see tricky
 *		  ---------------------------
 *		  start conversion
 *		  End conversion
 *		  read data
 *		  clear flag
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *		NOTE
 *		===========
 *		If have any proplem cheack the pull up \ pull down
 *
 */
