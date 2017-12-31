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
	void f1()SHOW(" Fun from ", "A");
	A(int j) { i = j; }
};

struct B : A {
	int i;
	void f() SHOW(" Virt fun from ", "B");
	void f1() SHOW(" Fun from ", "B");;
	B(int j1, int j2) : A(j2) { i = j1; }
};

// Вказівник на функцію-метод класу
typedef void(*PP)(A *const);
typedef void(*PPP)(B *const);

void main() {


	A* p = new B(2, 3);
	
	void** p2;
	memcpy(&p2, p, sizeof(p2));
	//void ** p2 = (void**) *((long long*)p);
	((PP)(p2[0]))(p);

	((PPP)(p2[0]))(new B(0,0));
	//((PPP)(p2[0]))(p);




				  

	system("pause");
}
