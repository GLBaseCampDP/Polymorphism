#include <iostream>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }
#pragma pack(push, 4)
struct  A {
 int i;
 virtual void f() SHOW(" Virt fun f from ", "A");
 virtual void f1()SHOW(" Virt fun f1 from ", "A");
 A(int j) { i = j; }
};
struct B : A {
 int i;
 void f() SHOW(" Virt fun f from ", "B");
 B(int j1, int j2) : A(j2) { i = j1; }
};
struct C : B {
 int i;
 void f() SHOW(" Virt fun f from ", "B");
 void f1() SHOW(" Virt fun f1 from ", "B");;
 C(int j1, int j2, int j3) : B(j2, j3) { i = j1; }
};
#pragma pack(pop)
void memory (A* p, int cnt , const char* m) {
  int *p1 = (int*)p;
  cout<<"\nstart adress "<<m<< ": "<<(long long)p<< "\n";
  for (int i = 0; i < cnt; ++i)
    cout << "    ofsset - " << i << " sizeof (int) - " <<  *(p1 + i) << "\n";
}


void vptr_vtab(A* p) {
 long long *p2 = (long long*)p;
 cout <<" *vtpr (8b) - "<<*p2<< " #divide by 4b - " <<*((int*)p2)<<" "<<*(((int*)p2 + 1))<<"\n";
 cout << " *vtab - " << *((long long*)(*p2)) << "\n\n";
}
 int main() {
  A* p = new A(1);
  p->f();  p->f1();
  memory(p, 3, "A"); // аналіз памяті з кроком sizeof(int)
  vptr_vtab(p);      // визначення vptr
  p = new B(2, 3);
  p->f(); p->f1();
  memory(p, 4, "B"); // аналіз памяті з кроком sizeof(int)
  vptr_vtab(p);      // визначення vptr
  p = new C(4, 5, 6);
  p->f(); p->f1();
  memory(p, 5, "C"); // аналіз памяті з кроком sizeof(int)
  vptr_vtab(p);      // визначення vptr
}
