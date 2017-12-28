// ExampleUseVirtualFunction.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
#define SHOW(S) \
 { cout << " class - " << S << '\n'; }
struct A {
	//��������� �������
	virtual void show() SHOW("A");
	void getShow() { 
		cout << " Call in method "; show(); 
	}
};

struct B : public A {
	//������������� ��������� �������
	// � ��������� ����������� �� ������ �����
	virtual void show() SHOW("B");
};

struct C : public B {
	//������������� ��������� �������
	void show() SHOW("C");
};

// ��������� �����������
void Output(A* a) { a->show(); }
void Output(A& a) { a.show(); }

void main() {
	A aa, &a = aa;
	Output(&a); Output(a);	 // �������� �������
	B b; Output(&b); Output(b);
	// ������ ��������� �-� ����� ����������
	b.getShow();
	C* c = new C; Output(c); Output(*c);
	A* p = (C*)new A; Output(p); Output(*p);
	system("pause");
}