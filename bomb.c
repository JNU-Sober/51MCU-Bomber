#include "defuse.h"
#include "LCD1602.h"
#include "Delay.h"
#include <STC89C5xRC.H>
sbit beep=P2^5;

void bomb(unsigned int p)
{
				int j=0,q=0,r=0;
				LCD_Init();//清屏
				LCD_ShowString(1,1,"Bomb explodes");
				LCD_ShowString(2,1,"after");
				LCD_ShowString(2,15,"s");
//倒计时模块
				while(p>=0)//计数器p以ms为单位
				{
					//p=0，即第0s
					if(p/1000<=14)//1000ms为一个周期，其中100ms蜂鸣器响，900ms不响，计数器加1
					{
						LCD_ShowNum(2,13,40-p/1000,2);
						for(j=0;j<100;j++)
						{
							beep=!beep;
							Delay(1);
						}
						Delay(900);
						p=p+1000;
					}
					//p=15000，即第15s执行到这个位置（下面同理）
					if(15<=p/1000 && p/1000<=23)//500ms为一个周期，其中100ms蜂鸣器响，400ms不响，两个周期才为1s,计数器才加1（下面同理）
					{
						LCD_ShowNum(2,13,40-p/1000,2);
						for(j=0;j<100;j++)
						{
							beep=!beep;
							Delay(1);
						}
						Delay(400);
						q++;
						if(q%2==0 && q!=0)
						{
							p=p+1000;
							if(p/1000==24) q=0;
						}
					}
					//p=24000
					if(24<=p/1000 &&p/1000<=29)
						{
							LCD_ShowNum(2,13,40-p/1000,2);
							for(j=0;j<100;j++)
								{
									beep=!beep;
									Delay(1);
								}
							Delay(150);
							q++;
							if(q%4==0 && q!=0)
							{
								p=p+1000;
								if(p/1000==30) q=0;
							}
						}
						//p=30000
						if(30<=p/1000 && p/1000<=35)
						{
							LCD_ShowNum(2,13,40-p/1000,2);	
							for(j=0;j<100;j++)
								{
									beep=!beep;
									Delay(1);
								}
								Delay(100);
								q++;
								if(q%5==0 && q!=0)
								{
									p=p+1000;
									if(p/1000==36) q=0;
								}
						}
						//p=36000
						if(36<=p/1000 && p/1000<=40)
						{
							LCD_ShowNum(2,13,40-p/1000,2);
							for(j=0;j<50;j++)
								{
									beep=!beep;
									Delay(1);
								}
							Delay(50);
							q++;
							if(q%10==0 && q!=0)
							{
								p=p+1000;
							}
						}
						//p=40000
						if(p/1000>40)
						{
								LCD_Init();//清屏
								LCD_ShowString(1,1,"Bomb exploded");
								LCD_ShowString(2,1,"Terrorists Win");
								while(1);//爆炸后始终显示上面文字
						}
					
//拆弹模块
					if(P31==0)
					{
							Delay(20);
							while(P31==0);
							Delay(20);
							r=defuse(p);//K0按下表示拆弹
							p+=r;
							if(r)
							{
								LCD_Init();//清屏
								LCD_ShowString(1,1,"Bomb has been");
								LCD_ShowString(2,1,"defused");
								Delay(2000);
								LCD_Init();//清屏
								LCD_ShowString(1,1,"Counter");
								LCD_ShowString(2,1,"Terrorists Win");
								while(1);
							}
					}			
					
				}
}