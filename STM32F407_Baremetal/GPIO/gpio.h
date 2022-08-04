/*
 * gpio.h
 *
 *  Created on: 22-Jun-2022
 *      Author: crmar
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f407xx.h"
#include "stm32f4xx.h"
#include "stdbool.h"

/**REGISTER CONFIGURATION MASKS**/
#define gpio_moder_mask 		0b1100000
#define gpio_otyper_mask 		0b0010000
#define gpio_ospeedr_mask		0b0001100
#define gpio_pupdr_mask			0b0000011

/**GPIO FUNCTION CONFIGURATION**/
#define gpio_output_pushpull 		   0b0101100
#define gpio_output_pullup   		   0b0101101
#define gpio_output_pulldown 		   0b0101110
#define gpio_output_opendrain 		   0b0111100
#define gpio_output_opendrain_pullup   0b0111101
#define gpio_output_opendrain_pulldown 0b0111110

#define afio_output_pushpull 		   0b1001100
#define afio_output_pullup   		   0b1001101
#define afio_output_pulldown 		   0b1001110
#define afio_output_opendrain 		   0b1011100
#define afio_output_opendrain_pullup   0b1011101
#define afio_output_opendrain_pulldown 0b1011110

#define gpio_input_floating 		   0b0001100
#define gpio_input_pullup   		   0b0001101
#define gpio_input_pulldown 		   0b0001110

#define analog_io 					   0b1100000

void gpio_init(GPIO_TypeDef *port,int function,uint32_t pin,int alternate_function);
void gpio_write(GPIO_TypeDef *port,uint32_t pin,bool state);
void gpio_toggle(GPIO_TypeDef *port,uint32_t pin,int delay);
int gpio_read(GPIO_TypeDef *port,uint32_t pin);
#endif /* GPIO_H_ */
