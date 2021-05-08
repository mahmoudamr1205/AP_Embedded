/*
 * LCD2004_config.h
 *
 *  Created on: May 8, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_LCD2004_CONFIG_H_
#define INCLUDE_LCD2004_CONFIG_H_




//		---------------------------Configuration START -----------------------------

//#define four_bits_mode
//#define eight_bits_mode

#define four_bits_mode	//four_bits_mode

#ifdef  four_bits_mode

#define RS 			PIN0
#define EN 			PIN1
#define D4			PIN2
#define D5			PIN3
#define D6			PIN4
#define D7			PIN5

#define LCD_PORT	GPIOA

#endif

#ifdef eight_bits_mode


#endif




//		---------------------------Configuration end -----------------------------



#endif /* INCLUDE_LCD2004_CONFIG_H_ */
