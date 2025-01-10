#pragma once
#include "CWinBase.h"
#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
class CLogWin :public CWinBase
{
public:
	CLogWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CLogWin();
	int do_action();
	char* get_username();
private:
	char* myusername;
};
