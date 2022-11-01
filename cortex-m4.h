#ifndef _CORTEX_M4_H_
#define _CORTEX_M4_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f446.h"

/*!<NVIC Address */
#define NVIC_REGISTERS		(( uint32_t )0xE000E100UL )

#define NVIC				(( NVIC_TypeDef * )NVIC_REGISTERS )

typedef struct
{
	volatile uint32_t ISER[8U];		/*!< Interrupt Set Enable Register, 0xE000E100 - 0xE000E11C */
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];		/*!< Interrupt Clear Enable Register, 0xE000E180 - 0xE000E19C */
	uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8U];		/*!< Interrupt Set Pending Register */
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];		/*!< Interrupt Clear Pending Register */
	uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8U];		/*!< Interrupt Active Bit Register */
	uint32_t RESERVED4[24U];
	volatile uint32_t IP[8U];		/*!< Interrupt Priority Register */
	uint32_t RESERVED5[24U];
	volatile uint32_t STIR;			/*!< Software Trigger Interrupt Register */
} NVIC_TypeDef;

// Functional Prototypes
void NVIC_EnableIRQ( IRQ_Type irq_no );
void NVIC_DisableIRQ( IRQ_Type irq );

#endif