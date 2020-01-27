#include <iostream>
#define SHOW(S) \
 { std::cout << " class - " << S << '\n'; }

struct A { // абстрактний клас
 //нульові і ненульові функції
 virtual void show() = 0, show2() = 0, show3();
 //virtual ~A() = 0; допускається
};

void A::show3() {
 std::cout << " Non pure Fun from class A\n";
}

// клас залишається абстрактним –
// не визначена show2
struct B : A {
  void show()SHOW("C");
  ~B() {}
};

// клас вже не абстрактний
struct C : B {   void show2() SHOW("C"); };

// клас знову став абстрактний
struct D :  C {  void show3() override = 0; };

int main() {
  A* a = new C ; a->show();
}
