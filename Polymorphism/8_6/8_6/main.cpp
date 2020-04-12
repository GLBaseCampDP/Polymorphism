#include <iostream>
#include <cstring>
using namespace std;
#define SHOW(M,s) { cout << M << s<< "\n"; }


#pragma pack(push, 4)
struct  A { int i;
  virtual void f() SHOW(" Virt fun from ", "A");
  void f1()SHOW(" Fun from ", "A");
  A(int j) { i = j; }
};
struct B : A { int i;
  void f() SHOW(" Virt fun from ", "B");
  void f1() SHOW(" Fun from ", "B");;
  B(int j1, int j2) : A(j2) { i = j1; }
};
#pragma pack(pop)
// Вказівник на функцію-метод класу
typedef void(*PP)(A *const);
typedef void(*PPP)(B *const);
int main() {
  A* p = new B(2, 3); 	// Створення об’єкта класу В
  void** p2; 		// Створення вказівника на ТВФ

  // Ініціалізація вказівника адресою ТВФ
  memcpy(&p2, p, sizeof(p2));
  // Інший спосіб ініціалізації
  //void ** p2 = (void**) *((long long*)(p));


  // Виклик віртуальної функції класу B
  ((PP)(p2[0]))(p);
  //((PPP)(p2[0]))(p);
  ((PP)(p2[0]))(new B(0,0));
  ((PPP)(p2[0]))(new B(0,0));
}
