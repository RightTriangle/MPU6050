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
			 while(P1!=0x0f); //������δ�ͷ�ʱ��ͣ�ڴ˴����Ͳ����з���ֵ
			 return 1;        //��������Ӧ����P1!=0x0fʱѭ��return 1 ��	  Ӧ�ò���
		   /*while(P1!=0x0f)
		     	return 1;	    ��������ʱѭ������1		  �ͻ����������ֵ ����ĳ���Ῠ��ѭ���� ��һֱ�ȴ������ͷ�
			 return 0;			�ͷŰ��������Ϸ���0
			 ���ȵ��ú���������Ż�ص�֮ǰ�ĺ��������ж� �ɣ�
		     */
		  }
		  else
		  	return 0;	 //�˴��¼ӣ������ʱȥ�����ְ���δ������Ϊδ���°���
      }
      else
		return 0;  // �˴������⣿
}

uchar keyHandle()
{

      if(keyScan())
	  {
       switch(keyValue)
	     {
	      case 0xee:{return 1  ;break;}  //��Ӧ����S1
		  case 0xde:{return 2  ;break;}  //��Ӧ����S2
		  case 0xbe:{return 3  ;break;}  //��Ӧ����S3
		  case 0x7e:{return 4  ;break;}  //��Ӧ����S4
		  case 0xed:{return 5  ;break;}  //��Ӧ����S5
		  case 0xdd:{return 6  ;break;}  //��Ӧ����S6
		  case 0xbd:{return 7  ;break;}  //��Ӧ����S7
		  case 0x7d:{return 8  ;break;}  //��Ӧ����S8
		  case 0xeb:{return 9  ;break;}  //��Ӧ����S9
		  case 0xdb:{return 10 ;break;} //��Ӧ����S10
		  case 0xbb:{return 11 ;break;} //��Ӧ����S11
		  case 0x7b:{return 12 ;break;} //��Ӧ����S12
		  case 0xe7:{return 13 ;break;} //��Ӧ����S13
		  case 0xd7:{return 14 ;break;} //��Ӧ����S14
		  case 0xb7:{return 15 ;break;} //��Ӧ����S15
		  case 0x77:{return 16 ;break;} //��Ӧ����S16
		  default:{return 0;break;}
	     }
	   }
	  	else	return 0;
}