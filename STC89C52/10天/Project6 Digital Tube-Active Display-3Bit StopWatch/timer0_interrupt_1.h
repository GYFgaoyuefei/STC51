void init_timer0(uint timer0_long)
{
	EA = 1;
	ET0 = 1;
	TMOD = 0X01;
	TH0 = (65536 - timer0_long) / 256;
	TL0 = (65536 - timer0_long) % 256;
	TR0 = 1;
}

void timer0() interrupt 1
{
	/*****��ʼ�޸Ķ�ʱ��ʱ��*****/

	uint time_long0;	
	time_long0 = 50000; 

	/*****�����޸Ķ�ʱ��ʱ��*****/

	TH0 = (65536 - time_long0) / 256;
	TL0 = (65536 - time_long0) % 256;

	/*****��ʼ��������*****/

	n++;

	/*****������������*****/
}