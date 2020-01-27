#include <iostream>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }

#define MEMORY(p, cnt, m){int *p1 = (int*)p; cout << "\nstart adress "\
 << m << ": " << (long long)p << "\n"; for (int i = 0; i < cnt; ++i) \
 cout<< "    ofsset - "<< i << " sizeof (int) - " << *(p1 + i) <<"\n";}

#define VPTRVTAB(p) { long long *p2 = (long long*)p;  cout <<\
 " #vtpr (8b) - " << *p2 << " #divide by 4b - "<<*((int*)p2) << " " <<\
 *(((int*)p2 + 1))<<"\n"<< " #vtab - " << *((long long*)(*p2))<<"\n\n";}

#define CLASS(M) int i;\
 virtual void f() SHOW(" Virt fun f from ", M);\
 void f1()SHOW(" Fun f1 from ", M);

#pragma pack(push, 4)
struct  A { CLASS("A");  A(int j): i(j) {} };

struct B:A {CLASS("B"); B(int j1, int j2): A(j2), i(j1){}};

struct C  { CLASS("C");  C(int j): i(j) {} };

struct D:C {CLASS("D"); D(int j1, int j2): C(j2), i(j1){}};

struct P : B, D { CLASS("P");
 P(int j0, int j1, int j2, int j3, int j4) : B(j1, j2),
  D(j3, j4), i(j0) {}
};

#pragma pack(pop)
void memory(A* p, int cnt, const char* m) MEMORY(p, cnt, m);
void memory(C* p, int cnt, const char* m) MEMORY(p, cnt, m);

void vptr_vtab(A* p) VPTRVTAB(p);
void vptr_vtab(C* p) VPTRVTAB(p);

int main() {
 A* p = new A(1);   p->f();  p->f1();
 memory(p, 3, "A");// аналіз памяті з кроком sizeof(int)
 vptr_vtab(p); // визначення vptr

 p = new B(2, 3);  p->f(); p->f1();
 memory(p, 4, "B");// аналіз памяті з кроком sizeof(int)
 vptr_vtab(p); // визначення vptr

 C* pc = new C(1);  pc->f();  pc->f1();
 memory(pc, 3, "C");// аналіз памяті з кроком sizeof(int)
 vptr_vtab(pc); // визначення vptr

 p = new P(4, 5, 6, 7, 8);  p->f(); p->f1();
 memory(p, 9, "P");// аналіз памяті з кроком sizeof(int)
 vptr_vtab(p); // визначення vptr

 pc = new P(4, 5, 6, 7, 8);
 pc->f(); pc->f1();
}
