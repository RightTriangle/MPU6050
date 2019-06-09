#include <reg52.h>
#include "mytype.h"
#include "delay.h"
#include "jz.h"

uchar keyValue;
uchar m_stop=1; 

bit keyScan()
 {
      uchar x,y;
	  P1=0xf0;
      if((P1&0xf0)!=0xf0)
       {
         delayms(10);
         if((P1&0xf0)!=0xf0)
          {
		     x=P1&0xf0;
	         P1=0x0f;
			 y=P1&0x0f;
			 keyValue=x|y;
			 while(P1!=0x0f); //当按键未释放时会停在此处，就不会有返回值
			 return 1;        //或许这里应该是P1!=0x0f时循环return 1 ？	  应该不是
		   /*while(P1!=0x0f)
		     	return 1;	    按键按下时循环返回1		  就会马上有输出值 上面的程序会卡在循环处 便一直等待按键释放
			 return 0;			释放按键后马上返回0
			 但等到该函数运行完才会回到之前的函数进行判断 吧？
		     */
		  }
		  else
		  	return 0;	 //此处新加，如果延时去抖发现按键未按下仍为未按下按键
      }
      else
		return 0;  // 此处有问题？
}

uchar keyHandle()
{

      if(keyScan())
	  {
       switch(keyValue)
	     {
	      case 0xee:{return 1  ;break;}  //对应按键S1
		  case 0xde:{return 2  ;break;}  //对应按键S2
		  case 0xbe:{return 3  ;break;}  //对应按键S3
		  case 0x7e:{return 4  ;break;}  //对应按键S4
		  case 0xed:{return 5  ;break;}  //对应按键S5
		  case 0xdd:{return 6  ;break;}  //对应按键S6
		  case 0xbd:{return 7  ;break;}  //对应按键S7
		  case 0x7d:{return 8  ;break;}  //对应按键S8
		  case 0xeb:{return 9  ;break;}  //对应按键S9
		  case 0xdb:{return 10 ;break;} //对应按键S10
		  case 0xbb:{return 11 ;break;} //对应按键S11
		  case 0x7b:{return 12 ;break;} //对应按键S12
		  case 0xe7:{return 13 ;break;} //对应按键S13
		  case 0xd7:{return 14 ;break;} //对应按键S14
		  case 0xb7:{return 15 ;break;} //对应按键S15
		  case 0x77:{return 16 ;break;} //对应按键S16
		  default:{return 0;break;}
	     }
	   }
	  	else	return 0;
}