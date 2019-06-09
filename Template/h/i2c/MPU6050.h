#ifndef __MPU6050_H_
#define __MPU6050_H_

/*�豸��ַ�궨��*/
#define MPU6050 		0xD0	//AD0����Ϊ�ߵ�ƽʱ����Ϊ0xD2

/*MPU6050�Ĵ����궨��*/
#define	SMPLRT_DIV		0x19	//25//����������ʵķ�Ƶ������ֵ0x07(1kHz)
#define	CONFIG			0x1A	//26//��ͨ�˲�Ƶ��,һ��0x01~0x05,��ֵԽ�����ԽС��ʱԽ��
#define	GYRO_CONFIG		0x1B	//27//�������Լ켰���������̷�Χ
#define	ACCEL_CONFIG	0x1C	//28//���ٶ����Լ켰���������̷�Χ

/////ԭʼ���ݼĴ���///////////////////
#define	ACCEL_XOUT_H	0x3B    //59//���ٶȼ�X�����ݸ�λ
#define	ACCEL_XOUT_L	0x3C    //60//���ٶȼ�X�����ݵ�λ
#define	ACCEL_YOUT_H	0x3D    //61//���ٶȼ�Y�����ݸ�λ
#define	ACCEL_YOUT_L	0x3E	//62//���ٶȼ�Y�����ݵ�λ
#define	ACCEL_ZOUT_H	0x3F	//63//���ٶȼ�Z�����ݸ�λ
#define	ACCEL_ZOUT_L	0x40	//64//���ٶȼ�Z�����ݵ�λ

#define	TEMP_OUT_H		0x41    //65//�¶ȴ��������ݸ�λ
#define	TEMP_OUT_L		0x42	//66//�¶ȴ��������ݵ�λ

#define	GYRO_XOUT_H		0x43    //67//������X�����ݸ�λ
#define	GYRO_XOUT_L		0x44	//68//������X�����ݵ�λ
#define	GYRO_YOUT_H		0x45	//69//������Y�����ݸ�λ
#define	GYRO_YOUT_L		0x46	//70//������Y�����ݵ�λ
#define	GYRO_ZOUT_H		0x47	//71//������Z�����ݸ�λ
#define	GYRO_ZOUT_L		0x48	//72//������Z�����ݵ�λ
//////////////////////////////////////

#define	PWR_MGMT_1		0x6B	//107//��Դ��������ֵ��0x00(��������)
#define	WHO_AM_I		0x75	//117//I2C��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)

/**********/
#define GYRO_XOUT		((long) ( (int) I2CRead(0xD0,GYRO_XOUT_H)<<8|(int) I2CRead(0xD0,GYRO_XOUT_L)) )
#define GYRO_YOUT		((long) ( (int) I2CRead(0xD0,GYRO_YOUT_H)<<8|(int) I2CRead(0xD0,GYRO_YOUT_L)) )
#define GYRO_ZOUT		((long) ( (int) I2CRead(0xD0,GYRO_ZOUT_H)<<8|(int) I2CRead(0xD0,GYRO_ZOUT_L)) )
#define ACCEL_XOUT		((long) ( (int) I2CRead(0xD0,ACCEL_XOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_XOUT_L))	)
#define ACCEL_YOUT		((long) ( (int) I2CRead(0xD0,ACCEL_YOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_YOUT_L))	)
#define ACCEL_ZOUT		((long) ( (int) I2CRead(0xD0,ACCEL_ZOUT_H)<<8|(int) I2CRead(0xD0,ACCEL_ZOUT_L))	)
#define	TEMP_OUT		((long) ( (int) I2CRead(0xD0,TEMP_OUT_H)<<8|(int) I2CRead(0xD0,TEMP_OUT_L))	)




#endif