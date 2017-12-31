// functionalzamykannya 4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>

struct GetContext
{
	HWND hw;
	HDC hdc;
	GetContext(HWND hwn) 	{
		hw = hwn;
		hdc = GetDC(hwn);
	}
	void Text(int x, int y, char* string) 	{
		TextOut(hdc, x, y, (LPSTR)string, strlen(string));
	}
	~GetContext() { ReleaseDC(hw, hdc); }
};
void Fun(HWND hwnd)
{
	GetContext hdc(hwnd);
	hdc.Text(1, 2, "Error");
}

