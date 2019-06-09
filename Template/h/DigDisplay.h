#ifndef __SHUMAGUAN_H_
#define __SHUMAGUAN_H

/*138译码管输入端口位定义*/
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

/*数码管显示函数调用接口声明*/
void DigDisplay();

#endif