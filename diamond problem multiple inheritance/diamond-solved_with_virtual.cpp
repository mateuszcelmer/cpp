#include <iostream>
using namespace std;

// Virtual inheritance solves the classic “Diamond Problem”.
// It ensures that the child class gets only a single instance of the common base class.
// https://www.freecodecamp.org/news/multiple-inheritance-in-c-and-the-diamond-problem-7c12a9ddbbec/

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

class B : virtual public A
{
public:
  B()
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
  cout << "d.print() = ";
  d.print();
  return 0;
}