#ifndef __MPU6050_H_
#define __MPU6050_H_

/*设备地址宏定义*/
#define MPU6050 		0xD0	//AD0引脚为高电平时定义为0xD2

/*MPU6050寄存器宏定义*/
#define	SMPLRT_DIV		0x19	//25//陀螺仪输出率的分频，典型值0x07(1kHz)
#define	CONFIG			0x1A	//26//低通滤波频率,一般0x01~0x05,数值越大带宽越小延时越长
#define	GYRO_CONFIG		0x1B	//27//陀螺仪自检及配置满量程范围
#define	ACCEL_CONFIG	0x1C	//28//加速度仪自检及配置满量程范围

/////原始数据寄存器///////////////////
#define	ACCEL_XOUT_H	0x3B    //59//加速度计X轴数据高位
#define	ACCEL_XOUT_L	0x3C    //60//加速度计X轴数据低位
#define	ACCEL_YOUT_H	0x3D    //61//加速度计Y轴数据高位
#define	ACCEL_YOUT_L	0x3E	//62//加速度计Y轴数据低位
#define	ACCEL_ZOUT_H	0x3F	//63//加速度计Z轴数据高位
#define	ACCEL_ZOUT_L	0x40	//64//加速度计Z轴数据低位

#define	TEMP_OUT_H		0x41    //65//温度传感器数据高位
#define	TEMP_OUT_L		0x42	//66//温度传感器数据低位

#define	GYRO_XOUT_H		0x43    //67//陀螺仪X轴数据高位
#define	GYRO_XOUT_L		0x44	//68//陀螺仪X轴数据低位
#define	GYRO_YOUT_H		0x45	//69//陀螺仪Y轴数据高位
#define	GYRO_YOUT_L		0x46	//70//陀螺仪Y轴数据低位
#define	GYRO_ZOUT_H		0x47	//71//陀螺仪Z轴数据高位
#define	GYRO_ZOUT_L		0x48	//72//陀螺仪Z轴数据低位
//////////////////////////////////////

#define	PWR_MGMT_1		0x6B	//107//电源管理，典型值：0x00(正常启用)
#define	WHO_AM_I		0x75	//117//I2C地址寄存器(默认数值0x68，只读)

/**********/
#define GYRO_XOUT		((long) ( (int) I2CRead(0xD0,GYRO_XOUT_H)<<8|(int) I2CRead(0xD0,GYRO_XOUT_L)) )
#define GYRO_YOUT		((long) ( (int) I2CRead(0xD0,GYRO_YOUT_H)<<8|(int) I2CRead(0xD0,GYRO_YOUT_L)) )
#define GYRO_ZOUT		((long) ( (int) I2CRead(0xD0,GYRO_ZOUT_H)<<8|(int) I2CRead(0xD0,GYRO_ZOUT_L)) )
#define ACCEL_XOUT		((long) ( (int) I2CRead(0xD0,ACCEL_XOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_XOUT_L))	)
#define ACCEL_YOUT		((long) ( (int) I2CRead(0xD0,ACCEL_YOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_YOUT_L))	)
#define ACCEL_ZOUT		((long) ( (int) I2CRead(0xD0,ACCEL_ZOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_ZOUT_L))	)
#define	TEMP_OUT		((long) ( (int) I2CRead(0xD0,TEMP_OUT_H)<<8|(int) I2CRead(0xD0,TEMP_OUT_L))	)




#endif