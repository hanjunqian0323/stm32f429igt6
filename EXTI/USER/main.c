#include "sys.h"
#include "exti.h"

void LED_Init(void);

int main()
{
  HAL_Init();                     //��ʼ��HAL��
  
  Stm32_Clock_Init(360,25,2,8);   //��ʼ��ϵͳʱ��Ϊ180M
  
  LED_Init();
  
  EXTI_Init();
  
  while(1)
  {
    
  }
}

void LED_Init(void)
{
  RCC->AHB1ENR = 1<<1;
  GPIO_InitTypeDef GPIOled_Init_struct;
  GPIOled_Init_struct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIOled_Init_struct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
  HAL_GPIO_Init(GPIOB,&GPIOled_Init_struct);
  GPIOB->ODR = 0XFF;
}





