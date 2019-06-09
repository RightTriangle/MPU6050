/**************************************************************************************
如果不想让点阵模块显示，可以将74HC595模块上的JP595短接片拔掉。																				  
***************************************************************************************/
#include <reg52.h>
#include "DigDisplay.h"
#include "delay.h"
#include "mytype.h"			 //已包含delay.h

extern u8 DisplayData[8]={0,0,0,0,0,0,0,0};

extern u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值	0x40为负号，0x80为小数点。

void DigDisplay()	 //DisplayData[x]=smgduan[num];
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第1位	
			case(1):
				LSA=0;LSB=1;LSC=1; break;//显示第2位
			case(2):
				LSA=1;LSB=0;LSC=1; break;//显示第3位
			case(3):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第5位
			case(5):
				LSA=0;LSB=1;LSC=0; break;//显示第6位
			case(6):
				LSA=1;LSB=0;LSC=0; break;//显示第7位
			case(7):
				LSA=0;LSB=0;LSC=0; break;//显示第8位		
		}
		P0=DisplayData[i];//发送段码
		delayms(1); //间隔一段时间扫描								  //改动
		P0=0x00;//消隐
	}
}

//void datapros()
//{
//	DisplayData[0]=smgduan[num/1000];//千位
//	DisplayData[1]=smgduan[num%1000/100];//百位
//	DisplayData[2]=smgduan[num%1000%100/10];//十位
//	DisplayData[3]=smgduan[num%10];//个位		
//}