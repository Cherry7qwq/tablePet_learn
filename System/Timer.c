#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TimBaseInitStruct;
	TimBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TimBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TimBaseInitStruct.TIM_Period = 7200-1;              //速度->越小精度越高
	TimBaseInitStruct.TIM_Prescaler = 10000-1;          //长度->越大控制越细腻->PWM
	TimBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TimBaseInitStruct);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVICInitStructure;
	NVICInitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVICInitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVICInitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVICInitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVICInitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
};

