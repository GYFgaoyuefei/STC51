/********************************************************/
//����4*4������̣��ӿ�ΪP3
/********************************************************/
uchar Keyboard_4x4()
{
	P3 = 0xfe;                      //���P30��һ�еİ���
	temp = P3;						//��ȡP3��ֵ
	temp = temp & 0xf0;
	if (temp != 0xf0)			//�а��µ�����
	{
		delay_ms(5);				//��һ��
		temp = P3;					//�ٴζ�ȡP3��ֵ
		temp = temp & 0xf0;
		if (temp != 0xf0)		//ȷʵ������
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xee:num = 0;
				break;
			case 0xde:num = 1;
				break;
			case 0xbe:num = 2;
				break;
			case 0x7e:num = 3;
				break;
			}

			/********�������º�Ĳ���********/

			/********���̧��********/

			while (temp != 0xf0)      //��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
			delay_ms(5);
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
		delay_ms(5);
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xed:num = 4;
				break;
			case 0xdd:num = 5;
				break;
			case 0xbd:num = 6;
				break;
			case 0x7d:num = 7;
				break;
			}

			/*****�������º�Ĳ���*****/

			/********���̧��********/

			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			delay_ms(5);
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
		delay_ms(5);
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xeb:num = 8;
				break;
			case 0xdb:num = 9;
				break;
			case 0xbb:num = 10;
				break;
			case 0x7b:num = 11;
				break;
			}

			/********�������º�Ĳ���********/

			/********���̧��********/

			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			delay_ms(5);
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
		delay_ms(5);
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0)
		{
			/*****��ʼ���º�Ĳ���*****/

			temp = P3;
			switch (temp)
			{
			case 0xe7:num = 12;
				break;
			case 0xd7:num = 13;
				break;
			case 0xb7:num = 14;
				break;
			case 0x77:num = 15;
				break;
			}

			/********�������º�Ĳ���********/

			/********���̧��********/

			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
			delay_ms(5);
			while (temp != 0xf0)      //�ټ��̧�������
			{
				temp = P3;			  //���¶�ȡP3
				temp = temp & 0xf0;
			}
		}
	}
	return num;
}