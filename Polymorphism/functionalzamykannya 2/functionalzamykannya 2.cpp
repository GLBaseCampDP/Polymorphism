// functionalzamykannya 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <windows.h>
#include <string.h>
struct GetContext {
	HWND hwindow;
	HDC hdc;
	GetContext(HWND hwnd) {
		hwindow = hwnd;
		hdc = GetDC(hwnd);
	}
	~GetContext() { ReleaseDC(hwindow, hdc); }
};
struct Text : GetContext {
	Text(HWND hwnd, int x, int y, char* str) :
		GetContext(hwnd)	{
		TexOut(hdc, x, y, (LPSTR)(str), strlen(str);
	}
};
void main()
{
	HWND hwnd;
	Text message(hwnd, 3, 5, "Error");
}

