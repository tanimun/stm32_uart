

#include "stm32f10x.h"                  // Device header

void USART2_write(int ch);
void delayMs(int delay);

int main(void)
{
	char a[] = {"Apu Bhai? Haa bhai"};
	
	RCC->APB2ENR |= 0x0004;
	RCC->APB1ENR |= 0x20000;
	
	GPIOA ->CRL= 0x00004A00;
	
	USART2->CR1 |= 0x2000;
	USART2->CR1 |= 0x0008;
	
	USART2->BRR = 0x0EA6;
	
	while(1)
	{
		for(int i=0; a[i]!=0; i++)
		{
			USART2_write(a[i]);
		}
			delayMs(50);
	
	}
}

void USART2_write (int ch)
	{

while(!(USART2 ->SR & 0x0080)){}
		USART2 ->DR = (ch & 0xFF);
}
	void delayMs(int delay)
{
	int i;
	for(; delay>0;delay--)
	{
		for(i = 0; i<3195; i++);
	}
}
