//����4*4������̣��ӿ�ΪP3
/***************************************�������ܶ���************************************/
void Key0_Func()
{

}

void Key1_Func()
{

}

void Key2_Func()
{

}

void Key3_Func()
{

}

void Key4_Func()
{

}

void Key5_Func()
{

}

void Key6_Func()
{

}

void Key7_Func()
{

}

void Key8_Func()
{

}

void Key9_Func()
{

}

void Key10_Func()
{

}

void Key11_Func()
{

}

void Key12_Func()
{

}

void Key13_Func()
{

}

void Key14_Func()
{

}

void Key15_Func()
{

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
