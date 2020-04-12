#include <iostream>
using namespace std;
#define SHOW(M){cout<< "Private Virt Fun -  Class " << M << "\n"; }
#define CLASS(M) void Show() \
  {cout << "Public Method -  Class " << M <<  "\n";show(); }\
                 virtual void Show1() \
  {cout << "Public Virt Fun -  Class " << M << "\n";show(); }


class A {
  friend void Call0(A&);
  virtual void show() SHOW("A");
  public:  CLASS("A");
};


class B : public A {
  virtual void show() SHOW("B");
  public:   CLASS("B");
};
void Call0(A& a) {
  cout << " Friend function: " << "\n";
  a.show();
}
void Call1(A& a) {
 cout << " Non Friend function: " << "\n";
 a.Show1();
}
int main() {
  A a;   B b;
  Call0(a); Call0(b);
  Call1(a); Call1(b);
}
