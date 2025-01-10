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
		else if (this->ctrlArry[i]->getCtrlType() == 2) //按钮CButton
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
		case -2: //下
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
		case -1: //上
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
			//左
			break;
		case -4:
			//右
			break;
		case 13: //回车
		//点击按钮需要实现什么功能
			if (this->ctrlArry[i]->getCtrlType() == 2) //表示是不是按钮
			{
				this->focuxIndex = i; //将控件的下标保存在focuxIndex中
				//触发多态
				//this->do_action(); //CWinBse-->do_action (虚函数)
				// CRegWin--->do_action 在子类当中重写虚函数 // CLogWin -->do_action
				return;
			}
			break;
		default:
			//其他字符
			if (this->ctrlArry[i]->getCtrlType() == 1) //编辑框 键盘点击事件
			{
				//this->ctrlArry[i] ==> (CtrlBase *) virtual keyListen
				// --->(CEdit *) --->keyListen
				this->ctrlArry[i]->keyListen(key);
			}
		}
	}
}