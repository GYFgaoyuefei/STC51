//�����ʵ����Ҫ����TMOD��TR��EA
void init_timer0(uint timer0_long)
{
//	EA = 1;
	ET0 = 1;
//	TMOD = 0X01;
	TH0 = (65536 - timer0_long) / 256;
	TL0 = (65536 - timer0_long) % 256;
//	TR0 = 1;
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

	t0++;
	if (flag_t0 == 0)
	{
		if (t0 == 10)
		{
			t0 = 0;
			temp = _crol_(temp, 1);
			P1 = temp;
		}
	}
	else
	{
		if (t0 % 4 == 0)
			P1 = ~P1;
		if (t0 == 60)
		{
			TR0 = 0;
			t0 = 0;
			P1 = 0xff;
			flag_t1 = 1;
		}
	}

	/*****������������*****/
}