#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
class viewWin :public CWinBase
{
public:
	viewWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~viewWin();
	int do_action();
private:
};

