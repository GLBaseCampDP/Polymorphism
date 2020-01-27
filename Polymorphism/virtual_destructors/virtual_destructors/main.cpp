#include <iostream>

#define SHOW(S, c) \
 { std::cout << "  " << S << \
 " class - " << c << '\n'; }

#define CTOR(c1) { c = c1; \
  SHOW(" Ctor", c); }

#define  DTOR { SHOW(" Dtor", c); }

struct A {
  char c;
  A(char c1) CTOR(c1);
  //~A() DTOR;  // звичайний dtor
  virtual ~A() DTOR; // віртуальний dtor
};

struct B :public A {
  char c;
  B(char c1, char c2) :A(c2) CTOR(c1);
  ~B() DTOR;
};

int main() {
  A* a = new B('B', 'A');
  delete a;

}
