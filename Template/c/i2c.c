#include <reg52.h>
#include "i2c/i2c.h"
#include "delay.h"

/*I2C启始信号*/
void I2cStart()
{
	SDA=1;
	delay10us();
	SCL=1;
	delay10us();//建立时间是SDA保持时间>4.7us
	SDA=0;
	delay10us();//保持时间是>4us
	SCL=0;			
	delay10us();		
}

/*I2C终止信号*/
void I2cStop()
{
	SDA=0;
	delay10us();
	SCL=1;
	delay10us();//建立时间大于4.7us
	SDA=1;
	delay10us();		
}

/*通过I2C发送一个字节*/
unsigned char I2cSendByte(unsigned char dat)
{
	unsigned char a=0,b=0;//最大255，一个机器周期为1us，最大延时255us。		
	for(a=0;a<8;a++)//要发送8位，从最高位开始
	{
		SDA=dat>>7;	//起始信号之后SCL=0，所以可以直接改变SDA信号
		dat=dat<<1;
		delay10us();
		SCL=1;
		delay10us();//建立时间>4.7us
		SCL=0;
		delay10us();//时间大于4us		
	}
	SDA=1;
	delay10us();
	SCL=1;
	while(SDA)//等待应答，也就是等待从设备把SDA拉低
	{
		b++;
		if(b>200)	 //如果超过2000us没有应答发送失败，或者为非应答，表示接收结束
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

/*通过I2C读取一个字节*/
unsigned char I2cReadByte()
{
	unsigned char a=0,dat=0;
	SDA=1;			//起始和发送一个字节之后SCL都是0
	delay10us();
	for(a=0;a<8;a++)//接收8个字节
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

/*向某从设备的一个地址写入一个数据*/
void I2CWrite(unsigned char dev,unsigned char addr,unsigned char dat)
{
	I2cStart();
	I2cSendByte(dev);//发送写器件地址
	I2cSendByte(addr);//发送要写入内存地址
	I2cSendByte(dat); //发送数据
	I2cStop();
}

/*读取某从设备的一个地址的一个数据*/
unsigned char I2CRead(unsigned char dev,unsigned char addr)
{
	unsigned char num;
	I2cStart();
	I2cSendByte(dev); //发送写器件地址
	I2cSendByte(addr); //发送要读取的地址
	I2cStart();
	I2cSendByte(dev+1); //发送读器件地址
	num=I2cReadByte(); //读取数据
	I2cStop();
	return num;	
}
