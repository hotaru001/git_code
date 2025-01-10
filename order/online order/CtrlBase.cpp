#define _CRT_SECURE_NO_WARNINGS

#include "CtrlBase.h"
#include "CTool.h"
#include <iostream>
#include <string.h>
using namespace std;
CtrlBase::CtrlBase(int x, int y, int w, int h, const char* content, int ctrlType) :x(x), y(y), w(w), h(h), ctrlType(ctrlType)
{
	memset(this->content, '\0', sizeof(this->content));
	if (content != nullptr)
	{
		strcpy(this->content, content);
	}
}
CtrlBase::~CtrlBase()
{
}
void CtrlBase::show()
{
	//移动光标
	CTool::gotoxy(this->x, this->y);
	//画框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//显示内容
	CTool::gotoxy(this->x + 3, this->y + 2);
	cout << this->content << endl;
}
int CtrlBase::getX() //x坐标
{
	return this->x;
}
int CtrlBase::getY() //y坐标
{
	return this->y;
}
int CtrlBase::getCtrlType()
{
	return this->ctrlType;
}
void CtrlBase::keyListen(char key)
{
}
char* CtrlBase::getContent() //获得内容
{
	return this->content;
}