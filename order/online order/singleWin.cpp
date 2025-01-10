#define _CRT_SECURE_NO_WARNINGS
#include "singleWin.h"
singleWin::singleWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    /*
    cout << "--------单人餐--------" << endl;
    cout << "1.[热销]主食随心选OK三件套  19.9" << endl;
    cout << "2.老北京鸡肉卷单人餐  27.9" << endl;
    cout << "3.全鸡可乐餐（含新品炸全鸡）  29.9" << endl;
    cout << "4.汁汁嫩牛堡经典四件套  34.9" << endl;
    cout << "5.赞萌露比圣诞玩具餐  39.9" << endl;
    cout << "6.汉堡四件套单人餐 34.9" << endl;
    cout << "7.汁汁和牛堡两件套 30.9" << endl;
    cout << "8.汉堡三件套单人餐 29.9" << endl;
    cout << "9.汉堡五件套单人餐 39.9" << endl;
    cout << "10.和牛堡疯狂拼 39.9" << endl;
    cout << "11.[超值五件套]经典汉堡疯狂拼 39.9" << endl;
    cout << "12.奶芝意面汁汁和牛堡两件餐 31.9" << endl;
    */
    CLabel* aaa = new CLabel(2, 16, 4, 4, "编号", 3);
    //CEdit* aaa = new CEdit(2, 16, 4, 4, "", 1, 1, 6, 3);
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
    //char* username = logWin.get_username();//调用CLogWin对象的get_username方法获取用户名
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