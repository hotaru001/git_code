#include "CTool.h"
#include <stdio.h>
void CTool::gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}
void CTool::paintWindow(int x, int y, int w, int h)
{
	int j, i;
	gotoxy(x, y); //�t�s���r���q
	printf("�q");
	for (j = 0; j < w; j++)
	{
		printf(" ��");
	}
	gotoxy(x + 2 * w, y);
	printf("�r");
	for (i = 0; i < h; i++)
	{
		gotoxy(x, y + i + 1);
		printf("��\n");
	}
	for (i = 0; i < h; i++)
	{
		gotoxy(x + 2 * w, y + i + 1);
		printf("��\n");
	}
	gotoxy(x, y + h);
	printf("�t");
	for (j = 0; j < w; j++)
	{
		printf(" ��");
	}
	gotoxy(x + 2 * w, y + h);
	printf("�s\n");
}
char CTool::getKey()
{
	//����+��ĸ
	// �������
	//��ü��̵�ֵ,��Ϊ������һ�ο��Ի������ֵ -32/224��ʾ����� ,��һ�����Ƿ���������ֵ
	//Enter (13)
	//72---> �� 80 ---->�� 75 --->�� 77 ---->��
	char key = _getch();
	if (key == -32) //224 /-32
	{
		key = _getch();
		switch (key)
		{
		case 72:
			return -1; //��
		case 80:
			return -2; //��
		case 75:
			return -3; //��
		case 77:
			return -4; //��
		}
	}
	else
	{
		return key;
	}
}