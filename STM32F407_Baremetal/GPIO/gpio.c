/*
 * gpio.c
 *
 *  Created on: 22-Jun-2022
 *      Author: crmar
 */

#include "gpio.h"

void gpio_init(GPIO_TypeDef *port, int function, uint32_t pin,
		int alternate_function) {

	 /**This is the GPIO initialisation function.
	 * The various registers defined for configuring GPIO are configured here.
	 * This is done based on the arguments function and alternate function.
	 * Macros have been defined for the above in gpio.h
	 */

	if (port == GPIOA) {

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		/** pin setup **/
		port->MODER |= ((gpio_moder_mask & function) >> 5) << (2 * pin);
		port->OTYPER |= ((gpio_otyper_mask & function) >> 4) << pin;
		port->OSPEEDR |= ((gpio_ospeedr_mask & function) >> 2) << (2 * pin);
		port->PUPDR |= ((gpio_pupdr_mask & function)) << (2 * pin);
		/**AFIO configuration**/
		port->AFR[0] |= (pin < 7) ? (alternate_function) << (pin - 1) * 4 : 0;
		port->AFR[1] |= (pin > 7) ? (alternate_function) << (pin - 1) * 4 : 0;

	}

	if (port == GPIOB) {

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
		/** pin setup **/
		port->MODER |= ((gpio_moder_mask & function) >> 5) << (2 * pin);
		port->OTYPER |= ((gpio_otyper_mask & function) >> 4) << pin;
		port->OSPEEDR |= ((gpio_ospeedr_mask & function) >> 2) << (2 * pin);
		port->PUPDR |= ((gpio_pupdr_mask & function)) << (2 * pin);
		/**AFIO configuration**/
		port->AFR[0] |= (pin < 7) ? (alternate_function) << (pin - 1) * 4 : 0;
		port->AFR[1] |= (pin > 7) ? (alternate_function) << (pin - 1) * 4 : 0;

	}

	if (port == GPIOC) {

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
		/** pin setup **/
		port->MODER |= ((gpio_moder_mask & function) >> 5) << (2 * pin);
		port->OTYPER |= ((gpio_otyper_mask & function) >> 4) << pin;
		port->OSPEEDR |= ((gpio_ospeedr_mask & function) >> 2) << (2 * pin);
		port->PUPDR |= ((gpio_pupdr_mask & function)) << (2 * pin);
		/**AFIO configuration**/
		port->AFR[0] |= (pin < 7) ? (alternate_function) << (pin - 1) * 4 : 0;
		port->AFR[1] |= (pin > 7) ? (alternate_function) << (pin - 1) * 4 : 0;

	}

	if (port == GPIOD) {

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
        /** pin setup **/
		port->MODER |= ((gpio_moder_mask & function) >> 5) << (2 * pin);
		port->OTYPER |= ((gpio_otyper_mask & function) >> 4) << pin;
		port->OSPEEDR |= ((gpio_ospeedr_mask & function) >> 2) << (2 * pin);
		port->PUPDR |= ((gpio_pupdr_mask & function)) << (2 * pin);
		/**AFIO configuration**/
		port->AFR[0] |= (pin < 7) ? (alternate_function) << (pin - 1) * 4 : 0;
		port->AFR[1] |= (pin > 7) ? (alternate_function) << (pin - 1) * 4 : 0;

	}
}

void gpio_write(GPIO_TypeDef *port, uint32_t pin, bool state) {

	/** The BSRR is the bit set reset reg.
	 * write to its first 16 bits to set a particular pin.
	 * write to the next 16 bits to reset it.
	 * the bool state governs weather you wish to set or reset,
	 * specified pin on specified port.
	 */

	gpio_init(port, gpio_output_pushpull, pin, 0);
	if(state)
		port->BSRR |= 0x1UL << pin;
	else
		port->BSRR |= 0x1UL << (16 + pin);
}

void gpio_toggle(GPIO_TypeDef *port, uint32_t pin, int delay) {

	/**User defined variable delay is used to toggle between states.
	 * delay defines half the period i.e T/2.
	 * thus the frequency is 1/(2*delay).
	 * specified pin at specified port are toggled
	 * function has been verified with D12 on stm32f407vg discovery board
	 * **/

	gpio_write(port, pin, 1);
	HAL_Delay(delay);
	gpio_write(port, pin, 0);
	HAL_Delay(delay);
}

int gpio_read(GPIO_TypeDef *port, uint32_t pin) {
	gpio_init(port, gpio_input_floating, pin, 0);
	return (((port->IDR) | (1 >> pin)) >> pin);
}


