#pragma once
#include "CtrlBase.h"
//CLabel继承于CtrlBase
class CLabel :public CtrlBase
{
public:
	//构造函数
	CLabel(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, int ctrlType = 0);
	//析构函数
	~CLabel();
private:
};
