// AbstractClass.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // абстрактний клас
	//нульова функція
	virtual void show() = 0;
};
struct B :public A {};
struct С :public B {
	void show()	SHOW("C");
};
struct D : public A {
	void show()	SHOW("D");
};
// Шлюз на клас A
void Show(A* a) { a->show(); }

void main() {
	//A a; // помилка створeння 
	// об'єкта абстракт. класу
	//B b; Show(b); клас В є абстрактним
	С c; Show(&c);

	// c.A::show(); неправильний виклик 
	// чисто вірт. ф-ії

	D d; Show(&d); // виклик наслідуваної 
				  // переозначеної чисто вірт. ф-її
}



