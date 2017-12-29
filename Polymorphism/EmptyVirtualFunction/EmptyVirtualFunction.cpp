// EmptyVirtualFunction.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A {
	//������� ��������� �������
	virtual void show() {}
};
struct B :public A {};
struct D :public A {
	void show()	SHOW("D");
};
struct C : public B {
	void show() SHOW("C");
};
// ���� �� ���� A
void Show(A* a) { a->show(); }
//������ ��������� ������� ::show()
void main() { Show(new C); }




