// Virtual Dtor.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>

#define SHOW(S, c) \
 { std::cout << "  " << S << " class - " << c << '\n'; }

#define CTOR(c1) { c = _strdup(c1); SHOW(" Ctor", c); }
#define  DTOR { SHOW(" Dtor", c); delete c; }

using namespace std;

struct A {
	char* c;
	A(char* c1) CTOR(c1);
	//~A();	   ��������� �����������
	// ���������� �����������
	virtual ~A() DTOR;
};

struct B :public A {
	char *c;
	B(char*c1, char* c2) :A(c2) CTOR(c1);
	~B() DTOR;
};

void main() {
	// ���������� �� ������� ���� �������-
	// ����� ������ ��'���� ��������� �����
	A* a = new B("B", "A");
	delete a;
	system("pause");
}


