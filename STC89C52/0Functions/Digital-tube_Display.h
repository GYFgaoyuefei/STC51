void display(uchar one, uchar two, uchar three, uchar four, uchar five, uchar six)
{
	dx = 1;
	P0 = duanxuan[one];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[0];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[two];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[1];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[three];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[2];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[four];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[3];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[five];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[4];
	wx = 0;
	DelayMs(1);

	dx = 1;
	P0 = duanxuan[six];
	dx = 0;
	P0 = 0xff;
	wx = 1;
	P0 = weixuan[5];
	wx = 0;
	DelayMs(1);
}
