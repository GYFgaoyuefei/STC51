//�����ʵ����Ҫ����TMOD��TR��EA
void init_timer1(uint timer1_long)
{
//	EA = 1;
	ET1 = 1;
//	TMOD = 0X10;
	TH1 = (65536 - timer1_long) / 256;
	TL1 = (65536 - timer1_long) % 256;
//	TR1 = 1;
}

void timer1() interrupt 3
{
	/*****��ʼ�޸Ķ�ʱ��ʱ��*****/

	uint time_long1;
	time_long1 = 50000;

	/*****�����޸Ķ�ʱ��ʱ��*****/

	TH1 = (65536 - time_long1) / 256;
	TL1 = (65536 - time_long1) % 256;

	/*****��ʼ��������*****/

	

	/*****������������*****/
}
