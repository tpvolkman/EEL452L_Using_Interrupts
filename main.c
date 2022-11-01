/**
 * Main program.
 */

#include "main.h"

bool user_button_pressed = FALSE;

#define LED_TIMER 	500000

int main(void) 
{
	// Enable GPIO Port A Clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA;

	// Enable GPIO Port B Clock 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOB;

	// Enable GPIO Port C Clock 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOC;
	
	// Initialize GPIOA Port, Pin 5
	// Set GPIO Port A, Bit 5 as a General Purpose Output
	GPIOA->MODER.bit11 = 0;
	GPIOA->MODER.bit10 = 1;
	
	// Set GPIO Port A, Bit 5 as an Output, Push-Pull
	GPIOA->OTYPER.bit5 = 0;
	
	// Set GPIO Port A, Bit 5 for Low Speed
	GPIOA->OSPEEDR.bit11 = 0;
	GPIOA->OSPEEDR.bit10 = 0;
	
	// Set GPIO Port A, Bit 5 for No Pull-Up, Pull-Down
	GPIOA->PUPDR.bit11 = 0;
	GPIOA->PUPDR.bit10 = 0;
	
	// Set GPI0 Port C, Bit 13 for Input
	GPIOC->MODER.bit27 = 0;
	GPIOC->MODER.bit26 = 0;
	
	// Set GPIO Port C, Bit 13 for Pull-Up
	GPIOC->PUPDR.bit27 = 0;
	GPIOC->PUPDR.bit26 = 1;
	
	// Enable the System Clock
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	// Enable GPIO13 Interrupt for GPIO Port C
	SYSCFG->EXTICR4 |= 0x00000020;
	
	// Set up Interrupt Handler for Interrupt 12 (Pin 13), Port C
	EXTI->FTSR &= 0xFFFFDFFF;
	EXTI->RTSR |= 0x00002000;
	EXTI->EMR &= 0xFFFFDFFF;
	EXTI->IMR |= 0x00002000; 
	
	// Enable Interrupt 40 in Nested Vector Interrupt Controller
	NVIC_EnableIRQ( EXTI15_10_IRQn );
	
	while (1)
	{	
		// User Button Flag is set in EXTI15_10_IRQHandler
		if ( user_button_pressed == TRUE )
		{
			// When button is pressed, toggle the Onboard LED
			if ( GPIOA->IDR.bit5 == 0 )
			{
				GPIOA->ODR.bit5 = 1;
			}
			else
			{
				GPIOA->ODR.bit5 = 0;
			}
			user_button_pressed = FALSE;
		}
	}
}
