sbit wx = P2 ^ 7;
sbit dx = P2 ^ 6;

uchar code duanxuan[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,
0x77,0x7c,0x39,0x5e,0x79,0x71 };
uchar code weixuan[] = { 0xfe,0xfd,0xfb,0xf7,0xef,0xdf };

void DigitalTube_1bit_Display(uchar duan, uchar wei)     //�����ݣ�λ����
{
	dx = 1;
	P0 = duanxuan[duan];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[wei];
	wx = 0;
	DelayMs(1);
}
