// EmptyVirtualFunction.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A {
	//порожня віртуальна функція
	virtual void show() {}
};
struct B :public A {};
struct D :public A {
public:
	void show()	SHOW("D");
};
struct C : public B {
	void show() SHOW("C");
};
// Шлюз на клас A
void Show(A* a) { a->show(); }
//виклик віртуально функції ::show()
main() { Show(new C); }


