#ifndef		_2000_2g

#define 	ACCEL_SENS	1.6384
#define 	GYRO_SENS	1.64

void MPUinit()            
{
	I2CWrite(0xD0,PWR_MGMT_1,0x00);     //解除休眠状态
    I2CWrite(0xD0,SMPLRT_DIV,0x07);     //陀螺仪采样率1kHz
    I2CWrite(0xD0,CONFIG,0x02);         //设置低通滤波器
    I2CWrite(0xD0,GYRO_CONFIG,0x18);    //陀螺仪量程2000deg/s
    I2CWrite(0xD0,ACCEL_CONFIG,0x00);   //0x00:2g  0x08:4g  0x10:8g  0x18:16g			

}

#endif


/* ACCEL_SENS
0  ±2g  16384 LSB/g
1  ±4g  8192 LSB/g
2  ±8g  4096 LSB/g
3  ±16g  2048 LSB/g 
/* GYRO_SENS
0  ± 250 °/s  131 LSB/°/s
1  ± 500 °/s  65.5 LSB/°/s
2  ± 1000 °/s  32.8 LSB/°/s
3  ± 2000 °/s  16.4 LSB/°/s
*/