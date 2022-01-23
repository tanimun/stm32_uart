#include "stm32f10x.h"                  // Device header
#include<stdio.h>

char USART2_read(void);
int USART2_write(int ch);
void delayMs(int delay);

int main(void)
{
		//char ch;
		int analogValue;
	  
	
		RCC->APB2ENR = 0x0204;
		RCC-> APB1ENR = 0x2000;

		GPIOA-> CRL = 0x00004A00;
	
		USART2->CR1 = 0x200C;
		USART2->BRR = 0x0EA6;
	
		RCC->CFGR = 0x8000;
		ADC1->SMPR2 = 0x0038;
		ADC1->SQR3 = 0x0003;
		ADC1-> CR2 = 0x0003;
		ADC1-> CR2 = 0x0003;
		ADC1->CR2 = 0x0007;
		ADC1->CR2|= 0x40000000;
	
while(1)
{
	ADC1->CR2 |=0x00400000;
	while(!(ADC1->SR & 2)){}
		analogValue = ADC1->DR;
			printf("Analog Value is:%d",analogValue);
			printf("\r\n");
			delayMs(50);
	
}
}
int USART2_write(int ch){

		while(!(USART2 -> SR & 0x0080)){}
					USART2 ->DR =(ch& 0xFF);		
}

char USART2_read(void){
//wait until char arrive
	
	while(!(USART2->SR & 0x0020)){}
				return USART2->DR;
}


void delayMs(int delay)
{
	for(; delay>0; delay--)
{
	for(int i = 0; i<5000; i++);
	}
}
