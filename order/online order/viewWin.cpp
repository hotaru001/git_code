#include "viewWin.h"
#include "CMyDb.h"
viewWin::viewWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    CButton* aaa = new CButton(5, 2, 6, 4, "���˲�", 2);
    CButton* bbb = new CButton(20, 2, 6, 4, "˫�˲�", 2);
    CButton* ccc = new CButton(35, 2, 6, 4, "���˲�", 2);
    CButton* ddd = new CButton(5, 8, 6, 4, "Сʳ��Ʒ", 2);
    CButton* eee = new CButton(20, 8, 6, 4, "���", 2);
    CButton* fff = new CButton(35, 8, 6, 4, "��ĩר��", 2);
    CButton* hhh = new CButton(20, 16, 6, 4, "����", 2);
    this->ctrlArry.push_back(aaa);
    this->ctrlArry.push_back(bbb);
    this->ctrlArry.push_back(ccc);
    this->ctrlArry.push_back(ddd);
    this->ctrlArry.push_back(eee);
    this->ctrlArry.push_back(fff);
    this->ctrlArry.push_back(hhh);
}
viewWin::~viewWin()
{
}
int viewWin::do_action()
{
    if (this->focuxIndex == 6)
    {
        return 2;
    }
    else if (this->focuxIndex == 0)
    {
        return 4;
    }
    else if (this->focuxIndex == 1)
    {
        return 7;
    }
    else if (this->focuxIndex == 2)
    {
        return 8;
    }
    else 
    {
        MessageBox(NULL, TEXT("û������"), TEXT("��ʾ"), MB_OK);
        return 3;
    }
}