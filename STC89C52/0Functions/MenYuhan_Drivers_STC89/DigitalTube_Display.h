/********************************************��������*********************************************/
/********************************************��ѡ************************/
uchar code duanxuan[] = 
{ 
	0x3f,		//0
	0x06,		//1
	0x5b,		//2
	0x4f,		//3
	0x66,		//4
	0x6d,		//5
	0x7d,		//6
	0x07,		//7
	0x7f,		//8
	0x6f,		//9
	0x77,		//A
	0x7c,		//B
	0x39,		//C
	0x5e,		//d
	0x79,		//E
	0x71,		//F
	0x00		//0x00Ϊȫ����
};             
/********************************************λѡ************************/
uchar code weixuan[] =			//��ߵ�һλΪbit0
{ 
	0xfe,		//0
	0xfd,		//1
	0xfb,		//2
	0xf7,		//3
	0xef,		//4
	0xdf,		//5
	0xc0		//ALL--6
};
/********************************************�����ֶ�************************/
uchar code HELLO[] = { 0x76,0x79,0x38,0x38,0x3f };
/*******************************************ȫ�ֱ���**********************************************/
/********************************************IO����************************/
//sbit wx = P2 ^ 7;
//sbit dx = P2 ^ 6;
/***********************************************����**********************************************/
/*******************************************�������ʾ1bit******************/
void DigitalTube_Display_1bit(uchar wei, uchar duan)     //λ���ݣ�������
{
	dx = 1;
	P0 = duanxuan[duan];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[wei];
	wx = 0;
	Delay_ms_1();
}
/*******************************************�������ʾ3bit����******************/
void DigitalTube_Display_num_3bit(uchar shu)
{
	uchar bai, shi, ge;
	bai = shu / 100;
	shi = shu / 10 % 10;
	ge = shu % 10;

	DigitalTube_Display_1bit(0, bai);
	DigitalTube_Display_1bit(1, shi); 
	DigitalTube_Display_1bit(2, ge);
}
/*******************************************�������ʾ6bit******************/
void DigitalTube_Display_6bit(uchar zero, uchar one, uchar two, uchar three, uchar four, uchar five)
{
	DigitalTube_Display_1bit(0, zero);
	DigitalTube_Display_1bit(1, one);
	DigitalTube_Display_1bit(2, two);
	DigitalTube_Display_1bit(3, three);
	DigitalTube_Display_1bit(4, four);
	DigitalTube_Display_1bit(5, five);
}
/*******************************************�������ʾHELLO******************/
void DigitalTube_Display_smg_HELLO()
{
	dx = 1;
	P0 = HELLO[0];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[0];
	wx = 0;
	Delay_ms_1();

	dx = 1;
	P0 = HELLO[1];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[1];
	wx = 0;
	Delay_ms_1();

	dx = 1;
	P0 = HELLO[2];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[2];
	wx = 0;
	Delay_ms_1();

	dx = 1;
	P0 = HELLO[3];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[3];
	wx = 0;
	Delay_ms_1();

	dx = 1;
	P0 = HELLO[4];   //�Ͷ�����
	dx = 0;
	P0 = 0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
	wx = 1;
	P0 = weixuan[4];
	wx = 0;
	Delay_ms_1();
}