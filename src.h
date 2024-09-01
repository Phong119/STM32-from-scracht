#include <stdio.h>
#include <stdint.h>

 typedef struct 
	 {
		volatile uint32_t RC;
		volatile uint32_t CFGR;
		volatile uint32_t CIR;
		volatile uint32_t APB2RSTR;
		volatile uint32_t APB1RSTR;
		volatile uint32_t AHBENR;
		volatile uint32_t APB2ENR;
		volatile uint32_t APB1ENR;
		volatile uint32_t BDCR;
		volatile uint32_t CSR;
		volatile uint32_t AHBRSTR;
		volatile uint32_t CFGR2;
	 }RCC_TYPE;
	
	typedef struct 
	{
		volatile	uint32_t GPIO_CRL;
		volatile	uint32_t GPIO_CRH;
		volatile	uint32_t GPIO_IDR;
		volatile	uint32_t GPIO_ODR;
		volatile	uint32_t GPIO_BSRR;
		volatile	uint32_t GPIO_BRR;
		volatile	uint32_t GPIO_LCKR;
	}GPIO_TYPE;
	
//clock	
	
#define BASE_RCC ((RCC_TYPE*)0x40021000)
	
	//PORT_DEFINE
#define GPIO_PORTA ((GPIO_TYPE*)0x40010800)
#define GPIO_PORTB ((GPIO_TYPE*)0x40010C00)
#define GPIO_PORTC ((GPIO_TYPE*)0x40011000)
#define GPIO_PORTD ((GPIO_TYPE*)0x40011400)
#define GPIO_PORTE ((GPIO_TYPE*)0x40011800)
#define GPIO_PORTF ((GPIO_TYPE*)0x40011C00)
#define GPIO_PORTG ((GPIO_TYPE*)0x40012000)
	
	//struct RCC_TYPE *MY_RRC =(struct RCC_TYPE *)RRC_ADDRESS;
	//struct GPIO_TYPE