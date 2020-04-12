#include <iostream>
#define SHOW(S) { std::cout << " class - " << S << '\n'; }


struct A {  virtual void show() = 0; }; 	// абстрактний клас
struct B: public A {};
struct C: public B { void show() SHOW("C");};
struct D: public A { void show() SHOW("D");};


void Show(A* a) { a->show(); } 			// шлюз на клас A
int main() {
 //A a; 			помилка створeння об'єкта абстракт. класу
 //B b; Show(b); 	клас В є абстрактним
 C c; Show(&c);
 // c.A::show(); 	// неправильний виклик нульової ф-ії
 D d; Show(&d);  	// виклик переозначеної нульової ф-її
}

