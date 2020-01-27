#include <iostream>

#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A {
  //порожня віртуальна функція
  virtual void show() {}
};

struct B: public A {};
struct D: public A
 { void show()SHOW("D");};

struct C: public B { void show()SHOW("C");};

// Шлюз на клас A
void Show(A* a) { a->show(); }

//виклик віртуально функції ::show()
int main() { Show(new C); }
