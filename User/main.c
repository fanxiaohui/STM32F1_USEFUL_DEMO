/**
  ******************************************************************************
  * @file    main.c
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   main
  ******************************************************************************
  * @attention 此demo是无RTOS版本，需要RTOS的demo请关注杰杰的GitHub：
  *	GitHub：https://github.com/jiejieTop
  *
  * 实验平台:野火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
#include "include.h"

/**
  ******************************************************************
													   变量声明
  ******************************************************************
  */

Button_t Button1;
Button_t Button2;

/**
  ******************************************************************
														函数声明
  ******************************************************************
  */
static void BSP_Init(void);

void Btn1_Dowm_CallBack(void *btn)
{
	PRINTF_INFO("Button1 单击!\r\n");
}

void Btn1_Double_CallBack(void *btn)
{
	PRINTF_INFO("Button1 双击!\r\n");
}

void Btn1_Long_CallBack(void *btn)
{
	PRINTF_INFO("Button1 长按!\r\n");
}
void Btn1_Long_Free_CallBack(void *btn)
{
	PRINTF_INFO("Button1 长按松开!\r\n");
}
void Btn1_Continuos_CallBack(void *btn)
{
	PRINTF_INFO("Button1 连按!\r\n");
}
void Btn1_ContinuosFree_CallBack(void *btn)
{
	PRINTF_INFO("Button1 连按释放!\r\n");
}

void Btn2_Dowm_CallBack(void *btn)
{
	PRINTF_INFO("Button2 单击!\r\n");
}

void Btn2_Double_CallBack(void *btn)
{
	PRINTF_INFO("Button2 双击!\r\n");
}

void Btn2_Long_CallBack(void *btn)
{
	PRINTF_INFO("Button2 长按!\r\n");
}
void Btn2_Long_Free_CallBack(void *btn)
{
	PRINTF_INFO("Button2 长按松开!\r\n");
}
void Btn2_Continuos_CallBack(void *btn)
{
	PRINTF_INFO("Button2 连按!\r\n");
}
void Btn2_ContinuosFree_CallBack(void *btn)
{
	PRINTF_INFO("Button2 连按释放!\r\n");
}

/**
  ******************************************************************
  * @brief   主函数
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  ******************************************************************
  */
int main(void)
{
	//  BSP_Init();
	CPU_TS_TmrInit();
	USART_Config();
	LED_GPIO_Config();
	Key_Init();
	Button_Create("Button1",
				  &Button1,
				  Read_Key1,
				  KEY_ON);
	Button_Attach(&Button1, BUTTON_DOWN, Btn1_Dowm_CallBack);			//单击
	Button_Attach(&Button1, BUTTON_DOUBLE, Btn1_Double_CallBack);		//双击
	Button_Attach(&Button1, BUTTON_LONG, Btn1_Long_CallBack);			//长按
	Button_Attach(&Button1, BUTTON_LONG_FREE, Btn1_Long_Free_CallBack); //长按松开

	Button_Create("Button2",
				  &Button2,
				  Read_Key2,
				  KEY_ON);
	Button_Attach(&Button2, BUTTON_DOWN, Btn2_Dowm_CallBack);	  //单击
	Button_Attach(&Button2, BUTTON_DOUBLE, Btn2_Double_CallBack); //双击
	Button_Attach(&Button2, BUTTON_LONG, Btn2_Long_CallBack);	  //长按
	Button_Attach(&Button2, BUTTON_LONG_FREE, Btn2_Long_Free_CallBack);
	Get_Button_Event(&Button1);
	Get_Button_Event(&Button2);
	PRINTF_INFO("welcome to learn stm32 library!\r\n");
	while (1)
	{

		//PRINTF_INFO("key value :%d!\r\n",Touch_Key_Analysis());
		Button_Process(); //需要周期调用按键处理函数
		Delay_ms(10);
		LED1_TOGGLE;
	}
}

/**
  ******************************************************************
  * @brief   BSP_Init，用于所有板级初始化
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  ******************************************************************
  */
//static void BSP_Init(void)
//{
//	/* LED 初始化 */
//	LED_GPIO_Config();

//#if USE_DWT_DELAY
//	/* 内核精确定时器初始化 */
//	CPU_TS_TmrInit();
//#else
//	/* 滴答定时器初始化 */
//	SysTick_Init();
//#endif

//	/* 串口初始化 */
//	USART_Config();

//	/* 按键初始化 */
//	Key_GPIO_Config();

//	//	/* 外部中断初始化 */
//	//	EXTI_Key_Config();

//	CRC_Config();

//	/* 打印信息 */
//	PRINTF_INFO("welcome to learn stm32 library!\r\n");
//}

/********************************END OF FILE***************************************/
