#include <stdint.h>
#include "irq_handler.h"

extern bool user_button_pressed;

void EXTI0_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 0 ))
	{
		EXTI->PR |= ( 1 << 0 );
	}
}

void EXTI1_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 1 ))
	{
		EXTI->PR |= ( 1 << 1 );
	}
}

void EXTI2_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 2 ))
	{
		EXTI->PR |= ( 1 << 2 );
	}
}

void EXTI3_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 3 ))
	{
		EXTI->PR |= ( 1 << 3 );
	}
}

void EXTI4_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 4 ))
	{
		EXTI->PR |= ( 1 << 4 );
	}
}

void EXTI9_5_IRQHandler()
{
	if ( EXTI->PR & ( 1 << 5 ))
	{
		EXTI->PR |= ( 1 << 5 );
	}
	if ( EXTI->PR & ( 1 << 6 ))
	{
		EXTI->PR |= ( 1 << 6 );
	}
	if ( EXTI->PR & ( 1 << 7 ))
	{
		EXTI->PR |= ( 1 << 7 );
	}
	if ( EXTI->PR & ( 1 << 8 ))
	{
		EXTI->PR |= ( 1 << 8 );
	}
	if ( EXTI->PR & ( 1 << 9 ))
	{
		EXTI->PR |= ( 1 << 9 );
	}
}

void EXTI15_10_IRQHandler()
{
	// Check to see which Interrupt was Triggered
	if ( EXTI->PR & ( 1 << 10 ))
	{
		EXTI->PR |= ( 1 << 10 );
	}
	if ( EXTI->PR & ( 1 << 11 ))
	{
		EXTI->PR |= ( 1 << 11 );
	}
	if ( EXTI->PR & ( 1 << 12 ))
	{
		EXTI->PR |= ( 1 << 12 );
	}
	if ( EXTI->PR & ( 1 << 13 ))
	{
		user_button_pressed = TRUE;
		EXTI->PR |= ( 1 << 13 );
	}
	if ( EXTI->PR & ( 1 << 14 ))
	{
		EXTI->PR |= ( 1 << 14 );
	}
	if ( EXTI->PR & ( 1 << 15 ))
	{
		EXTI->PR |= ( 1 << 15 );
	}
}
