sbit LcdRs_P = P2 ^ 7;       // 1602Һ����RS       
sbit LcdRw_P = P2 ^ 6;			// 1602Һ����RW 
sbit LcdEn_P = P2 ^ 5;       // 1602Һ����EN

/*********************************************************/
// 1602Һ��д�������cmd����Ҫд�������
/*********************************************************/
void LcdWriteCmd(uchar cmd)
{
	LcdRs_P = 0;
	LcdRw_P = 0;
	LcdEn_P = 0;
	P0 = cmd;
	DelayMs(2);
	LcdEn_P = 1;
	DelayMs(2);
	LcdEn_P = 0;
}

/*********************************************************/
// 1602Һ��д���ݺ�����dat����Ҫд�������
/*********************************************************/
void LcdWriteData(uchar dat)
{
	LcdRs_P = 1;
	LcdRw_P = 0;
	LcdEn_P = 0;
	P0 = dat;
	DelayMs(2);
	LcdEn_P = 1;
	DelayMs(2);
	LcdEn_P = 0;
}

/*********************************************************/
// 1602Һ����ʼ������
/*********************************************************/
void LcdInit()
{
	LcdWriteCmd(0x38);        // 16*2��ʾ��5*7����8λ���ݿ�
	LcdWriteCmd(0x0C);        // ����ʾ������ʾ���
	LcdWriteCmd(0x06);        // ��ַ��1����д�����ݺ�������
	LcdWriteCmd(0x01);        // ����
}

/*********************************************************/
// Һ������ַ�������
/*********************************************************/
void LcdPrintStr(uchar* str)
{
	while (*str != '\0')
		LcdWriteData(*str++);
}

/*********************************************************/
// Һ����궨λ����
/*********************************************************/
void LcdGotoXY(uchar hang, uchar lie)
{	
	if (hang == 0)							// ��һ��
		LcdWriteCmd(0x80 + lie);	
	if (hang == 1)							// �ڶ���
		LcdWriteCmd(0x80 + 0x40 + lie);
}

/*********************************************************/
// Һ����ʾ���ݵĳ�ʼ��
/*********************************************************/
void LcdShowInit()
{
	LcdGotoXY(0, 0);
	LcdPrintStr("20  -  -        ");
	LcdGotoXY(1, 0);
	LcdPrintStr("      :  :      ");
}

/*********************************************************/
// Һ���������
/*********************************************************/
void LcdPrintNum(uchar num)
{
	LcdWriteData(num / 10 + 48);		// ʮλ
	LcdWriteData(num % 10 + 48); 		// ��λ
}

/*********************************************************/
// Һ����ʾ����
/*********************************************************/
void LcdPrintWeek(uchar week)
{
	switch (week)
	{
	case 1: LcdPrintStr(" Sun");	break;
	case 2: LcdPrintStr(" Mon");	break;
	case 3: LcdPrintStr("Tues");	break;
	case 4: LcdPrintStr(" Wed");	break;
	case 5: LcdPrintStr("Thur");	break;
	case 6: LcdPrintStr(" Fri");	break;
	case 7: LcdPrintStr(" Sat");	break;
	default:break;
	}
}

/*********************************************************/
// ˢ��ʱ����ʾ
/*********************************************************/
void FlashTime()
{
	LcdGotoXY(0, 2);					// ���
	LcdPrintNum(TimeBuff[0]);
	LcdGotoXY(0, 5);					// �·�
	LcdPrintNum(TimeBuff[1]);
	LcdGotoXY(0, 8);					// ����
	LcdPrintNum(TimeBuff[2]);
	LcdGotoXY(1, 4);					// Сʱ
	LcdPrintNum(TimeBuff[4]);
	LcdGotoXY(1, 7);					// ����
	LcdPrintNum(TimeBuff[5]);
	LcdGotoXY(1, 10);					// ����
	LcdPrintNum(TimeBuff[6]);
	LcdGotoXY(0, 12);					// ����	
	LcdPrintWeek(TimeBuff[3]);
}
