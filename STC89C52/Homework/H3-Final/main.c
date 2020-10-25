//#include <STC89C5XRC.H>
#include <STC12C5A60S2.H>

#include <intrins.h>
#include <math.h>
//#include "MenYuhan_Drivers_STC89.h"

typedef unsigned int uint;
typedef unsigned char uchar;

#define BIT0 1<<0
#define BIT1 1<<1
#define BIT2 1<<2
#define BIT3 1<<3

#define BIT4 1<<4
#define BIT5 1<<5
#define BIT6 1<<6
#define BIT7 1<<7

#define BIT8_ALL 0xff

/*************************************ע��******************************************/
//data��C51�ؼ���
//ASCII�У�0---48;  A--65;  a--97  
/***********************************Ԥװ����****************************************/
/************************************�����*********************/
uint Digital_Tube_Char_Num = 41;
/************************************LCD1602*******************/
const uchar LCD1602_Str0[] = "Men Yuhan";
const uchar LCD1602_Str1[] = "18050100196";
const uint LCD1602_Num0 = 713;
/************************************����**********************/
char UART1_Char = 48;
/***********************************Ԥ�����****************************************/
uint uart_flag = 0;

//f=11.0592MHz
/******************************************������ʱ***********************************/
void Delay_ms(uint time_ms)
{
	uint i, j;
	for (i = 0; i < time_ms; i++)
		for (j = 0; j < 113; j++);
}
/******************************************��Ϊ��׼��ʱ********************************/
/***********************************************ms*****************/
void Delay_ms_1()
{
	unsigned char i, j;
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_ms_2()
{
	unsigned char i, j;
	_nop_();
	i = 4;
	j = 146;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_ms_5()
{
	unsigned char i, j;
	i = 9;
	j = 244;
	do
	{
		while (--j);
	} while (--i);
}
/***********************************************s******************/
void Delay_s_0_5()
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay_s_1()
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

/***************************************Ԥ����*****************************************/
/***************************************LED**********************/
/**************************************IOԤ����*/
sbit LED0 = P1 ^ 0;
sbit LED1 = P1 ^ 1;
sbit LED2 = P1 ^ 2;
sbit LED3 = P1 ^ 3;
sbit LED4 = P1 ^ 4;
sbit LED5 = P1 ^ 5;
sbit LED6 = P1 ^ 6;
sbit LED7 = P1 ^ 7;
/**************************************����Ԥ����*/
/*����*/
#define LED0_On LED0=0
#define LED1_On LED1=0
#define LED2_On LED2=0
#define LED3_On LED3=0
#define LED4_On LED4=0
#define LED5_On LED5=0
#define LED6_On LED6=0
#define LED7_On LED7=0
#define LED_ALL_On P1=0x00
/*�ص�*/
#define LED0_Off LED0=1
#define LED1_Off LED1=1
#define LED2_Off LED2=1
#define LED3_Off LED3=1
#define LED4_Off LED4=1
#define LED5_Off LED5=1
#define LED6_Off LED6=1
#define LED7_Off LED7=1
#define LED_ALL_Off P1=0xff
/*��ת*/
#define LED0_Toggle P1^=BIT0
#define LED1_Toggle P1^=BIT1
#define LED2_Toggle P1^=BIT2
#define LED3_Toggle P1^=BIT3
#define LED4_Toggle P1^=BIT4
#define LED5_Toggle P1^=BIT5
#define LED6_Toggle P1^=BIT6
#define LED7_Toggle P1^=BIT7
#define LED_ALL_Toggle P1^=BIT8_ALL

/***************************************Beep*****************/
/**************************************IOԤ����*/
sbit Beep = P2 ^ 3;
/**************************************����Ԥ����*/
#define Beep_On Beep=0
#define Beep_Off Beep=1
#define Beep_Toggle P2^=BIT3
/***************************************�����*****************/
sbit wx = P2 ^ 7;
sbit dx = P2 ^ 6;
/***************************************��������****************/
sbit Key_i0 = P3 ^ 4;
sbit Key_i1 = P3 ^ 5;
sbit Key_i2 = P3 ^ 6;
sbit Key_i3 = P3 ^ 7;
/***************************************����****************************************/
void STC89_TX_1C_Board_IO_Base_Init()
{
	dx = 0;	//dx
	wx = 0;	//wx

	EA = 1;
}

/************************************��ʼ��*****************************************/
//f=11.0592 MHz
//BR=9600 bps
//Timer=T1
//Timer Mode=2
//��ʱ��ʱ��:12T
void UART1_Init()
{
	PCON &= 0x7F;	//�����ʲ�����
	SCON = 0x50;	//8λ����,�ɱ䲨����
	AUXR &= 0xBF;	//��ʱ��1ʱ��ΪFosc/12,��12T
	AUXR &= 0xFE;	//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;	//�����ʱ��1ģʽλ
	TMOD |= 0x20;	//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xfd;		//�趨��ʱ��ֵ
	TH1 = 0xfd;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
//	ES = 1;			//���������ж�
	ES = 0;			//�رմ����ж�
}
/************************************�ж�*****************************************/
/**********************************�жϹ���********************/
void UART1_INT_Func()
{

}
/**********************************�����ж�********************/
void UART1_INT() interrupt 4
{
	UART1_INT_Func();
}

/********************************************��������*********************************************/
/********************************************��ѡ************************/
uchar code duanxuan[] =
{
	0x3f,		//0
	0x06,		//1
	0x5b,		//2
	0x4f,		//3
	0x66,		//4
	0x6d,		//5
	0x7d,		//6
	0x07,		//7
	0x7f,		//8
	0x6f,		//9

	0x77,		//A--10
	0x7c,		//b--11
	0x39,		//C--12
	0x5e,		//d--13
	0x79,		//E--14
	0x71,		//F--15
	0x3d,		//G--16
	0x76,		//H--17
	0x11,		//i--18
	0x0e,		//J--19
	0x7a,		//k--20
	0x38,		//L--21
	0x55,		//M--22
	0x54,		//n--23
	0X3f,		//O--24
	0x73,		//P--25
	0x67,		//q--26
	0x50,		//r--27
	0x6d,		//S--28
	0x78,		//t--29
	0x3e,		//U--30
	0x3e,		//V--31
	0x6a,		//W--32
	0x76,		//X--33
	0x6e,		//y--34
	0x5b,		//Z--35

	0x7b,		//e--36
	0x74,		//h--37
	0x5c,		//o--38
	0x1c,		//u--39
	0x62,		//v--40

	0x00		//0x00Ϊȫ����--41
};
/********************************************λѡ************************/
uchar code weixuan[] =			//��ߵ�һλΪbit0
{
	0xfe,		//0
	0xfd,		//1
	0xfb,		//2
	0xf7,		//3
	0xef,		//4
	0xdf,		//5
	0xc0		//ALL--6
};
/*******************************************ȫ�ֱ���**********************************************/
/********************************************IO����************************/
//sbit wx = P2 ^ 7;
//sbit dx = P2 ^ 6;
/***********************************************����**********************************************/
/*******************************************�������ʾ1bit******************/
void DigitalTube_Display_1bit(uchar wei, uchar duan)     //λ���ݣ�������
{
	dx = 1;
	P0 = duanxuan[duan];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[wei];
	wx = 0;
	Delay_ms_1();
}
/*******************************************�������ʾ3bit����******************/
void DigitalTube_Display_num_3bit(uchar shu)
{
	uchar bai, shi, ge;
	bai = shu / 100;
	shi = shu / 10 % 10;
	ge = shu % 10;

	DigitalTube_Display_1bit(0, bai);
	DigitalTube_Display_1bit(1, shi);
	DigitalTube_Display_1bit(2, ge);
}
/*******************************************�������ʾ6bit******************/
void DigitalTube_Display_6bit(uchar zero, uchar one, uchar two, uchar three, uchar four, uchar five)
{
	DigitalTube_Display_1bit(0, zero);
	DigitalTube_Display_1bit(1, one);
	DigitalTube_Display_1bit(2, two);
	DigitalTube_Display_1bit(3, three);
	DigitalTube_Display_1bit(4, four);
	DigitalTube_Display_1bit(5, five);
}

//����4*4������̣��ӿ�ΪP3
/***************************************�������ܶ���************************************/
void Key0_Func()
{
	Digital_Tube_Char_Num = 0;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key1_Func()
{
	Digital_Tube_Char_Num = 1;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key2_Func()
{
	Digital_Tube_Char_Num = 2;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key3_Func()
{
	Digital_Tube_Char_Num = 3;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key4_Func()
{
	Digital_Tube_Char_Num = 4;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key5_Func()
{
	Digital_Tube_Char_Num = 5;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key6_Func()
{
	Digital_Tube_Char_Num = 6;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key7_Func()
{
	Digital_Tube_Char_Num = 7;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key8_Func()
{
	Digital_Tube_Char_Num = 8;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key9_Func()
{
	Digital_Tube_Char_Num = 9;
	UART1_Char += Digital_Tube_Char_Num;
}

void Key10_Func()
{
	Digital_Tube_Char_Num = 10;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}

void Key11_Func()
{
	Digital_Tube_Char_Num = 11;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}

void Key12_Func()
{
	Digital_Tube_Char_Num = 12;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}

void Key13_Func()
{
	Digital_Tube_Char_Num = 13;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}

void Key14_Func()
{
	Digital_Tube_Char_Num = 14;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}

void Key15_Func()
{
	Digital_Tube_Char_Num = 15;
	UART1_Char += Digital_Tube_Char_Num;
	UART1_Char += 7;
}
/******************************************����****************************************/
void Keyboard_4x4()
{
	uint temp = 0;

	P3 = 0xfe;                      //���P30��һ�еİ���
	temp = P3;						//��ȡP3��ֵ
	temp = temp & 0xf0;
	if (temp != 0xf0)			//�а��µ�����
	{
		Delay_ms_5();				//��һ��
		temp = P3;					//�ٴζ�ȡP3��ֵ
		temp = temp & 0xf0;
		if (temp != 0xf0)		//ȷʵ������
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xee:Key0_Func();
				break;
			case 0xde:Key1_Func();
				break;
			case 0xbe:Key2_Func();
				break;
			case 0x7e:Key3_Func();
				break;
			}
			/********�������º�Ĳ���********/

			/********���̧��********/
			while (temp != 0xf0)      //��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			uart_flag = 1;
		}
	}

	P3 = 0xfd;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xed:Key4_Func();
				break;
			case 0xdd:Key5_Func();
				break;
			case 0xbd:Key6_Func();
				break;
			case 0x7d:Key7_Func();
				break;
			}
			/*****�������º�Ĳ���*****/

			/********���̧��********/
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			uart_flag = 1;
		}
	}

	P3 = 0xfb;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xeb:Key8_Func();
				break;
			case 0xdb:Key9_Func();
				break;
			case 0xbb:Key10_Func();
				break;
			case 0x7b:Key11_Func();
				break;
			}

			/********�������º�Ĳ���********/

			/********���̧��********/

			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			uart_flag = 1;
		}
	}

	P3 = 0xf7;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xe7:Key12_Func();
				break;
			case 0xd7:Key13_Func();
				break;
			case 0xb7:Key14_Func();
				break;
			case 0x77:Key15_Func();
				break;
			}
			/********�������º�Ĳ���********/

			/********���̧��********/
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			uart_flag = 1;
		}
	}
}



void main()
{
	STC89_TX_1C_Board_IO_Base_Init();

	UART1_Init();

	while (1)
	{
		Keyboard_4x4();
		DigitalTube_Display_1bit(5, Digital_Tube_Char_Num);
		P3 = 0xff;
		if (uart_flag == 1)
		{
			uart_flag = 0;
			SBUF = UART1_Char;
			while (!TI);
			TI = 0;
			UART1_Char = 48;
		}
		
	}
}

