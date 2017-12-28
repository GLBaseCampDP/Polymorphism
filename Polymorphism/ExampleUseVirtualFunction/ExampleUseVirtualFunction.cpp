// ExampleUseVirtualFunction.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
#define SHOW(S) \
 { cout << " class - " << S << '\n'; }
struct A {
	//віртуальна функція
	virtual void show() SHOW("A");
	void getShow() { 
		cout << " Call in method "; show(); 
	}
};

struct B : public A {
	//переозначення віртуальної функції
	// і поширення віртуальності на похідні класи
	virtual void show() SHOW("B");
};

struct C : public B {
	//переозначення віртуальної функції
	void show() SHOW("C");
};

// реалізація поліморфізму
void Output(A* a) { a->show(); }
void Output(A& a) { a.show(); }

void main() {
	A aa, &a = aa;
	Output(&a); Output(a);	 // приклади виклику
	B b; Output(&b); Output(b);
	// виклик віртуальної ф-ї через наслідувану
	b.getShow();
	C* c = new C; Output(c); Output(*c);
	A* p = (C*)new A; Output(p); Output(*p);
	system("pause");
}