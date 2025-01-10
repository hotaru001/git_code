#if 1
#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
class menuWin :public CWinBase
{
public:
	menuWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~menuWin();
	int do_action();
private:
};
#endif

