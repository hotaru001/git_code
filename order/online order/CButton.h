#pragma once
#include "CtrlBase.h"
class CButton :public CtrlBase
{
public:
	//���캯��
	CButton(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, int ctrlType = 0);
	//��������
	~CButton();
private:
};

