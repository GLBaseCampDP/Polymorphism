// functionalzamykanya 1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

struct Popup {
public:
	Popup(int x1, int y1, int x2, int y2) {/* ���������� ���������*/}
		virtual void Out() = 0;
		virtual ~Popup() {/*���������� ������������*/}
};
struct PopupWin : public Popup	{
	PopupWin() : Popup(1, 10, 20, 30)
 	{/*�������� ����� ����*/}
    void Out()	{/* ����*/ }
	~PopupWin(){/* �������� ����� ����*/}
};
void main()  {
	PopupWin w;
	w.Out();
}
