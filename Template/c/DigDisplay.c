/**************************************************************************************
��������õ���ģ����ʾ�����Խ�74HC595ģ���ϵ�JP595�̽�Ƭ�ε���																				  
***************************************************************************************/
#include <reg52.h>
#include "DigDisplay.h"
#include "delay.h"
#include "mytype.h"			 //�Ѱ���delay.h

extern u8 DisplayData[8]={0,0,0,0,0,0,0,0};

extern u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//��ʾ0~F��ֵ	0x40Ϊ���ţ�0x80ΪС���㡣

void DigDisplay()	 //DisplayData[x]=smgduan[num];
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��1λ	
			case(1):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��2λ
			case(2):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��3λ
			case(3):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(4):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��5λ
			case(5):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��6λ
			case(6):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��7λ
			case(7):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��8λ		
		}
		P0=DisplayData[i];//���Ͷ���
		delayms(1); //���һ��ʱ��ɨ��								  //�Ķ�
		P0=0x00;//����
	}
}

//void datapros()
//{
//	DisplayData[0]=smgduan[num/1000];//ǧλ
//	DisplayData[1]=smgduan[num%1000/100];//��λ
//	DisplayData[2]=smgduan[num%1000%100/10];//ʮλ
//	DisplayData[3]=smgduan[num%10];//��λ		
//}