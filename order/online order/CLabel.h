#pragma once
#include "CtrlBase.h"
//CLabel�̳���CtrlBase
class CLabel :public CtrlBase
{
public:
	//���캯��
	CLabel(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, int ctrlType = 0);
	//��������
	~CLabel();
private:
};
