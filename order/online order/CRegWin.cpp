#define _CRT_SECURE_NO_WARNINGS
#include "CRegWin.h"
#include "CTool.h"
#include "CMyDb.h"
#include <windows.h>
#include <cstring>
CRegWin::CRegWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
	//new 标签的对象
	CLabel* userLabel = new CLabel(3, 3, 10, 4, "用户名", 3); //ctrlType 3.标签类 1.编辑框类 2.按钮类
	CEdit * userEdit = new CEdit(35, 3, 15, 4, "", 1, 1, 6, 3);
	CLabel* pwdLabel = new CLabel(3, 10, 10, 4, "密码", 3);
	CEdit* pwdEdit = new CEdit(35, 10, 15, 4, "", 1, 2, 6, 1);
	CLabel* rePwdLabel = new CLabel(3, 17, 10, 4, "确认密码", 3);
	CEdit* rePwdEdit = new CEdit(35, 17, 15, 4, "", 1, 2, 6, 1);
	CButton* cRegBtn = new CButton(3, 22, 5, 4, "登录", 2);
	CButton* cLoginBtn = new CButton(25, 22, 5, 4, "注册", 2);
	CButton* cancelBtn = new CButton(50, 22, 5, 4, "取消", 2);
	this->ctrlArry.push_back(userLabel);
	this->ctrlArry.push_back(userEdit);
	this->ctrlArry.push_back(pwdLabel);
	this->ctrlArry.push_back(pwdEdit);
	this->ctrlArry.push_back(rePwdLabel);
	this->ctrlArry.push_back(rePwdEdit);
	this->ctrlArry.push_back(cRegBtn);
	this->ctrlArry.push_back(cLoginBtn);
	this->ctrlArry.push_back(cancelBtn);
}
CRegWin::~CRegWin()
{
}
int CRegWin::do_action()
{
	if (this->focuxIndex == 6)
	{
		return 0;
	}
	else if (this->focuxIndex == 7)
	{
		char* username = this->ctrlArry[1]->getContent();
		char* pwd = this->ctrlArry[3]->getContent();
		char* repwd = this->ctrlArry[5]->getContent();
		if (strcmp(pwd, repwd) != 0)
		{
			MessageBox(NULL, TEXT("两次输入密码不一致"), TEXT("错误"), MB_OK);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			memset(this->ctrlArry[5]->getContent(), 0, sizeof(this->ctrlArry[5]->getContent()));
			return 1;
		}
		CMyDb* cdb = CMyDb::getIntanse();
		char sql[256] = { '\0' };
		sprintf(sql, "SELECT * FROM user WHERE username = '%s';", username);
		char** result = nullptr;
		int row = 0;
		int column = 0;
		cdb->get_result_exec(sql, result, row, column);
		if(row > 0)
		{
			MessageBox(NULL, TEXT("用户名已存在"), TEXT("错误"), MB_OK);
			sqlite3_free_table(result);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			memset(this->ctrlArry[5]->getContent(), 0, sizeof(this->ctrlArry[5]->getContent()));
			return 1;
		}
		else 
		{
			// 拼接SQL插入语句
			char asql[100] = { '\0' };
			sprintf(asql, "insert into user(username,pwd) values ('%s','%s');", username, pwd);
			cout << "sql:" << asql << endl;
			// 执行插入语句
			cdb->no_result_exec(asql);
			MessageBox(NULL, TEXT("注册成功"), TEXT("提示"), MB_OK);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			memset(this->ctrlArry[5]->getContent(), 0, sizeof(this->ctrlArry[5]->getContent()));
			return 0;
		}
	}
	else if (this->focuxIndex == 8)
	{
		//cout << "我是注册窗口的取消按钮" << endl;
		MessageBox(NULL, TEXT("已退出"), TEXT("提示"), MB_OK);
		return -1;
	}
}