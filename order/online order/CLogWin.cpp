#define _CRT_SECURE_NO_WARNINGS
#include "CLogWin.h"
#include "CMyDb.h"
#include <windows.h>
CLogWin::CLogWin(int x, int y, int w, int h) :CWinBase(x, y, w, h)
{
	//new ��ǩ�Ķ���
	CLabel* userLabel = new CLabel(3, 3, 10, 4, "�û���", 3);
	CEdit* userEdit = new CEdit(35, 3, 15, 4, "", 1, 1, 6, 3);
	CLabel* pwdLabel = new CLabel(3, 10, 10, 4, "����", 3);
	CEdit* pwdEdit = new CEdit(35, 10, 15, 4, "", 1, 1, 6, 1);
	CButton* cRegBtn = new CButton(5, 17, 5, 4, "��¼", 2);
	CButton* cLoginBtn = new CButton(30, 17, 5, 4, "ע��", 2);
	CButton* cancelBtn = new CButton(55, 17, 5, 4, "ȡ��", 2);
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
	return this->myusername; // �����û���
}
//����̳г����࣬����Ĭ��Ҳ�ǳ�����,���봴���������������д���麯��
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
		// ����ѯ��������row����0��˵���ҵ���ƥ����û�
		if (row > 0) 
		{
			// ��¼�ɹ�
			sqlite3_free_table(result); // �ͷŲ�ѯ����ڴ�
			system("cls");
			MessageBox(NULL, TEXT("��¼�ɹ�"), TEXT("��ʾ"), MB_OK);
			this->myusername = this->ctrlArry[1]->getContent();
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
			return 2;
		}
		else 
		{
			// ��¼ʧ��
			sqlite3_free_table(result); // �ͷŲ�ѯ����ڴ�
			system("cls");
			MessageBox(NULL, TEXT("��¼ʧ�ܣ��û��������ڻ��������"), TEXT("��ʾ"), MB_OK);
			memset(this->ctrlArry[1]->getContent(), 0, sizeof(this->ctrlArry[1]->getContent()));
			memset(this->ctrlArry[3]->getContent(), 0, sizeof(this->ctrlArry[3]->getContent()));
		}
		return 0; //0��ʾ��¼��ť
	}
	else if (this->focuxIndex == 5)
	{
		//cout << "���ǵ�¼�е�ע�ᰴť" << endl;
		return 1; //1��ʾע�ᰴť
	}
	else if (this->focuxIndex == 6) //ȡ�� �û����������е�ֵ���
	{
		//cout << "���ǵ�¼���ڵ�ȡ����ť" << endl;
		MessageBox(NULL, TEXT("���˳�"), TEXT("��ʾ"), MB_OK);
		return -1;
	}
}