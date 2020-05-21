sfr ISP_DATA = 0xe2;		// ���ݼĴ���
sfr ISP_ADDRH = 0xe3;			// ��ַ�Ĵ����߰�λ
sfr ISP_ADDRL = 0xe4;		// ��ַ�Ĵ����Ͱ�λ
sfr ISP_CMD = 0xe5;			// ����Ĵ���
sfr ISP_TRIG = 0xe6;		// ������Ĵ���
sfr ISP_CONTR = 0xe7;			// ����Ĵ���

/*********************************************************/
// ��Ƭ���ڲ�EEPROM��ʹ��
/*********************************************************/
void ISP_Disable()
{
	ISP_CONTR = 0;
	ISP_ADDRH = 0;
	ISP_ADDRL = 0;
}

/*********************************************************/
// �ӵ�Ƭ���ڲ�EEPROM��һ���ֽڣ���0x2000��ַ��ʼ
/*********************************************************/
uchar EEPROM_Read(uint add)
{
	ISP_DATA = 0x00;
	ISP_CONTR = 0x83;
	ISP_CMD = 0x01;
	ISP_ADDRH = (uchar)(add >> 8);
	ISP_ADDRL = (uchar)(add & 0xff);

	ISP_TRIG = 0x46;	// ��STC89C51ϵ����˵��ÿ��Ҫд��0x46����д��0xB9,ISP/IAP�Ż���Ч
	ISP_TRIG = 0xB9;
	_nop_();
	ISP_Disable();
	return (ISP_DATA);
}

/*********************************************************/
// ����Ƭ���ڲ�EEPROMдһ���ֽڣ���0x2000��ַ��ʼ
/*********************************************************/
void EEPROM_Write(uint add, uchar ch)
{
	ISP_CONTR = 0x83;
	ISP_CMD = 0x02;
	ISP_ADDRH = (uchar)(add >> 8);
	ISP_ADDRL = (uchar)(add & 0xff);
	ISP_DATA = ch;
	ISP_TRIG = 0x46;
	ISP_TRIG = 0xB9;
	_nop_();
	ISP_Disable();
}

/*********************************************************/
// ������Ƭ���ڲ�EEPROM��һ������
// д8�����������һ���ĵ�ַ���Ա������������д��ǰҪ�Ȳ���
/*********************************************************/
void Sector_Erase(uint add)
{
	ISP_CONTR = 0x83;
	ISP_CMD = 0x03;
	ISP_ADDRH = (uchar)(add >> 8);
	ISP_ADDRL = (uchar)(add & 0xff);
	ISP_TRIG = 0x46;
	ISP_TRIG = 0xB9;
	_nop_();
	ISP_Disable();
}

