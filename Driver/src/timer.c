
#include "timer.h"

/***************************************************************
** 函数名称: Timer0Init
** 功能描述: 计数器0初始化函数-对外部脉冲计数
** 输　入:   
** 输　出:   
** 全局变量: 
** 作　者:   喵呜实验室
** 淘  宝：  Http://miaowlabs.taobao.com
** 日　期:   2014年08月01日
***************************************************************/
void Timer0Init(void)		
{
	//	AUXR |= 0x80;  //定时器0为1T模式
	AUXR &= 0x7f;  //定时器0为12T模式
	TMOD = 0x00;  //设置定时器为模式0-16位自动重装载)
	TL0 = 0x95 ;  //初始化计时值 65429 33M/12/(65536-65429)/2=12800HZ
	TH0 = 0xff ;
	TF0 = 0; 
	TR0 = 1;  //定时器0开始计时
	//ET0 = 1;  //中断使能
}


/***************************************************************
** 函数名称: Timer1Init
** 功能描述: 定时器1初始化函数
** 输　入:   
** 输　出:   
** 全局变量: 
** 作　者:   喵呜实验室
** 淘  宝：  Http://miaowlabs.taobao.com
** 日　期:   2014年08月01日
***************************************************************/
void Timer1Init(void)	//10毫秒@20.000MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
//	TL1 = 0xEB;		//设置定时初值
//	TH1 = 0xCB;		//设置定时初值
	TL1 = 0xE5;		//设置定时初值
	TH1 = 0xBE;		//设置定时初值10MS
	TF1 = 0;			//清除TF1标志
	TR1 = 1;			//定时器1开始计时
	ET1 = 1;        	//允许定时器T1中断	  
}


void Timer2Init()	
{
  AUXR |= 0x04;			
	T2L = 0xEB;	
	T2H = 0xFF;
	AUXR |= 0x10;		
}



