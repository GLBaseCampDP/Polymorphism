#include <iostream>
#define SHOW(M,s) { std::cout << M << s<< "\n"; }
#define CLASS(M) int i;\
 virtual void f() SHOW(" Virt fun f from ", M);


struct  A { CLASS("A");  A(int j) : i(j) {} };
struct B : virtual A { CLASS("B");
  B(int j1, int j2) : A(j2), i(j1) {}
};
struct C : virtual A { CLASS("C");
  C(int j1, int j2) :A(j2), i(j1) {}
};
// помилка немає однозначного перевизначення
/*struct D_bad : B, C {
 * D_bad(int j1, int j2) : C(j2), i(j1) {} };
*/
// немає помилка перевизначення - однозначне
struct D_good : B, C { CLASS("D_good");
  D_good(int j1, int j2) : B(j1, j2), C(j1, j2),
    A(j1), i(j1) {}
};


struct B_new : virtual A {
  B_new(int j1, int j2) : A(j2) {}
};


// немає помилка перевизначення - однозначне
struct D_good2 : B_new, C {
  D_good2(int j1, int j2) : B_new(j1,j2),
   C(j1, j2), A(j1) {}
};
