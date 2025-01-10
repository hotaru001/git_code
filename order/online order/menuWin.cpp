#if 1
#include "menuWin.h"
#include "CMyDb.h"
menuWin::menuWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
    CButton* viewMenuBtn = new CButton(5, 2, 6, 4, "查看菜单", 2);
    CButton* recommendDishesBtn = new CButton(20, 2, 7, 4, "推荐套餐", 2);
    CButton* placeOrderBtn = new CButton(38, 2, 6, 4, "购物车", 2);
    CButton* orderStatusBtn = new CButton(5, 8, 10, 4, "订单状态查询", 2);
    CButton* callWaiterBtn = new CButton(30, 8, 10, 4, "呼叫服务员", 2);
    CButton* memberServiceBtn = new CButton(5, 14, 10, 4, "会员服务", 2);
    CButton* feedbackBtn = new CButton(30, 14, 10, 4, "评价和反馈", 2);
    CButton* exitBtn = new CButton(20, 20, 7, 4, "退出登录", 2);
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
        //查看菜单
        return 3;
    }
    if (this->focuxIndex == 1)
    {
        return 6;
    }
    if (this->focuxIndex == 3)
    {
        MessageBox(NULL, TEXT("您的订单正在制作中"), TEXT("提示"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 4)
    {
        MessageBox(NULL, TEXT("服务员已呼叫，请耐心等待"), TEXT("提示"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 5)
    {
        MessageBox(NULL, TEXT("您不是会员"), TEXT("提示"), MB_OK);
        return 2;
    }
    if (this->focuxIndex == 6)
    {
        MessageBox(NULL, TEXT("功能未开通"), TEXT("提示"), MB_OK);
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
