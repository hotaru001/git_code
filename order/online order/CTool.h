#pragma once
#include <windows.h>
#include <conio.h>
class CTool
{
public:
	static void gotoxy(int x, int y);
	static void paintWindow(int x, int y, int w, int h);
	static char getKey();
};

