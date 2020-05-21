sbit Key1_P = P3 ^ 2;		// ����ʱ�䰴��
sbit Key2_P = P3 ^ 3;			// �������Ӱ���
sbit Key3_P = P3 ^ 4;		// ����ܰ���
sbit Key4_P = P3 ^ 5;			// �ӹ��ܰ���-
sbit Key5_P = P3 ^ 6;		// �ӹ��ܰ���+

/*********************************************************/
// ����ɨ��(����ʱ��)
/*********************************************************/
void KeyScanf1()
{
	if (Key1_P == 0)
	{
		LcdWriteCmd(0x0f);			// ���������˸
		LcdGotoXY(0, 3);					// ��λ��굽�����˸
		DelayMs(10);				// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);				// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)							//�������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[0] > 0)					// �ж�����Ƿ����0		
					TimeBuff[0]--;				// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(0, 2);						// ��궨λ����ݵ�λ��
				LcdPrintNum(TimeBuff[0]);		// ˢ����ʾ�ı������
				LcdGotoXY(0, 3);						// ��λ��굽�����˸
				DelayMs(300);					// ��ʱ0.3������
			}
			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[0] < 99)				// �ж�����Ƿ�С��99
					TimeBuff[0]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(0, 2);					// ��궨λ����ݵ�λ��
				LcdPrintNum(TimeBuff[0]);			// ˢ����ʾ�ı������
				LcdGotoXY(0, 3);					// ��λ��굽�����˸
				DelayMs(300);						// ��ʱ0.3������
			}
			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(0, 6);					// ��λ��굽�·���˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)						//�����·�
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[1] > 1)				// �ж��·��Ƿ����1		
					TimeBuff[1]--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(0, 5);					// ��궨λ���·ݵ�λ��
				LcdPrintNum(TimeBuff[1]);			// ˢ����ʾ�ı����·�
				LcdGotoXY(0, 6);					// ��λ��굽�·���˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[1] < 12)				// �ж��·��Ƿ�С��12
					TimeBuff[1]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(0, 5);					// ��궨λ���·ݵ�λ��
				LcdPrintNum(TimeBuff[1]);			// ˢ����ʾ�ı����·�
				LcdGotoXY(0, 6);					// ��λ��굽�·���˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(0, 9);					// ��λ��굽������˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)								//��������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[2] > 1)				// �ж������Ƿ����1		
					TimeBuff[2]--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(0, 8);					// ��궨λ�����ڵ�λ��
				LcdPrintNum(TimeBuff[2]);			// ˢ����ʾ�ı�������
				LcdGotoXY(0, 9);					// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[2] < 31)				// �ж������Ƿ�С��31
					TimeBuff[2]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(0, 8);					// ��궨λ�����ڵ�λ��
				LcdPrintNum(TimeBuff[2]);			// ˢ����ʾ�ı�������
				LcdGotoXY(0, 9);					// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(0, 15);				// ��λ��굽������˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)							//��������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[3] > 1)				// �ж������Ƿ����1		
					TimeBuff[3]--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(0, 12);				// ��궨λ�����ڵ�λ��
				LcdPrintWeek(TimeBuff[3]);			// ˢ����ʾ�ı�������
				LcdGotoXY(0, 15);				// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[3] < 7)				// �ж������Ƿ�С��7
					TimeBuff[3]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(0, 12);				// ��궨λ�����ڵ�λ��
				LcdPrintWeek(TimeBuff[3]);			// ˢ����ʾ�ı�������
				LcdGotoXY(0, 15);				// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(1, 5);					// ��λ��굽Сʱ��˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)								//����Сʱ
		{
			if (Key4_P == 0)							// �������������ȥ
			{
				if (TimeBuff[4] > 0)					// �ж�Сʱ�Ƿ����0
					TimeBuff[4]--;						// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(1, 4);						// ��궨λ��Сʱ��λ��
				LcdPrintNum(TimeBuff[4]);				// ˢ����ʾ�ı���Сʱ
				LcdGotoXY(1, 5);						// ��λ��굽Сʱ��˸
				DelayMs(300);							// ��ʱ0.3������
			}

			if (Key5_P == 0)							// ����Ӱ�������ȥ
			{
				if (TimeBuff[4] < 23)					// �ж�Сʱ�Ƿ�С��23
					TimeBuff[4]++;						// �ǵĻ��ͼ���1
				LcdGotoXY(1, 4);						// ��궨λ��Сʱ��λ��
				LcdPrintNum(TimeBuff[4]);				// ˢ����ʾ�ı���Сʱ
				LcdGotoXY(1, 5);						// ��λ��굽Сʱ��˸
				DelayMs(300);							// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(1, 8);					// ��λ��굽������˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)							//��������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[5] > 0)				// �жϷ����Ƿ����0
					TimeBuff[5]--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(1, 7);					// ��궨λ�����ӵ�λ��
				LcdPrintNum(TimeBuff[5]);			// ˢ����ʾ�ı��ķ���
				LcdGotoXY(1, 8);					// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[5] < 59)				// �жϷ����Ƿ�С��59
					TimeBuff[5]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(1, 7);					// ��궨λ�����ӵ�λ��
				LcdPrintNum(TimeBuff[5]);			// ˢ����ʾ�ı��ķ���
				LcdGotoXY(1, 8);					// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(1, 11);				// ��λ��굽������˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)							//��������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (TimeBuff[6] > 0)					// �ж������Ƿ����0
					TimeBuff[6]--;				// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(1, 10);					// ��궨λ�����ӵ�λ��
				LcdPrintNum(TimeBuff[6]);		// ˢ����ʾ�ı�������
				LcdGotoXY(1, 11);					// ��λ��굽������˸
				DelayMs(300);					// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (TimeBuff[6] < 59)				// �ж������Ƿ�С��59
					TimeBuff[6]++;					// �ǵĻ��ͼ���1
				LcdGotoXY(1, 10);				// ��궨λ�����ӵ�λ��
				LcdPrintNum(TimeBuff[6]);			// ˢ����ʾ�ı�������
				LcdGotoXY(1, 11);				// ��λ��굽������˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key1_P == 0)
			{
				break;
			}
		}

		/* �˳�ǰ������ */
		LcdWriteCmd(0x0C);			// �رչ����˸
		DS1302_Write_Time();			// �������õ�ʱ��ֵ����DS1302оƬ
		DelayMs(10);				// ��ʱ�ȴ��������������µĶ���
		while (!Key1_P);					// �ȴ������ͷ�
		DelayMs(10);				// ��ʱ�ȴ������������ɿ��Ķ���
	}
}

/*********************************************************/
// ����ɨ��(��������)
/*********************************************************/
void KeyScanf2()
{
	if (Key2_P == 0)
	{
		LcdGotoXY(0, 0);							// Һ����ʾΪ�������õĽ���
		LcdPrintStr("Alarm Clock Set ");
		LcdGotoXY(1, 0);
		LcdPrintStr("     :          ");
		LcdGotoXY(1, 3);							// ��ʾ���ӵ�Сʱ
		LcdPrintNum(Clock_Hour);
		LcdGotoXY(1, 6);							// ��ʾ���ӵķ���
		LcdPrintNum(Clock_Minute);
		LcdGotoXY(1, 10);						// ��ʾ����״̬
		if (Clock_Swt == 0)
		{
			LcdPrintStr("OFF");
		}
		else
		{
			LcdPrintStr(" ON");
		}
		LcdGotoXY(1, 4);					// ��궨λ
		LcdWriteCmd(0x0f);					// �����˸
		DelayMs(10);					// ��ʱ�ȴ��������������µĶ���
		while (!Key2_P);						// �ȴ������ͷ�
		DelayMs(10);					// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)						//��������Сʱ
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (Clock_Hour > 0)				// �ж�����Сʱ�Ƿ����0
					Clock_Hour--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(1, 3);					// ��궨λ������Сʱ��λ��
				LcdPrintNum(Clock_Hour);			// ˢ����ʾ�ı�������Сʱ
				LcdGotoXY(1, 4);					// ��λ��굽����Сʱ��˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)						// ����Ӱ�������ȥ
			{
				if (Clock_Hour < 23)				// �ж�����Сʱ�Ƿ�С��23
					Clock_Hour++;					// �ǵĻ��ͼ���1
				LcdGotoXY(1, 3);					// ��궨λ������Сʱ��λ��
				LcdPrintNum(Clock_Hour);			// ˢ����ʾ�ı�������Сʱ
				LcdGotoXY(1, 4);					// ��λ��굽����Сʱ��˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key2_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(1, 7);					// ��λ��굽���ӷ��ӵ���˸
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key2_P);					// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)						//��������
		{
			if (Key4_P == 0)						// �������������ȥ
			{
				if (Clock_Minute > 0)				// �ж����ӷ����Ƿ����0
					Clock_Minute--;					// �ǵĻ��ͼ�ȥ1
				LcdGotoXY(1, 6);					// ��궨λ�����ӷ��ӵ�λ��
				LcdPrintNum(Clock_Minute);			// ˢ����ʾ�ı������ӷ���
				LcdGotoXY(1, 7);					// ��λ��굽���ӷ�����˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key5_P == 0)					// ����Ӱ�������ȥ
			{
				if (Clock_Minute < 59)				// �ж����ӷ����Ƿ�С��59
					Clock_Minute++;					// �ǵĻ��ͼ���1
				LcdGotoXY(1, 6);					// ��궨λ�����ӷ��ӵ�λ��
				LcdPrintNum(Clock_Minute);			// ˢ����ʾ�ı������ӷ���
				LcdGotoXY(1, 7);					// ��λ��굽���ӷ�����˸
				DelayMs(300);						// ��ʱ0.3������
			}

			if (Key2_P == 0)
			{
				break;
			}
		}

		LcdGotoXY(1, 12);			// ��λ��굽���ӿ��ص�λ����˸
		DelayMs(10);					// ��ʱ�ȴ��������������µĶ���
		while (!Key2_P);				// �ȴ������ͷ�
		DelayMs(10);					// ��ʱ�ȴ������������ɿ��Ķ���

		while (1)						//���ӿ���
		{
			if (Key4_P == 0)				// �������������ȥ
			{
				if (Clock_Swt == 1)		// �ж������Ƿ���
					Clock_Swt = 0;			// �ر�����
				LcdGotoXY(1, 10);		// ��궨λ�����ӿ��ص�λ��
				LcdPrintStr("OFF");		// Һ����ʾ��OFF��
				LcdGotoXY(1, 12);		// ��λ��굽���ӿ��ص�λ����˸
				DelayMs(300);				// ��ʱ0.3������
			}

			if (Key5_P == 0)					// ����Ӱ�������ȥ
			{
				if (Clock_Swt == 0)			// �ж������Ƿ�ر�
					Clock_Swt = 1;				// ��������
				LcdGotoXY(1, 10);			// ��궨λ�����ӿ��ص�λ��
				LcdPrintStr(" ON");			// Һ����ʾ�� ON��
				LcdGotoXY(1, 12);			// ��λ��굽���ӿ��ص�λ����˸
				DelayMs(300);					// ��ʱ0.3������
			}

			if (Key2_P == 0)
			{
				break;
			}
		}

		//�˳�ǰ������
		LcdWriteCmd(0x0C);						// �رչ����˸
		LcdShowInit();								// Һ����ʾ���ݻָ�Ϊ�������
		DelayMs(10);							// ��ʱ�ȴ��������������µĶ���
		while (!Key2_P);								// �ȴ������ͷ�
		DelayMs(10);							// ��ʱ�ȴ������������ɿ��Ķ���
		Sector_Erase(0x2000);
		EEPROM_Write(0x2000, Clock_Hour);		// ��0x2000�����ַд�����ӵ�Сʱ 
		EEPROM_Write(0x2001, Clock_Minute);			// ��0x2001�����ַд�����ӵķ���
		EEPROM_Write(0x2002, Clock_Swt);		// ��0x2002�����ַд�����ӵĿ���
	}
}

/*********************************************************/
// ����/�˳� ���
/*********************************************************/
void KeyScanf3()
{
	if (Key3_P == 0)
	{
		LcdGotoXY(0, 0);								// Һ����ʾΪ���Ľ���
		LcdPrintStr("   Stop-Watch   ");
		LcdGotoXY(1, 0);
		LcdPrintStr("  00:00:00 00   ");

		DelayMs(10);								// ��ʱ�ȴ��������������µĶ���
		while (!Key3_P);									// �ȴ������ͷ�
		DelayMs(10);								// ��ʱ�ȴ������������ɿ��Ķ���

		while (Key3_P)						//��������Сʱ
		{
			if (Key4_P == 0)					// ���Ŀ�ʼ����ͣ�л�		
			{
				if (TR1 == 0)					// �ر俪
				{
					TR1 = 1;
				}
				else						// �����
				{
					TR1 = 0;
				}
				DelayMs(10);				// ��ʱ�ȴ��������������µĶ���
				while (!Key4_P);					// �ȴ������ͷ�
				DelayMs(10);				// ��ʱ�ȴ������������ɿ��Ķ���
			}

			if (Key5_P == 0)								// �������
			{
				Stop_Watch_Count = 0;						// ��������1����
				Stop_Watch_Second = 0;						// ��������2����
				LcdGotoXY(1, 0);							// ��ʾ����
				LcdPrintStr("  00:00:00 00   ");
				DelayMs(10);							// ��ʱ�ȴ��������������µĶ���
				while (!Key5_P);								// �ȴ������ͷ�
				DelayMs(10);							// ��ʱ�ȴ������������ɿ��Ķ���
			}


			if (TR1 == 1)									//����ʱ����ʾ
			{
				LcdGotoXY(1, 2);
				LcdPrintNum(Stop_Watch_Second / 3600);		// Сʱ
				LcdGotoXY(1, 5);
				LcdPrintNum(Stop_Watch_Second % 3600 / 60);	// ����
				LcdGotoXY(1, 8);
				LcdPrintNum(Stop_Watch_Second % 60);			// ����
				LcdGotoXY(1, 11);
				LcdPrintNum(Stop_Watch_Count);				// ����
			}

		}
		// �˳�����ص�ʱ��ģʽ
		TR1 = 0;								// ֹͣ��ʱ��		
		Stop_Watch_Count = 0;						// ��������1����
		Stop_Watch_Second = 0;				// ��������2����
		LcdShowInit();							// Һ����ʾʱ�ӽ���
		DelayMs(10);						// ��ʱ�ȴ��������������µĶ���
		while (!Key3_P);							// �ȴ������ͷ�
		DelayMs(10);						// ��ʱ�ȴ������������ɿ��Ķ���
	}
}

/*********************************************************/
// �����ж�
/*********************************************************/
void ClockJudge()
{
	if (Clock_Swt == 1)			// �ж����ӵĿ����Ƿ���
	{
		if ((Clock_Hour == TimeBuff[4]) && (Clock_Minute == TimeBuff[5]))	//��ǰСʱ�ͷ��ӣ������ӵ�Сʱ�ͷ����Ƿ�һ��
		{
			if (TimeBuff[6] == 0)			// �����Ƿ����0
			{
				Buzzer_Flag = 1;			// ����������������־
			}
		}
	}

	if (TimeBuff[6] == 59)					// �����ǰ����Ϊ59��
	{
		Buzzer_Flag = 0;					// �رշ�����������־
	}

	if ((Key4_P == 0) || (Key5_P == 0))		// ����Ӱ����������������
	{
		Buzzer_Flag = 0;					// Ҫ�رշ�����
	}

	if (Buzzer_Flag == 1)				// ���������Ҫ����
	{
		Buzzer_P = 0;					// ����������
		DelayMs(100);					// ��ʱ0.1��
		Buzzer_P = 1;					// �رշ�����
		DelayMs(100);					// ��ʱ0.1��
	}
}
