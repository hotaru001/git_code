#pragma once
#include "CtrlBase.h"
class CEdit :public CtrlBase
{
public:
	//���캯��
	CEdit(int x = 0, int y = 0, int w = 0, int h = 0, const char* content =
		nullptr, int ctrlType = 0, int ips = 1, int maxLen = 6, int inputType = 1);
	//��������
	~CEdit();
	void keyListen(char key);
private:
	int ips; //���� 1/���� 2
	int maxLen;//������볤�� 6
	int inputType;//�����ʽ 1���� 2 �ַ� 3+����+�ַ�
};

