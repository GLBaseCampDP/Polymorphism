#include <iostream>
using namespace std;


#define SHOW(M,s) { cout << M << s<< "\n"; }


#define SIZES cout << " sizeof (int) - " << sizeof(int) << " sizeof (int*) - " << sizeof(int*) << \
  "\n sizeof (long) - " << sizeof(long) <<  " sizeof (long long) - " << sizeof(long long) << \
  "\n sizeof (A) - " << sizeof(A) << " sizeof (B) - " << sizeof(B) << "\n\n";
#pragma pack(push, 4)


struct  A { int i;
  virtual void f() SHOW(" Virt fun from ", "A");
  void f1()SHOW(" Fun from ", "A");
  A(int j) { i = j; }
};


struct B : A { int i;
  void f() SHOW(" Virt fun from ", "B");
  void f1() SHOW(" Fun from ", "B");;
  B(int j1, int j2): A(j2) { i = j1; }
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
int main() { SIZES;
 A* p = new A(1);
 p->f();  p->f1();
 memory(p, 3, "A");			// аналіз пам’яті з кроком sizeof(int)
 vptr_vtab(p); 				// визначення vptr
                        // простіший спосіб - в тілі методу
                        //void* vptr = *reinterpret_cast<void**>( this );


 p = new B(2,3);
 p->f(); p->f1();
 memory(p, 4, "B");			// аналіз пам’яті з кроком sizeof(int)
 vptr_vtab(p); 				// визначення vptr
}
