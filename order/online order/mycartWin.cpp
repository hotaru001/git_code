#include "mycartWin.h"
mycartWin::mycartWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
	CLabel* ddd = new CLabel(2, 18, 8, 4, "删除的编号", 3);
	CEdit* fff = new CEdit(20, 18, 5, 4, "", 1, 1, 2, 1);
	CButton* eee = new CButton(32, 18, 5, 4, "删除", 2);
	CButton* aaa = new CButton(2, 23, 8, 4, "清空购物车", 2);
	CButton* bbb = new CButton(20, 23, 5, 4, "付款", 2);
	CButton* ccc = new CButton(32, 23, 5, 4, "返回", 2);
	this->ctrlArry.push_back(ddd);
	this->ctrlArry.push_back(fff);
	this->ctrlArry.push_back(eee);
	this->ctrlArry.push_back(aaa);
	this->ctrlArry.push_back(bbb);
	this->ctrlArry.push_back(ccc);
}
mycartWin::~mycartWin()
{
}
int mycartWin::do_action()
{
	if (this->focuxIndex == 2)
	{
		CMyDb* cdb = CMyDb::getIntanse();
		char* ordercode = this->ctrlArry[1]->getContent();
		string sql = "DELETE FROM orders WHERE order_code = '" + string(ordercode) + "';";
		cdb->no_result_exec(sql.c_str());
		memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
		return 5;
	}
	if (this->focuxIndex == 3)
	{
		MessageBox(NULL, TEXT("购物车已清空"), TEXT("提示"), MB_OK);
		const char* sql = "DELETE FROM orders;";
		CMyDb* cdb = CMyDb::getIntanse();
		cdb->delete_all_exec(sql);
		return 5;
	}
	if (this->focuxIndex == 4)
	{
		MessageBox(NULL, TEXT("已下单，请完成支付"), TEXT("提示"), MB_OK);
		const char* sql = "DELETE FROM orders;";
		CMyDb* cdb = CMyDb::getIntanse();
		cdb->delete_all_exec(sql);
		return 2;
	}
	else if (this->focuxIndex == 5)
	{
		return 2;
	}
}