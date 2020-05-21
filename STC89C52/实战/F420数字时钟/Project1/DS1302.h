sbit RST_P = P1 ^ 3;			// ʱ��оƬDS1302��RST
sbit SDA_P = P1 ^ 2;		// ʱ��оƬDS1302��SDA
sbit SCK_P = P1 ^ 1;			// ʱ��оƬDS1302��SCK

/*********************************************************/
// ��ʼ��DS1302
/*********************************************************/
void DS1302_Init(void)
{
	RST_P = 0;			// RST���õ�
	SCK_P = 0;			// SCK���õ�
	SDA_P = 0;			// SDA���õ�				
}

/*********************************************************/
// ��DS1302����һ�ֽ�����
/*********************************************************/
uchar DS1302_Read_Byte(uchar addr)
{
	uchar i;
	uchar temp;
	RST_P = 1;
	for (i = 0; i < 8; i++)			//д��Ŀ���ַ��addr
	{
		if (addr & 0x01)
			SDA_P = 1;
		else
			SDA_P = 0;

		SCK_P = 1;
		_nop_();
		SCK_P = 0;
		_nop_();

		addr = addr >> 1;
	}

	for (i = 0; i < 8; i++)			//�����õ�ַ������
	{
		temp = temp >> 1;

		if (SDA_P)
			temp |= 0x80;
		else
			temp &= 0x7F;

		SCK_P = 1;
		_nop_();
		SCK_P = 0;
		_nop_();
	}
	RST_P = 0;
	return temp;
}

/*********************************************************/
// ��DS1302д��һ�ֽ�����
/*********************************************************/
void DS1302_Write_Byte(uchar addr, uchar dat)
{
	uchar i;
	RST_P = 1;
	for (i = 0; i < 8; i++)				//д��Ŀ���ַ��addr
	{
		if (addr & 0x01)
			SDA_P = 1;
		else
			SDA_P = 0;

		SCK_P = 1;
		_nop_();
		SCK_P = 0;
		_nop_();

		addr = addr >> 1;
	}

	for (i = 0; i < 8; i++)			//д�����ݣ�dat
	{
		if (dat & 0x01)
			SDA_P = 1;
		else
			SDA_P = 0;

		SCK_P = 1;
		_nop_();
		SCK_P = 0;
		_nop_();

		dat = dat >> 1;
	}
	RST_P = 0;
}

/*********************************************************/
// ��DS1302д��ʱ������
/*********************************************************/
void DS1302_Write_Time()
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
	DS1302_Write_Byte(0x8E, 0x00);						// �ر�д���� 
	DS1302_Write_Byte(0x80, 0x80);						// ��ͣʱ�� 
	DS1302_Write_Byte(0x8C, TimeBuff[0]);				// �� 
	DS1302_Write_Byte(0x88, TimeBuff[1]);				// �� 
	DS1302_Write_Byte(0x86, TimeBuff[2]);				// �� 
	DS1302_Write_Byte(0x8A, TimeBuff[3]);				// ����
	DS1302_Write_Byte(0x84, TimeBuff[4]);				// ʱ 
	DS1302_Write_Byte(0x82, TimeBuff[5]);				// ��
	DS1302_Write_Byte(0x80, TimeBuff[6]);				// ��
	DS1302_Write_Byte(0x80, TimeBuff[6] & 0x7F);		// ����ʱ��
	DS1302_Write_Byte(0x8E, 0x80);						// ��д����  
}

/*********************************************************/
// ��DS1302����ʱ������
/*********************************************************/
void DS1302_Read_Time()
{
	uchar i;
	TimeBuff[0] = DS1302_Read_Byte(0x8D);						// �� 
	TimeBuff[1] = DS1302_Read_Byte(0x89);						// �� 
	TimeBuff[2] = DS1302_Read_Byte(0x87);						// �� 
	TimeBuff[3] = DS1302_Read_Byte(0x8B);						// ����
	TimeBuff[4] = DS1302_Read_Byte(0x85);						// ʱ 
	TimeBuff[5] = DS1302_Read_Byte(0x83);						// �� 
	TimeBuff[6] = (DS1302_Read_Byte(0x81)) & 0x7F;		// �� 

	for (i = 0; i < 7; i++)		// BCDתʮ����
	{
		TimeBuff[i] = (TimeBuff[i] / 16) * 10 + TimeBuff[i] % 16;
	}
}

