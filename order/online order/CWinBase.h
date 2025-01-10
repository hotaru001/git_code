#pragma once
#include <iostream>
#include <vector> //容器 动态数组
#include "CtrlBase.h"
#include "CTool.h"
using namespace std;
class CWinBase
{
public:
	CWinBase(int x = 0, int y = 0, int w = 0, int h = 0);
	~CWinBase();
	void show(); //显示
	void win_run();//窗口运行,人机交互
	//纯虚函数:自己本身是虚函数,为了实现多态,但该函数的实现本身没有意义,可以写成纯虚函数
	//纯虚函数 virtual 返回值类型 函数名(参数列表)=0;
	virtual int do_action() = 0; //纯虚函数
protected:
	int x;
	int y;
	int w;
	int h;
	vector <CtrlBase*> ctrlArry;
	int focuxIndex; //控件的下标
};

