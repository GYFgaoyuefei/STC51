/*********************************************************/
// ���뼶����ʱ������time��Ҫ��ʱ�ĺ�����
/*********************************************************/
void Delay_Ms(uint time)
{
	uint i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 113; j++);
}