sbit wx = P2 ^ 7;
sbit dx = P2 ^ 6;

uchar code duanxuan[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,
0x77,0x7c,0x39,0x5e,0x79,0x71 };
uchar code weixuan[] = { 0xfe,0xfd,0xfb,0xf7,0xef,0xdf };
uchar code HELLO[] = { 0x76,0x79,0x38,0x38,0x3f };

void Display_smg1(uchar shu)
{
	uchar bai, shi, ge;
	bai = shu / 100;
	shi = shu / 10 % 10;
	ge = shu % 10;

	dx = 1;
	P0 = duanxuan[7];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[0];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[6];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[1];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[5];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[2];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[bai];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[3];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[shi];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[4];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[ge];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[5];
	wx = 0;
	DelayMs(1);

}

void Display_smg_hello()
{
	dx = 1;
	P0 = HELLO[0];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[0];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = HELLO[1];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[1];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = HELLO[2];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[2];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = HELLO[3];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[3];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = HELLO[4];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[4];
	wx = 0;
	DelayMs(1);
}