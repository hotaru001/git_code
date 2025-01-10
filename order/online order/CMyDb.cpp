#include "CMyDb.h"
#include <iostream>

using namespace std;
//��ʼ����̬���ݳ�Ա:ʹ������ģʽ
CMyDb* CMyDb::intanse = nullptr;
CMyDb* CMyDb::getIntanse()
{
	if (CMyDb::intanse == nullptr)
	{
		CMyDb::intanse = new CMyDb;
	}
	return CMyDb::intanse;
}
CMyDb::CMyDb()
{
	//���캯���д����ݿ�
	//����1:���ݿ������
	//����2:������ݿ���
	sqlite3_open("pro.db", &this->mydb);
}
CMyDb::~CMyDb()
{
	sqlite3_close(this->mydb);
}
void CMyDb::no_result_exec(const char* sql)
{
	int ret = 0;
	char* errmsg = nullptr;
	ret = sqlite3_exec(this->mydb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		//cout << "errmsg" << errmsg << endl;
	}
}
void CMyDb::get_result_exec(const char* sql, char**& result, int& row, int &column)
{
	char* errmsg = nullptr;
	sqlite3_get_table(this->mydb, sql, &result, &row, &column, &errmsg);
}
void CMyDb::delete_all_exec(const char* sql)
{
	int ret = 0;
	char* errmsg = nullptr;
	ret = sqlite3_exec(this->mydb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "Error: " << errmsg << endl;
		sqlite3_free(errmsg); // �ͷŴ�����Ϣ�ڴ�
	}
}