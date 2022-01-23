#include "stm32f10x.h"                  // Device header
char USART2_read(void);
void USART2_write(int ch);
char USART2_read(void);
void delayMs(int delay);

int main(void)
{
char ch;
	
	
RCC->APB2ENR |= 0x0004;
RCC->APB1ENR |= 0x20000;

GPIOA -> CRL =0x00004A00;
	
	USART2->CR1 |= 0x2000;
	USART2->CR1 |= 0x000c;
	
	USART2->BRR = 0x0EA6;
	
	while(1)
	{
		ch = USART2_read();
		USART2_write(ch);
		delayMs(50);
	}
}
void USART2_write(int ch){
//wait while tx buffer is empty
	while(!(USART2 ->SR & 0x0080)){}
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
