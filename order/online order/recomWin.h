#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
#include "CLogWin.h"
#include "CMyDb.h"
class recomWin :public CWinBase
{
public:
	recomWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~recomWin();
	int do_action();
	void insert_into_orders(const char* username = nullptr, int i = 0, double price = 0);
private:
};

