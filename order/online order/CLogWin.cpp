#define _CRT_SECURE_NO_WARNINGS
#include "CLogWin.h"
#include "CMyDb.h"
#include <windows.h>
CLogWin::CLogWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
	//new 标签的对象
	CLabel* userLabel = new CLabel(3, 3, 10, 4, "用户名", 3);
	CEdit* userEdit = new CEdit(35, 3, 15, 4, "", 1, 1, 6, 3);
	CLabel* pwdLabel = new CLabel(3, 10, 10, 4, "密码", 3);
	CEdit* pwdEdit = new CEdit(35, 10, 15, 4, "", 1, 1, 6, 1);
	CButton* cRegBtn = new CButton(5, 17, 5, 4, "登录", 2);
	CButton* cLoginBtn = new CButton(30, 17, 5, 4, "注册", 2);
	CButton* cancelBtn = new CButton(55, 17, 5, 4, "取消", 2);
	this->ctrlArry.push_back(userLabel);
	this->ctrlArry.push_back(userEdit);
	this->ctrlArry.push_back(pwdLabel);
	this->ctrlArry.push_back(pwdEdit);
	this->ctrlArry.push_back(cRegBtn);
	this->ctrlArry.push_back(cLoginBtn);
	this->ctrlArry.push_back(cancelBtn);
}
CLogWin::~CLogWin()
{
}
char* CLogWin::get_username()
{
	return this->myusername; // 返回用户名
}
//子类继承抽象类，子类默认也是抽象类,若想创建对象，子类必须重写纯虚函数
int CLogWin::do_action()
{
	if (this->focuxIndex == 4)
	{
		char* username = this->ctrlArry[1]->getContent();
		char* pwd = this->ctrlArry[3]->getContent();
		char sql[256] = { '\0' };
		sprintf(sql, "SELECT * FROM user WHERE username = '%s' AND pwd = '%s';", username, pwd);
		CMyDb* cdb = CMyDb::getIntanse();
		char** result = nullptr;
		int row = 0;
		int column = 0;
		cdb->get_result_exec(sql, result, row, column);
		// 检查查询结果，如果row大于0，说明找到了匹配的用户
		if (row > 0) 
		{
			// 登录成功
			sqlite3_free_table(result); // 释放查询结果内存
			system("cls");
			MessageBox(NULL, TEXT("登录成功"), TEXT("提示"), MB_OK);
			this->myusername = this->ctrlArry[1]->getContent();
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			return 2;
		}
		else 
		{
			// 登录失败
			sqlite3_free_table(result); // 释放查询结果内存
			system("cls");
			MessageBox(NULL, TEXT("登录失败：用户名不存在或密码错误"), TEXT("提示"), MB_OK);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
		}
		return 0; //0表示登录按钮
	}
	else if (this->focuxIndex == 5)
	{
		//cout << "我是登录中的注册按钮" << endl;
		return 1; //1表示注册按钮
	}
	else if (this->focuxIndex == 6) //取消 用户名和密码中的值清空
	{
		//cout << "我是登录窗口的取消按钮" << endl;
		MessageBox(NULL, TEXT("已退出"), TEXT("提示"), MB_OK);
		return -1;
	}
}