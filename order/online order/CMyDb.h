#pragma once
#include "sqlite3.h"
#include <vector>
class CMyDb
{
public:
	~CMyDb();
	static CMyDb* getIntanse();
	void no_result_exec(const char* sql); //≥˝¡Àselect÷¥––”Ô—‘
	void get_result_exec(const char* sql, char**& result, int& row, int& column);
	void delete_all_exec(const char* sql);
private:
	CMyDb();
	static CMyDb* intanse;
	sqlite3* mydb;
};

