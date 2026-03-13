#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "OLED.h"
#include "Delay.h"

int main(void)
{
	LED_Init();
	OLED_Init();
	
//	face_0();
//	OLED_Update();
//	Delay_ms(2000);
//	OLED_Clear();
//	face_1();
//	OLED_Update();
//	Delay_ms(2000);
//	OLED_Clear();
//	face_2();
//	OLED_Update();
//	Delay_ms(2000);
//	OLED_Clear();
//	face_3();
//	OLED_Update();
//	Delay_ms(2000);

	while(1)
	{
		
		
		GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
	}
}

