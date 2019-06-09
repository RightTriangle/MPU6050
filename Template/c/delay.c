#include "delay.h"
#include "intrins.h"

void delayms(unsigned int xms)
{
	unsigned int i,j;
	for(i=xms;i>0;i--)
	  for(j=120;j>0;j--);
}

/***********************************************************************/	
/*	 Delay10us()函数中共用了6个_NOP_()语句，每个语句执行时间为1 μs。   */
/*主函数调用Delay10us()时先执行一个LCALL指令(2μs)，然后执行6个_NOP_()  */
/*语句(6μs)，最后执行了一个RET指令(2 μs)，所以执行该函数时共需要10 μs。*/
/***********************************************************************/
void Delay10us(){_nop_( );_nop_( );_nop_( );_nop_( );_nop_( );_nop_( );}