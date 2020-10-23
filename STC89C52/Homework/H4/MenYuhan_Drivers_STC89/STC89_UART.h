/************************************初始化*****************************************/
//f=11.0592 MHz
//BR=9600 bps
//Timer=T1
//Timer Mode=2
//定时器时钟:12T
void UART1_Init()
{
	PCON &= 0x7F;	//波特率不倍速
	SCON = 0x50;	//8位数据,可变波特率
	AUXR &= 0xBF;	//定时器1时钟为Fosc/12,即12T
	AUXR &= 0xFE;	//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;	//清除定时器1模式位
	TMOD |= 0x20;	//设定定时器1为8位自动重装方式
	TL1 = 0xfd;		//设定定时初值
	TH1 = 0xfd;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
//	ES = 1;			//启动串口中断
	ES = 0;			//关闭串口中断
}
/************************************中断*****************************************/
/**********************************中断功能********************/
void UART1_INT_Func()
{
		
}
/**********************************进入中断********************/
void UART1_INT() interrupt 4
{
	UART1_INT_Func();
}