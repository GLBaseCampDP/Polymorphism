// functionalzamykannya 3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <String>

struct Popup {
	Popup(int x1, int y1, int x2, int y2)
	{/* ���������� ���������*/}
	virtual ~Popup() {/*���������� ������������*/}
};

struct PopupWin	{
	PopupWin() : pop(1, 2, 10, 40) { }
	Popup pop;
	void Out(char* mes) {
		//�������� ����� ����
		//����������� ����
	}
	~PopupWin() {/* �������� ����� ����*/ }
};
	
void main()	{
	PopupWin pw;
	pw.Out("Error");
}
