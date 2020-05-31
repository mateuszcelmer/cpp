#include <iostream>
using namespace std;

/* Poziom 1*/
class A
{
protected:
  int x;

public:
  A()
  {
    x = 1;
    cout << "Konstruktor A() wywolany" << endl;
  }
  ~A() { cout << "Destruktor A() wywolany" << endl; }
  void print() { cout << x << endl; }
};

/* Poziom 2*/

class B : public A
{
public:
  B()
  {
    cout << "Konstruktor B() wywolany" << endl;
  }
  ~B() { cout << "Destruktor B() wywolany" << endl; }
};

/* Poziom 2*/
class C : public A
{
public:
  C()
  {
    cout << "Konstruktor C() wywolany" << endl;
  }
  ~C() { cout << "Destruktor C() wywolany" << endl; }
};

/* Poziom 3*/
class D : public B, public C
{
public:
  D() : B(), C() { cout << "Konstruktor D() wywolany" << endl; }
  ~D() { cout << "Destruktor D() wywolany" << endl; }
};

int main()
{
  D d;
  // d.print();  // error: request for member ‘print’ is ambiguous

  d.B::print();
  d.C::print();

  return 0;
}