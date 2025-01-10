#include "CTool.h"
#include <stdio.h>
void CTool::gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
void CTool::paintWindow(int x, int y, int w, int h)
{
	int j, i;
	gotoxy(x, y); //╰╯│╮─╭
	printf("╭");
	for (j = 0; j < w; j++)
	{
		printf(" ─");
	}
	gotoxy(x + 2 * w, y);
	printf("╮");
	for (i = 0; i < h; i++)
	{
		gotoxy(x, y + i + 1);
		printf("│\n");
	}
	for (i = 0; i < h; i++)
	{
		gotoxy(x + 2 * w, y + i + 1);
		printf("│\n");
	}
	gotoxy(x, y + h);
	printf("╰");
	for (j = 0; j < w; j++)
	{
		printf(" ─");
	}
	gotoxy(x + 2 * w, y + h);
	printf("╯\n");
}
char CTool::getKey()
{
	//数字+字母
	// 方向键盘
	//获得键盘的值,因为方向是一次可以获得两个值 -32/224表示方向键 ,下一个才是方向键具体的值
	//Enter (13)
	//72---> 上 80 ---->下 75 --->左 77 ---->右
	char key = _getch();
	if (key == -32) //224 /-32
	{
		key = _getch();
		switch (key)
		{
		case 72:
			return -1; //上
		case 80:
			return -2; //下
		case 75:
			return -3; //左
		case 77:
			return -4; //右
		}
	}
	else
	{
		return key;
	}
}