//����4*4������̣��ӿ�ΪP3
/***************************************�������ܶ���************************************/
void Key0_Func()
{
	num = 0;
}

void Key1_Func()
{
	num = 1;
}

void Key2_Func()
{
	num = 2;
}

void Key3_Func()
{
	num = 3;
}

void Key4_Func()
{
	num = 4;
}

void Key5_Func()
{
	num = 5;
}

void Key6_Func()
{
	num = 6;
}

void Key7_Func()
{
	num = 7;
}

void Key8_Func()
{
	num = 8;
}

void Key9_Func()
{
	num = 9;
}

void Key10_Func()
{
	num = 10;
}

void Key11_Func()
{
	num = 11;
}

void Key12_Func()
{
	num = 12;
}

void Key13_Func()
{
	num = 13;
}

void Key14_Func()
{
	num = 14;
}

void Key15_Func()
{
	num = 15;
}
/******************************************����****************************************/
void Keyboard_4x4()
{
	uint temp=0;

	P3 = 0xfe;                      //���P30��һ�еİ���
	temp = P3;						//��ȡP3��ֵ
	temp = temp & 0xf0;
	if (temp != 0xf0)			//�а��µ�����
	{
		Delay_ms_5();				//��һ��
		temp = P3;					//�ٴζ�ȡP3��ֵ
		temp = temp & 0xf0;
		if (temp != 0xf0)		//ȷʵ������
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xee:Key0_Func();
				break;
			case 0xde:Key1_Func();
				break;
			case 0xbe:Key2_Func();
				break;
			case 0x7e:Key3_Func();
				break;
			}
			/********�������º�Ĳ���********/

			/********���̧��********/
			while (temp != 0xf0)      //��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
		}
	}

	P3 = 0xfd;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xed:Key4_Func();
				break;
			case 0xdd:Key5_Func();
				break;
			case 0xbd:Key6_Func();
				break;
			case 0x7d:Key7_Func();
				break;
			}
			/*****�������º�Ĳ���*****/

			/********���̧��********/
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
		}
	}

	P3 = 0xfb;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xeb:Key8_Func();
				break;
			case 0xdb:Key9_Func();
				break;
			case 0xbb:Key10_Func();
				break;
			case 0x7b:Key11_Func();
				break;
			}

			/********�������º�Ĳ���********/

			/********���̧��********/

			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
		}
	}

	P3 = 0xf7;
	temp = P3;
	temp = temp & 0xf0;
	if (temp != 0xf0)
	{
		Delay_ms_5();
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/
			temp = P3;
			switch (temp)
			{
			case 0xe7:Key12_Func();
				break;
			case 0xd7:Key13_Func();
				break;
			case 0xb7:Key14_Func();
				break;
			case 0x77:Key15_Func();
				break;
			}
			/********�������º�Ĳ���********/

			/********���̧��********/
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			Delay_ms_5();
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
		}
	}
}
