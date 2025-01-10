#pragma once
#include "CtrlBase.h"
class CEdit :public CtrlBase
{
public:
	//构造函数
	CEdit(int x = 0, int y = 0, int w = 0, int h = 0, const char* content =
		nullptr, int ctrlType = 0, int ips = 1, int maxLen = 6, int inputType = 1);
	//析构函数
	~CEdit();
	void keyListen(char key);
private:
	int ips; //明文 1/密文 2
	int maxLen;//最大输入长度 6
	int inputType;//输入格式 1数字 2 字符 3+数字+字符
};

