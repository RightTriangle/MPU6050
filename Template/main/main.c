#include <reg52.h>      //使用的芯片头文件
#include "mytype.h"     
#include "delay.h"
#include "jz.h"
#include "DigDisplay.h"
#include "i2c/i2c.h"

#include "Init.c"
#include "MPUinit.c"

#define		_2000_2g

int main()
{
    MPUinit();
	Timer0Init();
#if 0
    while(1)            //死循环
    {  
	   DigDisplay();
	   while(keyHandle() == 13)
	   {
	   	led = !led;
		//delayms(1000);
	   }
    }
#elif 0
	while(1)
	{	
		if(keyHandle() != i)
		{
		DisplayData[0]=smgduan[i];
		}
		DigDisplay();
	}
#elif 0
	while(1)
	{
		switch (keyHandle())
		{
			case 1:{DisplayData[0]=smgduan[1];break;}
			case 2:{DisplayData[0]=smgduan[2];break;}
			case 3:{DisplayData[0]=smgduan[3];break;}
		}
		DigDisplay();
	}
#elif 0
	while(1)
	{
		if(a)
		{num = GYRO_XOUT/GYRO_SENS;a=0;}
		DigDisplay();
	}

#elif 1
	while(1)
	{		
			switch (keyHandle())
			{
				case 1:{num = ACCEL_XOUT/ACCEL_SENS;a=0;break;}
				case 2:{num = ACCEL_YOUT/ACCEL_SENS;a=0;break;}
				case 3:{num = ACCEL_ZOUT/ACCEL_SENS;a=0;break;}
				case 4:{num = TEMP_OUT/3.40+3653;a=0;break;}
				case 5:{num = GYRO_XOUT/GYRO_SENS;a=0;break;}
				case 6:{num = GYRO_YOUT/GYRO_SENS;a=0;break;}
				case 7:{num = GYRO_ZOUT/GYRO_SENS;a=0;break;}

			}
			DigDisplay();
	}
	
#endif
return 0;
}



/*中断*/
void Timer0() interrupt 1
{
	static u16 i;
	TH0=0XFC;	//给定时器赋初值，定时1ms
	TL0=0X18;
	i++;
	if(i==500)
	{
		i=0;
		a = 1;	
//		num = ACCEL_ZOUT/1.6384;
		if(num>=0)
		{
			DisplayData[0]=0;
			DisplayData[1]=smgduan[num/1000000];
			DisplayData[2]=smgduan[num%1000000/100000];			
			DisplayData[3]=smgduan[num%100000/10000]|0x80;
			DisplayData[4]=smgduan[num%10000/1000];		
			DisplayData[5]=smgduan[num%1000/100];	
			DisplayData[6]=smgduan[num%100/10];
			DisplayData[7]=smgduan[num%10];	
		}
		else
		{
			num = -num;
			DisplayData[0]=0x40;
			DisplayData[1]=smgduan[num/1000000];
			DisplayData[2]=smgduan[num%1000000/100000];			
			DisplayData[3]=smgduan[num%100000/10000]|0x80;
			DisplayData[4]=smgduan[num%10000/1000];		
			DisplayData[5]=smgduan[num%1000/100];	
			DisplayData[6]=smgduan[num%100/10];
			DisplayData[7]=smgduan[num%10];	
		}		
	}	
}