/**************************************IO����******************************/
//sbit Key_i0 = P3 ^ 4;
//sbit Key_i1 = P3 ^ 5;
//sbit Key_i2 = P3 ^ 6;
//sbit Key_i3 = P3 ^ 7;
/**************************************���ܶ���******************************/
void Key_i0_Func()
{

}

void Key_i1_Func()
{

}

void Key_i2_Func()
{

}

void Key_i3_Func()
{

}
/**************************************����*********************************/
void Keyboard_Independent()
{
	if (Key_i0 == 0)			//�а��µ�����
	{
		Delay_ms_5();
		if (Key_i0 == 0)		//ȷʵ����ȥ��
		{
			Key_i0_Func();
		}
		while (Key_i0 != 1);	 //��̧�������
		Delay_ms_5();
		while (Key_i0 != 1);	 //ȷʵ̧����
	}

	if (Key_i1 == 0)			//�а��µ�����
	{
		Delay_ms_5();
		if (Key_i1 == 0)		//ȷʵ����ȥ��
		{
			Key_i1_Func();
		}
		while (Key_i1 != 1);	 //��̧�������
		Delay_ms_5();
		while (Key_i1 != 1);	 //ȷʵ̧����
	}

	if (Key_i2 == 0)			//�а��µ�����
	{
		Delay_ms_5();
		if (Key_i2 == 0)		//ȷʵ����ȥ��
		{
			Key_i2_Func();
		}
		while (Key_i2 != 1);	 //��̧�������
		Delay_ms_5();
		while (Key_i2 != 1);	 //ȷʵ̧����
	}

	if (Key_i3 == 0)			//�а��µ�����
	{
		Delay_ms_5();
		if (Key_i3 == 0)		//ȷʵ����ȥ��
		{
			Key_i3_Func();
		}
		while (Key_i3 != 1);	 //��̧�������
		Delay_ms_5();
		while (Key_i3 != 1);	 //ȷʵ̧����
	}

}