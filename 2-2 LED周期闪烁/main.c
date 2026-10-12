/*
    2026.10.12 17:32
		目的：
		      了解单片机控制串口原理
		      学习使用串口助手
					获取延时函数
		功能：
					实现 LED 灯周期性闪烁
*/

#include <REGX52.H>
#include <INTRINS.H> // _nop_()所需头函数

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(void)
{
	while(1)
	{
		P2 = 0xFE;
		Delay500ms();  //500ms延时
	  P2 = 0XFF;
		Delay500ms();  //500ms延时
	}
}