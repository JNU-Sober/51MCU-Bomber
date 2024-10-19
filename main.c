#include <STC89C5xRC.H>
#include "MetrixKey.h"
#include "LCD1602.h"
#include "Delay.h"
#include "bomb.h"
sbit beep=P2^5;

void main()
{
	unsigned int k=0;	//k�ǰ���������
	unsigned int i=0;	//i������λ����¼��
	unsigned int p=0;	//����ʱģ���¼ʱ��
	unsigned int r=0;
	unsigned int j=0;	//j������ȶ���
	unsigned int password[7]={0,0,0,0,0,0,0};
	unsigned int correct[7]={7,3,5,5,6,0,8};//��ȷ������
	LCD_Init();//��ʼ��LCD
	while(1)
	{
		LCD_ShowString(1,1,"Enter password:");
		k=MetrixKey();
		if(i<=6 && k!=10 && k<=10)//i����6ʱ�������ٽ������ݣ�û�а��¼�ʱ���������ݣ�ֻ����0-9������
		{
				password[i]=k;
				if(password[i]!=10)//10����ָ�����������10�����Ǳ�ʾ�գ������MetrixKey.c��
				{
						LCD_ShowNum(2,i+1,password[i],1);//�����������������
						i++;//ÿ����һλ�����±��1
						for(j=0;j<=50;j++)//������ÿ��1ms��һ�Σ�����50ms
							{
								beep=!beep;
								Delay(1);
							}
				}
		}
//�������12����������
		if(k==12)
		{
			for(r=0;r<=6;r++)
			{password[r]=0;}//����λ������0
			i=0;LCD_Init();//��¼��i��0����ʾ������
		}
//�������11��ȷ������
			if(k==11)
			{
				j=0;i=0;p=0;//��������ȶ���������λ����¼����ʱ���¼��
				for(r=0;r<7;r++)//�ж�����������Ƿ���趨������ͬ
				{
					if(password[r]==correct[r])
						j++;
				}
				LCD_Init();//����
				if(j==7)//j=7��ʾ������ȷ
				{
					LCD_ShowString(1,1,"Bomb has");
					LCD_ShowString(2,1,"been planted");
					Delay(2000);//2s����ʾ��һ����ʾ
					bomb(0);
				}
				else //�������
				{
					LCD_ShowString(1,1,"*Error!*");
					Delay(2000);
					i=0;//��������λ����¼��
					LCD_Init();//����
				}	
			}
	}
}