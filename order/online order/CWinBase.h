#pragma once
#include <iostream>
#include <vector> //���� ��̬����
#include "CtrlBase.h"
#include "CTool.h"
using namespace std;
class CWinBase
{
public:
	CWinBase(int x = 0, int y = 0, int w = 0, int h = 0);
	~CWinBase();
	void show(); //��ʾ
	void win_run();//��������,�˻�����
	//���麯��:�Լ��������麯��,Ϊ��ʵ�ֶ�̬,���ú�����ʵ�ֱ���û������,����д�ɴ��麯��
	//���麯�� virtual ����ֵ���� ������(�����б�)=0;
	virtual int do_action() = 0; //���麯��
protected:
	int x;
	int y;
	int w;
	int h;
	vector <CtrlBase*> ctrlArry;
	int focuxIndex; //�ؼ����±�
};

