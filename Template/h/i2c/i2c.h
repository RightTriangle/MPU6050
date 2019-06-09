#ifndef __I2C_H_
#define __I2C_H_

/*I2C ���豸*/
//#include "AT24C02.h"
#include "MPU6050.h"

/*I2C ʱ����������λ����*/
sbit SCL=P2^1;
sbit SDA=P2^0;

/*I2C ������������*/
void I2cStart();
void I2cStop();
unsigned char I2cSendByte(unsigned char dat);
unsigned char I2cReadByte();

/*I2C ֱ�ӵ��ú���*/
void I2CWrite(unsigned char dev,unsigned char addr,unsigned char dat);
unsigned char I2CRead(unsigned char dev,unsigned char addr);

#endif