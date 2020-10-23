#include"reg52.h"
#include"intrins.h"

#define uchar unsigned char	
#define uint  unsigned int	

sbit Buzzer_P = P2 ^ 0;			// ������

uchar TimeBuff[7]={19,10,4,6,18,30,40};   //ʱ�����飬Ĭ��2019��10��4�գ������壬18:30:40
// TimeBuff[0] ������ݣ���Χ00-99
// TimeBuff[1] �����·ݣ���Χ1-12
// TimeBuff[2] �������ڣ���Χ1-31
// TimeBuff[3] �������ڣ���Χ1-7��1�������죬2������һ
// TimeBuff[4] ����Сʱ����Χ00-23
// TimeBuff[5] ������ӣ���Χ00-59
// TimeBuff[6] �������ӣ���Χ00-59

uchar Clock_Hour;				// ���ӵ�Сʱ
uchar Clock_Minute;					// ���ӵķ���
uchar Clock_Swt;				// ���ӵĿ���
uchar Buzzer_Flag = 0;				// ������������־

uchar Stop_Watch_Count = 0;		// ������������10�����1
uint  Stop_Watch_Second = 0;			// ������������1���1

#include"DelayMs.h"
#include"EEPROM.h"
#include"LCD1602.h"
#include"DS1302.h"
#include"keyboard4.h"
#include"timer1.h"

void main()
{
	LcdInit();					// ִ��Һ����ʼ��	
	DS1302_Init();					// ʱ��оƬ�ĳ�ʼ��
	LcdShowInit();				// Һ����ʾ���ݵĳ�ʼ��
	TimerInit();					// ��ʱ����ʼ��
	
	if(DS1302_Read_Byte(0x81)>=128)	// �ж�ʱ��оƬ�Ƿ���������
	{
		DS1302_Write_Time();				// ���û�У����ʼ��һ��ʱ��
	}
	
	Clock_Hour = EEPROM_Read(0x2000);		// ��ȡ0x2000�����ַ�����ݣ���ֵ�����ӵ�Сʱ����
	if(Clock_Hour>23)						// �����ȡ��������Сʱ��ֵ�������������¸�ֵ
	{
		Clock_Hour = 12;
	}

	Clock_Minute = EEPROM_Read(0x2001);	// ��ȡ0x2001�����ַ�����ݣ���ֵ�����ӵķ��ӱ���
	if(Clock_Minute>59)						// �����ȡ�������ӷ�����ֵ�������������¸�ֵ
	{
		Clock_Minute = 30;
	}

	Clock_Swt = EEPROM_Read(0x2002);		// ��ȡ0x2002�����ַ�����ݣ���ֵ�����ӵĿ��ر���
	if(Clock_Swt>1)							// �����ȡ�������ӿ�����ֵ�������������¸�ֵ
	{
		Clock_Swt = 0;
	}
	
	while(1)
	{
		DS1302_Read_Time();		// ��ȡ��ǰʱ��оƬ��ʱ�䣬��������time_buf��
		FlashTime();				// ˢ��ʱ����ʾ
		ClockJudge();					// ���ӹ������ж�

		KeyScanf1();				// ����ɨ��(ʱ�������)
		KeyScanf2();					// ����ɨ��(���ӵ�����)
		KeyScanf3();				// ����ɨ��(������˳����)
									
		DelayMs(100);				// ��ʱ0.1s
	}
}
