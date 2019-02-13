#include <iostream>
using namespace std;

/* Poziom 1*/
class A
{
public:
  A() { cout << "Konstruktor A() wywolany" << endl; }
  ~A() { cout << "Destruktor A() wywolany" << endl; }
};

/* Poziom 2*/
class B : virtual public A
{
public:
  B() { cout << "Konstruktor B() wywolany" << endl; }
  ~B() { cout << "Destruktor B() wywolany" << endl; }
};

/* Poziom 2*/
class C : virtual public A
{
public:
  C() { cout << "Konstruktor C() wywolany" << endl; }
  ~C() { cout << "Destruktor C() wywolany" << endl; }
};

/* Poziom 3*/
class D : public B, public C
{
public:
  D() { cout << "Konstruktor D() wywolany" << endl; }
  ~D() { cout << "Destruktor D() wywolany" << endl; }
};

int main()
{
  D d;
  return 0;
}