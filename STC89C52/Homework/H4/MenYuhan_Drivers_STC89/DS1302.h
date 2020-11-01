/************************************ע��*****************************************/
//dataΪC51�ؼ���
/***********************************Ԥ����****************************************/
uchar TimeBuff[7] = { 20,10,31,7,11,25,20 };   //ʱ�����飬Ĭ��2020��10��31�գ������壬18:30:40
// TimeBuff[0] ������ݣ���Χ00-99
// TimeBuff[1] �����·ݣ���Χ1-12
// TimeBuff[2] �������ڣ���Χ1-31
// TimeBuff[3] �������ڣ���Χ1-7��1�������죬2������һ
// TimeBuff[4] ����Сʱ����Χ00-23
// TimeBuff[5] ������ӣ���Χ00-59
// TimeBuff[6] �������ӣ���Χ00-59

/**********************************IO����*****************************************/
sbit DS1302_CLK = P2 ^ 1;
sbit DS1302_IO = P2 ^ 0;
sbit DS1302_RST = P2 ^ 4;
/***********************************����******************************************/
/***********************************ͨ��********************/
/*********************************��1�ֽ�*/
uchar DS1302_R_Byte(uchar addr)
{
	uchar i;
	uchar temp;

	DS1302_RST = 1;
	for (i = 0; i < 8; i++)			//д��Ŀ���ַ��addr
	{
		if (addr & 0x01)
			DS1302_IO = 1;
		else
			DS1302_IO = 0;

		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();

		addr = addr >> 1;
	}

	for (i = 0; i < 8; i++)			//�����õ�ַ������
	{
		temp = temp >> 1;

		if (DS1302_IO)
			temp |= 0x80;
		else
			temp &= 0x7F;

		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();
	}
	DS1302_RST = 0;
	return temp;
}

/*********************************д1�ֽ�*/
void DS1302_W_Byte(uchar addr, uchar dat)
{
	uchar i;

	DS1302_RST = 1;
	for (i = 0; i < 8; i++)			//д��Ŀ���ַ��addr
	{
		if (addr & 0x01)
			DS1302_IO = 1;
		else
			DS1302_IO = 0;

		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();

		addr = addr >> 1;
	}

	for (i = 0; i < 8; i++)			//д�����ݣ�dat
	{
		if (dat & 0x01)
			DS1302_IO = 1;
		else
			DS1302_IO = 0;

		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();

		dat = dat >> 1;
	}
	DS1302_RST = 0;
}

/***********************************�ж�********************/
/*******************************д��ʱ������*/
void DS1302_W_Time()
{
	uchar i;
	uchar temp1;
	uchar temp2;

	for (i = 0; i < 7; i++)			// ʮ����תBCD��
	{
		temp1 = (TimeBuff[i] / 10) << 4;
		temp2 = TimeBuff[i] % 10;
		TimeBuff[i] = temp1 + temp2;
	}
	DS1302_W_Byte(0x8E, 0x00);						// �ر�д���� 
	DS1302_W_Byte(0x80, 0x80);						// ��ͣʱ�� 
	DS1302_W_Byte(0x8C, TimeBuff[0]);				// �� 
	DS1302_W_Byte(0x88, TimeBuff[1]);				// �� 
	DS1302_W_Byte(0x86, TimeBuff[2]);				// �� 
	DS1302_W_Byte(0x8A, TimeBuff[3]);				// ����
	DS1302_W_Byte(0x84, TimeBuff[4]);				// ʱ 
	DS1302_W_Byte(0x82, TimeBuff[5]);				// ��
	DS1302_W_Byte(0x80, TimeBuff[6]);				// ��
	DS1302_W_Byte(0x80, TimeBuff[6] & 0x7F);		// ����ʱ��
	DS1302_W_Byte(0x8E, 0x80);						// ��д����  
}

/*******************************����ʱ������*/
void DS1302_R_Time()
{
	uchar i;
	TimeBuff[0] = DS1302_R_Byte(0x8D);				// �� 
	TimeBuff[1] = DS1302_R_Byte(0x89);				// �� 
	TimeBuff[2] = DS1302_R_Byte(0x87);				// �� 
	TimeBuff[3] = DS1302_R_Byte(0x8B);				// ����
	TimeBuff[4] = DS1302_R_Byte(0x85);				// ʱ 
	TimeBuff[5] = DS1302_R_Byte(0x83);				// �� 
	TimeBuff[6] = (DS1302_R_Byte(0x81)) & 0x7F;		// �� 

	for (i = 0; i < 7; i++)		// BCDתʮ����
	{
		TimeBuff[i] = (TimeBuff[i] / 16) * 10 + TimeBuff[i] % 16;
	}
}

/*******************�ж�ʱ��оƬ�Ƿ���������*/
void DS1302_Check()
{
	if (DS1302_R_Byte(0x81) >= 128)	// �ж�ʱ��оƬ�Ƿ���������
		DS1302_W_Time();				// ���û�У����ʼ��һ��ʱ��
}
/***********************************��ʼ��*/
void DS1302_Init()
{
	DS1302_RST = 0;
	DS1302_CLK = 0;
	DS1302_IO = 0;
}
