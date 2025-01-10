#include "CMyDb.h"
#include <iostream>

using namespace std;
//初始化静态数据成员:使用懒汉模式
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
	//构造函数中打开数据库
	//参数1:数据库的名字
	//参数2:获得数据库句柄
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
		sqlite3_free(errmsg); // 释放错误信息内存
	}
}