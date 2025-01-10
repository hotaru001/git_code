#define _CRT_SECURE_NO_WARNINGS
#include "recomWin.h"
recomWin::recomWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    CLabel* aaa = new CLabel(2, 16, 4, 4, "编号", 3);
    CEdit* eee = new CEdit(12, 16, 3, 4, "", 1, 1, 2, 1);
    CButton* bbb = new CButton(23, 16, 8, 4, "添加至购物车", 2);
    CButton* ccc = new CButton(2, 21, 8, 4, "查看购物车", 2);
    CButton* ddd = new CButton(23, 21, 8, 4, "返回", 2);
    this->ctrlArry.push_back(aaa);
    this->ctrlArry.push_back(eee);
    this->ctrlArry.push_back(bbb);
    this->ctrlArry.push_back(ccc);
    this->ctrlArry.push_back(ddd);
}
recomWin::~recomWin()
{

}
void recomWin::insert_into_orders(const char* username, int i, double price)
{
    char sql[1024];
    sprintf(sql, "INSERT INTO orders (username, order_code, price) VALUES ('%s', '%d', %f);", username, i, price);
    cout << "sql:" << sql << endl;
    CMyDb* cdb = CMyDb::getIntanse();
    cdb->no_result_exec(sql);
}
int recomWin::do_action()
{
    if (this->focuxIndex == 2)
    {
        char* username = nullptr;
        char* ordercode = this->ctrlArry[1]->getContent();
        if (strncmp(ordercode, "1", 2) == 0)
        {
            int i = 19;
            insert_into_orders(username, i, 19.9);
        }
        else if (strncmp(ordercode, "2", 2) == 0)
        {
            int i = 20;
            insert_into_orders(username, i, 27.9);
        }
        else if (strncmp(ordercode, "3", 2) == 0)
        {
            int i = 21;
            insert_into_orders(username, i, 29.9);
        }
        else if (strncmp(ordercode, "4", 1) == 0)
        {
            int i = 22;
            insert_into_orders(username, i, 34.9);
        }
        else if (strncmp(ordercode, "5", 1) == 0)
        {
            int i = 23;
            insert_into_orders(username, i, 39.9);
        }
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 6;
    }
    if (this->focuxIndex == 3)
    {
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 5;
    }
    if (this->focuxIndex == 4)
    {
        memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
        return 2;
    }
}
