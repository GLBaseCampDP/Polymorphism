#include <iostream>


struct A {  inline virtual void show()  { std::cout << "Class A:" << "\n"; }  };


struct B : A {  inline void show()  { std::cout << "Class B:" << "\n"; }  };


void Call(A& a) { a.show(); }


int main() {
  A a;   B b;
  a.show(); b.show();
  Call(a); Call(b);
}
