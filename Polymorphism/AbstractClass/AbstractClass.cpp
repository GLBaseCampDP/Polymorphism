// AbstractClass.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // ����������� ����
	//������� �������
	virtual void show() = 0;
};
struct B :public A {};
struct � :public B {
	void show()	SHOW("C");
};
struct D : public A {
	void show()	SHOW("D");
};
// ���� �� ���� A
void Show(A* a) { a->show(); }

void main() {
	//A a; // ������� �����e��� 
	// ��'���� ��������. �����
	//B b; Show(b); ���� � � �����������
	� c; Show(&c);

	// c.A::show(); ������������ ������ 
	// ����� ���. �-��

	D d; Show(&d); // ������ ���������� 
				  // ������������ ����� ���. �-��
}



