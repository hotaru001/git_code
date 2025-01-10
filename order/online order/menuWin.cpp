#if 1
#include "menuWin.h"
#include "CMyDb.h"
menuWin::menuWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    CButton* viewMenuBtn = new CButton(5, 2, 6, 4, "�鿴�˵�", 2);
    CButton* recommendDishesBtn = new CButton(20, 2, 7, 4, "�Ƽ��ײ�", 2);
    CButton* placeOrderBtn = new CButton(38, 2, 6, 4, "���ﳵ", 2);
    CButton* orderStatusBtn = new CButton(5, 8, 10, 4, "����״̬��ѯ", 2);
    CButton* callWaiterBtn = new CButton(30, 8, 10, 4, "���з���Ա", 2);
    CButton* memberServiceBtn = new CButton(5, 14, 10, 4, "��Ա����", 2);
    CButton* feedbackBtn = new CButton(30, 14, 10, 4, "���ۺͷ���", 2);
    CButton* exitBtn = new CButton(20, 20, 7, 4, "�˳���¼", 2);
    this->ctrlArry.push_back(viewMenuBtn);
    this->ctrlArry.push_back(recommendDishesBtn);
    this->ctrlArry.push_back(placeOrderBtn);
    this->ctrlArry.push_back(orderStatusBtn);
    this->ctrlArry.push_back(callWaiterBtn);
    this->ctrlArry.push_back(memberServiceBtn);
    this->ctrlArry.push_back(feedbackBtn);
    this->ctrlArry.push_back(exitBtn);
}
menuWin::~menuWin()
{
}
int menuWin::do_action()
{
    if (this->focuxIndex == 0)
    {
        //�鿴�˵�
        return 3;
    }
    if (this->focuxIndex == 1)
    {
        return 6;
    }
    if (this->focuxIndex == 3)
    {
        MessageBox(NULL, TEXT("���Ķ�������������"), TEXT("��ʾ"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 4)
    {
        MessageBox(NULL, TEXT("����Ա�Ѻ��У������ĵȴ�"), TEXT("��ʾ"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 5)
    {
        MessageBox(NULL, TEXT("�����ǻ�Ա"), TEXT("��ʾ"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 6)
    {
        MessageBox(NULL, TEXT("����δ��ͨ"), TEXT("��ʾ"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 7)
    {
        const char* sql = "DELETE FROM orders;";
        CMyDb* cdb = CMyDb::getIntanse();
        cdb->delete_all_exec(sql);
        return 0;
    }
    if (this->focuxIndex == 2)
    {
        return 5;
    }
}
#endif
