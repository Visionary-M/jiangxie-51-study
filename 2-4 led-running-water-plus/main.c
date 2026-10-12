/*
    2026.10.12 20:06
		目的：
		     学会如何改良延时
				 实现自主输入时间参数实现延时
				 本质上就是写一个能够传参的函数
				 实现多次循环即可
		功能：
				 点亮 LED 灯
*/
#include <REGX52.H>


void Delay1ms(unsigned  int xms)		
// 1ms 的时延函数
// 通过 while 循环实现用户输入指定参数
// @12.000MHz
{
	unsigned char i, j;

	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		
		xms--;
	} 
}

void main(void)
{
	while(1)
	{
		P2 = 0xFE; // 1111 1110
		Delay1ms(500);
		
		P2 = 0xFD; // 1111 1101
		Delay1ms(500);
		
		P2 = 0xFB; // 1111 1011
		Delay1ms(500);
		
		P2 = 0xF7; // 1111 0111
		Delay1ms(500);
		
		P2 = 0x7F; // 1110 1111
		Delay1ms(500);
		
		P2 = 0xDF; // 1101 1111
		Delay1ms(500);
		
		P2 = 0xBF; // 1011 1111
		Delay1ms(500);
		
		P2 = 0x7F; // 0111 1111
		Delay1ms(500);
	}
}

