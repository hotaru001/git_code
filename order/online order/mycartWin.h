#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
#include "CLogWin.h"
#include "CMyDb.h"
class mycartWin :public CWinBase
{
public:
	mycartWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~mycartWin();
	int do_action();
private:
};

