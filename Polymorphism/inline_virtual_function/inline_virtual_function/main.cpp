#include <iostream>
using namespace std;

struct A {
  inline virtual void show()
   { cout << "Class A:" << "\n"; }
};

struct B : A {
  inline void show()
   { cout << "Class B:" << "\n"; }
};

void Call(A& a) { a.show(); }

int main() {
  A a;   B b;
  a.show(); b.show();

  Call(a); Call(b);
}
