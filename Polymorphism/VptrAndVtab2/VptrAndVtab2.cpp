// VptrVtab.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }
#define SIZES 	cout << " sizeof (int) - " << sizeof(int) \
<< " sizeof (int*) - " << sizeof(int*) << "\n sizeof (long) - "\
<< sizeof(long) << " sizeof (long long) - " << sizeof(long long) \
<< "\n sizeof (A) - " << sizeof(A) << " sizeof (B) - " << sizeof(B) << "\n\n";


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
	//void f1() SHOW(" Virt fun f1 from ", "B");;
	B(int j1, int j2) : A(j2) { i = j1; }
};

struct C : B {
	int i;
	void f() SHOW(" Virt fun f from ", "C");
	void f1() SHOW(" Virt fun f1 from ", "C");;
	C(int j1, int j2, int j3) : B(j2, j3) { i = j1; }
};


#pragma pack(pop)
void memory(A* p, int cnt, char* m) {
	int *p1 = (int*)p;
	cout << "\nstart adress "<< m <<": " << (long long)p << "\n";
	for (int i = 0; i < cnt; ++i)
		cout << "    ofsset - " << i << " sizeof (int) - " << *(p1 + i) << "\n";
}

void vptr_vtab(A* p) {
	long long *p2 = (long long*)p;
	cout << " #vtpr (8b) - " << *p2 << " #divide by 4b - " << *((int*)p2) << " " << *(((int*)p2 + 1)) << "\n";
	cout << " #vtab - " << *((long long*)(*p2)) << "\n\n";
}

void main() {
	SIZES;

	A* p = new A(1);
	p->f();  	p->f1();
	memory(p, 3, "A");// ����� ����� � ������ sizeof(int)  
	vptr_vtab(p); // ���������� vptr  


	p = new B(2, 3);
	p->f(); p->f1();
	memory(p, 4, "B");// ����� ����� � ������ sizeof(int)
	vptr_vtab(p); // ���������� vptr  

	p = new C(4, 5, 6);
	p->f(); p->f1();
	memory(p, 5, "C");// ����� ����� � ������ sizeof(int)
	vptr_vtab(p); // ���������� vptr  

				  /*
				  void(A::*fA)() = &A::f;
				  void(B::*fB)() = &B::f;
				  void(A::*f1A)() = &A::f1;
				  void(B::*f1B)() = &B::f1;

				  void* p_af = (void*&)fA;
				  void* p_bf = (void*&)fB;
				  void* p_af1 = (void*&)f1A;
				  void* p_bf1 = (void*&)f1B;

				  std::cout << "&A::f = " << (long long)p_af << "  &B::f = " << (long long)p_bf << std::endl <<
				  "&A::f1 = " << (long long)p_af1 << "  &B::f1 = " << (long long)p_bf1 << std::endl;


				  cout << "\n";
				  */
				  //A(B(4,5)).f(); A(B(4, 5)).f1(); // ���������� �����������

	system("pause");
}
