#include "stm32f10x.h"                  // Device header
#include "LED.h"

int main(void)
{
	LED_Init();
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
	}
}

