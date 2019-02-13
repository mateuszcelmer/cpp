#include <iostream>
using namespace std;

/* Poziom 1*/
class A
{
  int x;

public:
  A()
  {
    cout << "Konstruktor A() wywolany" << endl;
  }
  A(int i)
  {
    x = i;
    cout << "Konstruktor A(int i) wywolany" << endl;
  }
  ~A() { cout << "Destruktor A() wywolany" << endl; }
  void print() { cout << x; }
};

/* Poziom 2*/
class B : virtual public A
{
public:
  B() : A(10)
  {
    cout << "Konstruktor B() wywolany" << endl;
  }
  ~B() { cout << "Destruktor B() wywolany" << endl; }
};

/* Poziom 2*/
class C : virtual public A
{
public:
  C()
  {
    A(20);
    cout << "Konstruktor C() wywolany" << endl;
  }
  ~C() { cout << "Destruktor C() wywolany" << endl; }
};

/* Poziom 3*/
class D : public B, public C
{
public:
  D() : B(), C() { cout << "Konstruktor D() wywolany" << endl; }
  // ~D() { cout << "Destruktor D() wywolany" << endl; }
};

int main()
{
  D d;
  d.print();
  return 0;
}