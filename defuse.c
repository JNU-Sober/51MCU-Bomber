#include "LCD1602.h"
#include "Delay.h"
#include <STC89C5xRC.H>
sbit beep=P2^5;

unsigned int defuse(unsigned int p)
{
					int r=0;
					if(p<=36000)//���ڲ���Ҫ4s,��������pС��36000�������
							{
								LCD_Init();//����
								LCD_ShowString(1,1,"Defusing Bomb..");
								for(r=0;r<=16;r++)//ÿ250ms������ʾ�𵯽��ȣ���16�֣���4s
								{
									Delay(250);
									if(P30==0)//��;�а���K1��ʾȡ����
									{
										Delay(20);
										while(P30==0);
										Delay(20);
										LCD_Init();LCD_ShowString(1,1,"Defuse canceled");
										Delay(1000);
										LCD_Init();
										LCD_ShowString(1,1,"Bomb explodes");
										LCD_ShowString(2,1,"after");					
										LCD_ShowString(2,15,"s");
										break;
									}
									switch(r)
									{
										case 0:
										case 1:
										LCD_ShowString(2,1,"*");break;	
										case 2:
										LCD_ShowString(2,1,"**");break;
										case 3:
										LCD_ShowString(2,1,"***");break;	
										case 4:
										LCD_ShowString(2,1,"****");break;	
										case 5:
										LCD_ShowString(2,1,"*****");break;	
										case 6:
										LCD_ShowString(2,1,"******");break;	
										case 7:
										LCD_ShowString(2,1,"*******");break;	
										case 8:
										LCD_ShowString(2,1,"********");break;	
										case 9:
										LCD_ShowString(2,1,"*********");break;	
										case 10:
										LCD_ShowString(2,1,"**********");break;	
										case 11:
										LCD_ShowString(2,1,"***********");break;	
										case 12:
										LCD_ShowString(2,1,"************");break;	
										case 13:
										LCD_ShowString(2,1,"*************");break;	
										case 14:
										LCD_ShowString(2,1,"**************");break;	
										case 15:
										LCD_ShowString(2,1,"***************");break;	
										case 16:
										LCD_ShowString(2,1,"****************");break;
									}
								}
							}	
							else//������p����36000����ʣ��ʱ�䲻��4s,������𵯣������跴����ʾ
							{
								LCD_Init();//����
								LCD_ShowString(1,1,"You don't have");
								LCD_ShowString(2,1,"enough time!!!");
								Delay(1000);
								LCD_Init();//����
								LCD_ShowString(1,1,"GoodBye");
								LCD_ShowString(2,1,"my friend");
								Delay(1000);
							}
							if(r==16)
							{
								return 0;
							}
							else
							{
								return r*250;//16*250
							}
}