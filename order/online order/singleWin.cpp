#define _CRT_SECURE_NO_WARNINGS
#include "singleWin.h"
singleWin::singleWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    /*
    cout << "--------���˲�--------" << endl;
    cout << "1.[����]��ʳ����ѡOK������  19.9" << endl;
    cout << "2.�ϱ���������˲�  27.9" << endl;
    cout << "3.ȫ�����ֲͣ�����Ʒըȫ����  29.9" << endl;
    cout << "4.֭֭��ţ�������ļ���  34.9" << endl;
    cout << "5.����¶��ʥ����߲�  39.9" << endl;
    cout << "6.�����ļ��׵��˲� 34.9" << endl;
    cout << "7.֭֭��ţ�������� 30.9" << endl;
    cout << "8.���������׵��˲� 29.9" << endl;
    cout << "9.��������׵��˲� 39.9" << endl;
    cout << "10.��ţ�����ƴ 39.9" << endl;
    cout << "11.[��ֵ�����]���人�����ƴ 39.9" << endl;
    cout << "12.��֥����֭֭��ţ�������� 31.9" << endl;
    */
    CLabel* aaa = new CLabel(2, 16, 4, 4, "���", 3);
    //CEdit* aaa = new CEdit(2, 16, 4, 4, "", 1, 1, 6, 3);
    CEdit* eee = new CEdit(12, 16, 3, 4, "", 1, 1, 2, 1);
    CButton* bbb = new CButton(23, 16, 8, 4, "��������ﳵ", 2);
    CButton* ccc = new CButton(2, 21, 8, 4, "�鿴���ﳵ", 2);
    CButton* ddd = new CButton(23, 21, 8, 4, "����", 2);
    this->ctrlArry.push_back(aaa);
    this->ctrlArry.push_back(eee);
    this->ctrlArry.push_back(bbb);
    this->ctrlArry.push_back(ccc);
    this->ctrlArry.push_back(ddd);
}
singleWin::~singleWin()
{
}
void singleWin::insert_into_orders(const char* username, int i, double price)
{
    char sql[1024];
    sprintf(sql, "INSERT INTO orders (username, order_code, price) VALUES ('%s', '%d', %f);", username, i, price);
    cout << "sql:" << sql << endl;
    CMyDb* cdb = CMyDb::getIntanse();
    cdb->no_result_exec(sql);
}
int singleWin::do_action()
{
    //char* username = logWin.get_username();//����CLogWin�����get_username������ȡ�û���
    if (this->focuxIndex == 2)
    {
        char* username = nullptr;
        char *ordercode = this->ctrlArry[1]->getContent();
        if (strncmp(ordercode, "1", 2)==0)
        {
            int i = 1;
            insert_into_orders(username, i, 19.9);
        }
        else if (strncmp(ordercode, "2", 1) == 0)
        {
            int i = 2;
            insert_into_orders(username, i, 27.9);
        }
        else if (strncmp(ordercode, "3", 1) == 0)
        {
            int i = 3;
            insert_into_orders(username, i, 29.9);
        }
        else if (strncmp(ordercode, "4", 1) == 0)
        {
            int i = 4;
            insert_into_orders(username, i, 34.9);
        }
        else if (strncmp(ordercode, "5", 1) == 0)
        {
            int i = 5;
            insert_into_orders(username, i, 39.9);
        }
        else if (strncmp(ordercode, "6", 1) == 0)
        {
            int i = 6;
            insert_into_orders(username, i, 34.9);
        }
        else if (strncmp(ordercode, "7", 1) == 0)
        {
            int i = 7;
            insert_into_orders(username, i, 30.9);
        }
        else if (strncmp(ordercode, "8", 1) == 0)
        {
            int i = 8;
            insert_into_orders(username, i, 29.9);
        }
        else if (strncmp(ordercode, "9", 1) == 0)
        {
            int i = 9;
            insert_into_orders(username, i, 39.9);
        }
        else if (strncmp(ordercode, "10", 2) == 0)
        {
            int i = 10;
            insert_into_orders(username, i, 39.9);
        }
        else if (strncmp(ordercode, "11", 2) == 0)
        {
            int i = 11;
            insert_into_orders(username, i, 39.9);
        }
        else if (strncmp(ordercode, "12", 2) == 0)
        {
            int i = 12;
            insert_into_orders(username, i, 31.9);
        }
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 4;
    }
    if (this->focuxIndex == 3)
    {
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 5;
    }
    if (this->focuxIndex == 4)
    {
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 3;
    }
}