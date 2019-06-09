#include <reg52.h>
#include "i2c/i2c.h"
#include "delay.h"

/*I2C��ʼ�ź�*/
void I2cStart()
{
	SDA=1;
	delay10us();
	SCL=1;
	delay10us();//����ʱ����SDA����ʱ��>4.7us
	SDA=0;
	delay10us();//����ʱ����>4us
	SCL=0;			
	delay10us();		
}

/*I2C��ֹ�ź�*/
void I2cStop()
{
	SDA=0;
	delay10us();
	SCL=1;
	delay10us();//����ʱ�����4.7us
	SDA=1;
	delay10us();		
}

/*ͨ��I2C����һ���ֽ�*/
unsigned char I2cSendByte(unsigned char dat)
{
	unsigned char a=0,b=0;//���255��һ����������Ϊ1us�������ʱ255us��		
	for(a=0;a<8;a++)//Ҫ����8λ�������λ��ʼ
	{
		SDA=dat>>7;	//��ʼ�ź�֮��SCL=0�����Կ���ֱ�Ӹı�SDA�ź�
		dat=dat<<1;
		delay10us();
		SCL=1;
		delay10us();//����ʱ��>4.7us
		SCL=0;
		delay10us();//ʱ�����4us		
	}
	SDA=1;
	delay10us();
	SCL=1;
	while(SDA)//�ȴ�Ӧ��Ҳ���ǵȴ����豸��SDA����
	{
		b++;
		if(b>200)	 //�������2000usû��Ӧ����ʧ�ܣ�����Ϊ��Ӧ�𣬱�ʾ���ս���
		{
			SCL=0;
			delay10us();
			return 0;
		}
	}
	SCL=0;
	delay10us();
 	return 1;		
}

/*ͨ��I2C��ȡһ���ֽ�*/
unsigned char I2cReadByte()
{
	unsigned char a=0,dat=0;
	SDA=1;			//��ʼ�ͷ���һ���ֽ�֮��SCL����0
	delay10us();
	for(a=0;a<8;a++)//����8���ֽ�
	{
		SCL=1;
		delay10us();
		dat<<=1;
		dat|=SDA;
		delay10us();
		SCL=0;
		delay10us();
	}
	return dat;		
}

/*��ĳ���豸��һ����ַд��һ������*/
void I2CWrite(unsigned char dev,unsigned char addr,unsigned char dat)
{
	I2cStart();
	I2cSendByte(dev);//����д������ַ
	I2cSendByte(addr);//����Ҫд���ڴ��ַ
	I2cSendByte(dat); //��������
	I2cStop();
}

/*��ȡĳ���豸��һ����ַ��һ������*/
unsigned char I2CRead(unsigned char dev,unsigned char addr)
{
	unsigned char num;
	I2cStart();
	I2cSendByte(dev); //����д������ַ
	I2cSendByte(addr); //����Ҫ��ȡ�ĵ�ַ
	I2cStart();
	I2cSendByte(dev+1); //���Ͷ�������ַ
	num=I2cReadByte(); //��ȡ����
	I2cStop();
	return num;	
}
