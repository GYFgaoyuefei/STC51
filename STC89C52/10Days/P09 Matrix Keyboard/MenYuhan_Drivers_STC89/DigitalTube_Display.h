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

	0x77,		//A--10
	0x7c,		//b--11
	0x39,		//C--12
	0x5e,		//d--13
	0x79,		//E--14
	0x71,		//F--15
	0x3d,		//G--16
	0x76,		//H--17
	0x11,		//i--18
	0x0e,		//J--19
	0x7a,		//k--20
	0x38,		//L--21
	0x55,		//M--22
	0x54,		//n--23
	0X3f,		//O--24
	0x73,		//P--25
	0x67,		//q--26
	0x50,		//r--27
	0x6d,		//S--28
	0x78,		//t--29
	0x3e,		//U--30
	0x3e,		//V--31
	0x6a,		//W--32
	0x76,		//X--33
	0x6e,		//y--34
	0x5b,		//Z--35

	0x7b,		//e--36
	0x74,		//h--37
	0x5c,		//o--38
	0x1c,		//u--39
	0x62,		//v--40

	0x00		//0x00Ϊȫ����--41
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
/*******************************************ȫ�ֱ���**********************************************/
/********************************************IO����************************/
//sbit wx = P2 ^ 7;
//sbit dx = P2 ^ 6;
/***********************************************����**********************************************/
/*******************************************�������ʾ1bit******************/
void DigitalTube_Display_1bit(uchar wei, uchar duan)     //λ���ݣ�������
{
	P0 = 0x00;		//�رն���ʾ
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
void DigitalTube_Display_Str_HELLO()
{
	DigitalTube_Display_6bit(HELLO[0], HELLO[1], HELLO[2], HELLO[3], HELLO[4], HELLO[5]);
}
