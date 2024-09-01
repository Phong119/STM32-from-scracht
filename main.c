//#include <stm32f10x.h>
#include "src.h"
#include <system_stm32f10x.h>
void GPIO_PC13();
void Delay_ms ();
void GPIO_INPUT ();
uint32_t count = 0;

int main (){
	GPIO_PC13();
	GPIO_INPUT();
	//while(1){ // loop blink led
	//	GPIO_PORTC->GPIO_ODR |= 0x2000; // push 13 as 1
	//	Delay_ms ();
	//	GPIO_PORTC->GPIO_ODR &= ~0x2000; //push 13 as 0
	//	Delay_ms ();
	//}
	
	while (1){
		
		if (GPIO_PORTA ->GPIO_IDR & 0x1 || GPIO_PORTB ->GPIO_IDR & 0x1)
			{
			GPIO_PORTC->GPIO_ODR |= 0x2000;	
		}
			
		else		
			{	
		
				GPIO_PORTC->GPIO_ODR &= ~0x2000;
		}
	}
}
void GPIO_PC13(void)
{
	BASE_RCC->APB2ENR |= 0x10; // enable CLOCK PORT C
	GPIO_PORTC->GPIO_CRH &= 0xFF0FFFFF; // RESET CAP chan 13 ve 0 ( CFN13 & MODE 13 )
	GPIO_PORTC->GPIO_CRH |= 0x00300000; // "11" OUTPUT MODE WITH 50HMz

}
void GPIO_INPUT(void){
	BASE_RCC->APB2ENR |= 0x4; // enable clock PORT A (PA1)
	GPIO_PORTA->GPIO_CRL &= 0xFFFFFF0F; // clear bit in CRL MODE 
	GPIO_PORTA->GPIO_CRL |=(1<<8); //select input pull up / pull down
	GPIO_PORTA->GPIO_ODR |=(1<<1);
	
	BASE_RCC->APB2RSTR |= (1<<3);
	GPIO_PORTB->GPIO_CRL &= 0xFFFFFF0F;
	GPIO_PORTB->GPIO_CRL |=(1<<8); //select input pull up / pull down
	GPIO_PORTB->GPIO_ODR |=(1<<1);
}

	
void Delay_ms(void){
	for (int  i =0 ; i<100000;i++)
{}
}



#include "src.h"
void GPIO_CONFIG();
void Delay_ms();
int main (){
	GPIO_CONFIG();
	Delay_ms();
	while(1){
		GPIO_PORTC->GPIO_ODR |= (1<<13);
		Delay_ms();
		GPIO_PORTC ->GPIO_ODR &= ~(1<<13);
	}
}

void GPIO_CONFIG(){
	// PORT C CONFIG
	BASE_RCC->APB2ENR |= (1<<4); // TRUE
	// CONFIG GPIO
	GPIO_PORTC->GPIO_CRH &= 0; //RESET TO 0     TRUE
	GPIO_PORTC->GPIO_CRH |= (3>>12); // CONFIG CNF, MODE (50Mhz)
	
}

void Delay_ms(void){
	for (int  i =0 ; i<100000;i++)
{}
}