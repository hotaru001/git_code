#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
class CRegWin :public CWinBase
{
public:
	CRegWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CRegWin();
	int do_action();
private:
};

