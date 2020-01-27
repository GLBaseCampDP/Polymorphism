#include <iostream>
struct A {
  virtual void f() {
    std::cout << 'A' << '\n';
  }
};
struct B : A {
// override є необов’язковим специфікатором
  void f() final override {
    std::cout << 'B' << '\n';
  }
};

struct C : B {
    // void f() {}    заборонено перевизначати
};

int main() {
    A* p = new B;
    p->f();
    p = new C;
    p->f();
}
