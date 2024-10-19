#include <STC89C5xRC.H>
#include "MetrixKey.h"
#include "LCD1602.h"
#include "Delay.h"
#include "bomb.h"
sbit beep=P2^5;

void main()
{
	unsigned int k=0;	//k是按键接收器
	unsigned int i=0;	//i是密码位数记录器
	unsigned int p=0;	//倒计时模块记录时间
	unsigned int r=0;
	unsigned int j=0;	//j是密码比对器
	unsigned int password[7]={0,0,0,0,0,0,0};
	unsigned int correct[7]={7,3,5,5,6,0,8};//正确的密码
	LCD_Init();//初始化LCD
	while(1)
	{
		LCD_ShowString(1,1,"Enter password:");
		k=MetrixKey();
		if(i<=6 && k!=10 && k<=10)//i大于6时不允许再接受数据，没有按下键时不接受数据，只接受0-9的输入
		{
				password[i]=k;
				if(password[i]!=10)//10不是指输入的数据是10，而是表示空，详见“MetrixKey.c”
				{
						LCD_ShowNum(2,i+1,password[i],1);//以数组存放输入的密码
						i++;//每输入一位密码下标加1
						for(j=0;j<=50;j++)//蜂鸣器每隔1ms震动一次，持续50ms
							{
								beep=!beep;
								Delay(1);
							}
				}
		}
//如果按下12，密码清零
		if(k==12)
		{
			for(r=0;r<=6;r++)
			{password[r]=0;}//将各位密码清0
			i=0;LCD_Init();//记录器i清0，显示屏清零
		}
//如果按下11，确认密码
			if(k==11)
			{
				j=0;i=0;p=0;//重置密码比对器、密码位数记录器、时间记录器
				for(r=0;r<7;r++)//判断输入的密码是否和设定密码相同
				{
					if(password[r]==correct[r])
						j++;
				}
				LCD_Init();//清屏
				if(j==7)//j=7表示密码正确
				{
					LCD_ShowString(1,1,"Bomb has");
					LCD_ShowString(2,1,"been planted");
					Delay(2000);//2s后显示下一个提示
					bomb(0);
				}
				else //密码错误
				{
					LCD_ShowString(1,1,"*Error!*");
					Delay(2000);
					i=0;//重置密码位数记录器
					LCD_Init();//清屏
				}	
			}
	}
}