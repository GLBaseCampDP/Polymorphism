// AbstractClass 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // ����������� ����
		   //������� �������
	virtual void show() = 0, show2() = 0, show3();
	//	~A() = 0;
};
void A::show3() {
	{ std::cout << " Non pure virtual Fun from class A\n"; }
}

// ���� ���������� ����������� - �� ��������� show2
struct B :public A {
	void show()	SHOW("C");
	~B() {}
};
// ���� ��� �� ����������� 
struct C :public B {
	void show2() SHOW("C");
};
// ���� ����� ���� ����������� 
struct D : public C {
	void show3() override = 0;
};

// ���� �� ���� A
void Show(A* a) { a->show(); }

int main() {
	C c; Show(&c);
	return 1;
}