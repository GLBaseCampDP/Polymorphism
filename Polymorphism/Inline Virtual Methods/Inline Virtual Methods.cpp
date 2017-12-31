// Inline Virtual Methods.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
struct A {
	inline virtual void show() { cout << "Class A:" << "\n"; }
};
struct B : A {
	inline void show() { cout << "Class B:" << "\n"; }
};

void Call(A& a) {
	a.show();
}
void main() {
	A a;   B b;
	a.show(); b.show();

	Call(a); Call(b);
	system("pause");
}




