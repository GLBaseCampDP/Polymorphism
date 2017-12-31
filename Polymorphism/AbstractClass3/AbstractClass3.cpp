// AbstractClass3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // абстрактний клас
		   //нульова функція
	virtual void show() = 0;
	void Show() { A::show(); };
};

void A::show() SHOW("C");

struct B :public A {
	void show() { A::show(); }
};


void main() {
	B* p = new B;
	p->show();
	p->Show();
}