#ifndef __I2C_H_
#define __I2C_H_

/*I2C 从设备*/
//#include "AT24C02.h"
#include "MPU6050.h"

/*I2C 时钟线数据线位定义*/
sbit SCL=P2^1;
sbit SDA=P2^0;

/*I2C 基本操作函数*/
void I2cStart();
void I2cStop();
unsigned char I2cSendByte(unsigned char dat);
unsigned char I2cReadByte();

/*I2C 直接调用函数*/
void I2CWrite(unsigned char dev,unsigned char addr,unsigned char dat);
unsigned char I2CRead(unsigned char dev,unsigned char addr);

#endif