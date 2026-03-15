#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "OLED.h"
#include "Delay.h"
#include "Timer.h"

uint16_t NUM;

int main(void)
{
	LED_Init();
	OLED_Init();
	Timer_Init();
	
	OLED_ShowString(1,1,"NUM:",OLED_8X16);
	OLED_Update();
	
	while(1)
	{
		OLED_ShowNum(40,1,NUM,5,OLED_8X16);
		OLED_Update();
		GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
	}
}




void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
	{
		NUM++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

