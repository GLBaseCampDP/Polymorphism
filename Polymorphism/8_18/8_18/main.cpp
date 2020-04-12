#include <iostream>
#define SHOW(S) { std::cout << " class - " << S << '\n'; }


struct A { 				// абстрактний клас
   virtual void show() = 0; 	// нульова функція
   void Show() { A::show(); };
};


void A::show() SHOW("C"); 		// реалізація нульової функції


struct B :public A {   void show() { A::show(); } };


int main() {   B* p = new B;
  p->show(); p->Show();
}
