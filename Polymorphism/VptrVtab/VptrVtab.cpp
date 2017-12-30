// VptrVtab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }

#pragma pack(push, 4)
struct  A {
	int i;
	virtual void f() SHOW(" Virt fun from ", "A"); 
	void f1() 	SHOW(" Fun from ", "A"); 
	A(int j) { i = j; }
};
struct B : public A {
	int i;
	void f() SHOW(" Virt fun from ", "B");
	void f1() SHOW(" Fun from ", "B");
	B(int j1, int j2): A(j2) { i = j1; }
};
#pragma pack(pop)

void main()
{
	
	cout << " sizeof int - " << sizeof(int) << " sizeof int* - " << sizeof(int*) << "\n sizeof A - " << sizeof(A) << " sizeof B - " << sizeof(B) << "\n";
	A* p = new A(1);
	p->f(); p->f1();
	p = new B(2,3);
	p->f(); p->f1();
	int *p1 = (int*) p;
	cout << " "  <<*p1 << " " << *(p1+1) << " " << *(p1 + 2) << " " << *(p1 + 3) <<"\n";
	long long *p2 =  (long long*) p;
	cout << " sizeof long long - " << sizeof(long long) << "\n";
	cout << " " << *p2 << " " << *((int*)p2) <<" " << *(((int*)p2+1)) << "\n";
	p2 = (long long *)(*p2);
	cout << " " << *p2 << "\n";
	//cout << " " << (int*)p->f;
	long long *p3 = new long long; memcpy(p3,p2, sizeof(long long ));
	cout << " " << *p3 << "\n";

	std::cout << reinterpret_cast<void *>(p->f) << std::endl;


	A(B(4,5)).f(); A(B(4, 5)).f1(); // поліморфізм нівелюється

	system("pause");
}
