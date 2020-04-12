#include <iostream>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }


#define CLASS(M) int i;\
 virtual void f() SHOW(" Virt fun f from ", M);\
 void f1()SHOW(" Fun f1 from ", M);


struct  A { CLASS("A"); A(int j) : i(j) {} };
struct B : A {  CLASS("B");
  B(int j1, int j2) : A(j2), i(j1) {}
};


struct C { CLASS("C"); C(int j) : i(j) {} };
struct D : C { CLASS("D");
  D(int j1, int j2) : C(j2), i(j1) {}
};
struct P : B, D {
    P(int j1, int j2, int j3, int j4) :
      B(j1, j2), D(j3, j4) {}
};


int main() {
    A* p = new P(5, 6, 7, 8);
    p->f();  p->f1(); 	// неоднозначності немає
    P a(5, 6, 7, 8);
    // a.f(); помилка - невідомо яку функцію викликати
    ((A)a).f(); 		// можливий виклик
    a.C::f();   		// можливий виклик
}
