#define _CRT_SECURE_NO_WARNINGS
#include "CRegWin.h"
#include "CTool.h"
#include "CMyDb.h"
#include <windows.h>
#include <cstring>
CRegWin::CRegWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
	//new ��ǩ�Ķ���
	CLabel* userLabel = new CLabel(3, 3, 10, 4, "�û���", 3); //ctrlType 3.��ǩ�� 1.�༭���� 2.��ť��
	CEdit * userEdit = new CEdit(35, 3, 15, 4, "", 1, 1, 6, 3);
	CLabel* pwdLabel = new CLabel(3, 10, 10, 4, "����", 3);
	CEdit* pwdEdit = new CEdit(35, 10, 15, 4, "", 1, 2, 6, 1);
	CLabel* rePwdLabel = new CLabel(3, 17, 10, 4, "ȷ������", 3);
	CEdit* rePwdEdit = new CEdit(35, 17, 15, 4, "", 1, 2, 6, 1);
	CButton* cRegBtn = new CButton(3, 22, 5, 4, "��¼", 2);
	CButton* cLoginBtn = new CButton(25, 22, 5, 4, "ע��", 2);
	CButton* cancelBtn = new CButton(50, 22, 5, 4, "ȡ��", 2);
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
			MessageBox(NULL, TEXT("�����������벻һ��"), TEXT("����"), MB_OK);
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
			MessageBox(NULL, TEXT("�û����Ѵ���"), TEXT("����"), MB_OK);
			sqlite3_free_table(result);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			memset(this->ctrlArry[5]->getContent(), 0, sizeof(this->ctrlArry[5]->getContent()));
			return 1;
		}
		else 
		{
			// ƴ��SQL�������
			char asql[100] = { '\0' };
			sprintf(asql, "insert into user(username,pwd) values ('%s','%s');", username, pwd);
			cout << "sql:" << asql << endl;
			// ִ�в������
			cdb->no_result_exec(asql);
			MessageBox(NULL, TEXT("ע��ɹ�"), TEXT("��ʾ"), MB_OK);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			memset(this->ctrlArry[5]->getContent(), 0, sizeof(this->ctrlArry[5]->getContent()));
			return 0;
		}
	}
	else if (this->focuxIndex == 8)
	{
		//cout << "����ע�ᴰ�ڵ�ȡ����ť" << endl;
		MessageBox(NULL, TEXT("���˳�"), TEXT("��ʾ"), MB_OK);
		return -1;
	}
}