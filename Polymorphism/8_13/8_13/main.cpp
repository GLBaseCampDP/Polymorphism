#include <iostream>
#define COUT(CC, pp) { std::cout << "\n"<<\
 #CC<<"::show: \n "<<#CC<<"::i -" << CC::pp<<\
 "\n C::i -" << c.pp; }


class C;
struct A {   int i;
   A(int ii) : i(ii) {}
   virtual void show(C& c);
};
struct B : A {    int j;
   B(int jj): A(0), j(jj) {}
   B(int ii, int jj) : A(ii), j(jj) {}
   void show(C& c) override;
};
class C {  int i, j;
           friend void A::show(C&);
           friend void B::show(C&);
           public:
            C(int ii, int jj): i(ii), j (jj) {}
};


void A::show(C& c) COUT(A, i);
void B::show(C& c) COUT(B, j);
void Show(A& a, C& c) { a.show(c); }


int main() {
    A a(10);  B b(20, 30);  C c(40, 50);
    // доступ до приватних членів класу С
    // через дружню віртуальну функцію
    Show(a, c);  Show(b, c);
}

