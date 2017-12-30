// FinalInVirtualFunctions.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
struct A
{
	virtual void f() {
		std::cout << "A" << '\n';
	}
};
struct B : A
{
	// override � ������������� ��������������
	void f() final override {
		std::cout << "B" << '\n';
	}

	void B::f1()
	{
	}
	
};
struct C : B
{
	// void f() {}    ����������� �������������
};


void main()
{
	A* p = new B;
	p->f();
	p = new C;
	p->f();


}





