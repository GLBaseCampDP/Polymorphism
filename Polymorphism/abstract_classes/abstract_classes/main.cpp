#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // абстрактний клас
  virtual void show() = 0; //нульова функція
};

struct B: public A {};

struct C: public B { void show() SHOW("C");};

struct D: public A { void show() SHOW("D");};

// Шлюз на клас A
void Show(A* a) { a->show(); }

int main() {
 //A a; помилка створeння
 //об'єкта абстракт. класу
 //B b; Show(b); клас В є абстрактним
 C c; Show(&c);
 // неправильний виклик нульової ф-ії
 // c.A::show();
 // виклик переозначеної нульової ф-її
 D d; Show(&d);
}
