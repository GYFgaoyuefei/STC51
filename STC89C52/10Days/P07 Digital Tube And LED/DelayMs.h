#define uint unsigned int
#define uchar unsigned char

/*********************************************************/
// ���뼶����ʱ������time��Ҫ��ʱ�ĺ�����
/*********************************************************/
void DelayMs(uint time)
{
	uint i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 113; j++);
}

