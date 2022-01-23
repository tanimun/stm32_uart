#include "stm32f10x.h"                  // Device header

void USART2_write(int ch);
void delayMs(int delay);

int main(void)
{
// Initialize GPIO PORT
	// initialize the clock for the GPIO and USART2
	RCC->APB2ENR |= 0x0004; // 0000 0100...//Enable clock for GPIOA
	RCC->APB1ENR |= 0x20000; //0010 0000 0000 0000 0000  Enable clock for USART2.... PIN17
	
	//Configure GPIOA2 as alternative function
	GPIOA ->CRL = 0x00004A00; // 0100 1010 0000 0000
	//Enable Tx and USART2.. both in CR1 Register
	USART2->CR1 |= 0x2000;
	USART2->CR1 |= 0x0008;
	//Set Baudrate to  9600 @16Mhz
	USART2->BRR = 0x0EA6;

while(1)
{	

	USART2_write('A');
	USART2_write('B');
	USART2_write('C');
	delayMs(50);
	
}
}

void USART2_write(int ch){

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

