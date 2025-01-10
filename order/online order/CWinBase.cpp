#include "CWinBase.h"
CWinBase::CWinBase(int x, int y, int w, int h) :x(x), y(y), w(w), h(h)
{
}
CWinBase::~CWinBase()
{
	for (int i = 0; i < this->ctrlArry.size(); i++)
	{
		delete this->ctrlArry[i];
	}
}
void CWinBase::show()
{
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	for (int i = 0; i < this->ctrlArry.size(); i++)
	{
		//this->ctrlArry[0] --->CtrlBase *
		this->ctrlArry[i]->show();
	}
}
void CWinBase::win_run()
{
	int i = 0;
	for (i = 0; i < this->ctrlArry.size(); i++)
	{
		if (this->ctrlArry[i]->getCtrlType() == 1) //CEdit
		{
			CTool::gotoxy(this->ctrlArry[i]->getX() + 3, this->ctrlArry[i] -> getY() + 2);
			break;
		}
		else if (this->ctrlArry[i]->getCtrlType() == 2) //��ťCButton
		{
			CTool::gotoxy(this->ctrlArry[i]->getX() + 3, this->ctrlArry[i] -> getY() + 2);
			break;
		}
	}
	while (1)
	{
		int key = CTool::getKey();
		switch (key)
		{
		case -2: //��
			i++;
			if (i == this->ctrlArry.size())
			{
				i = 0;
			}
			if (this->ctrlArry[i]->getCtrlType() == 1 || this->ctrlArry[i] -> getCtrlType() == 2)
			{
				CTool::gotoxy(this->ctrlArry[i]->getX() + 3, this->ctrlArry[i] -> getY() + 2);
			}
			break;
		case -1: //��
			i--;
			if (i < 0)
			{
				i = this->ctrlArry.size() - 1;
			}
			if (this->ctrlArry[i]->getCtrlType() == 1 || this->ctrlArry[i]->getCtrlType() == 2)
			{
				CTool::gotoxy(this->ctrlArry[i]->getX() + 3, this->ctrlArry[i]->getY() + 2);
			}
			break;
		case -3:
			//��
			break;
		case -4:
			//��
			break;
		case 13: //�س�
		//�����ť��Ҫʵ��ʲô����
			if (this->ctrlArry[i]->getCtrlType() == 2) //��ʾ�ǲ��ǰ�ť
			{
				this->focuxIndex = i; //���ؼ����±걣����focuxIndex��
				//������̬
				//this->do_action(); //CWinBse-->do_action (�麯��)
				// CRegWin--->do_action �����൱����д�麯�� // CLogWin -->do_action
				return;
			}
			break;
		default:
			//�����ַ�
			if (this->ctrlArry[i]->getCtrlType() == 1) //�༭�� ���̵���¼�
			{
				//this->ctrlArry[i] ==> (CtrlBase *) virtual keyListen
				// --->(CEdit *) --->keyListen
				this->ctrlArry[i]->keyListen(key);
			}
		}
	}
}