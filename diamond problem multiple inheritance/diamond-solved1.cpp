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
    cout << "Konstruktor A() wywolany" << endl;
  }
  A(int i)
  {
    x = i;
    cout << "Konstruktor A(int i) wywolany, x = " << x << endl;
  }
  ~A() { cout << "Destruktor A() wywolany" << endl; }
  void print() { cout << x << endl; }
};

/* Poziom 2*/

class B : virtual public A
{
public:
  B() : A(20) // A(20) konstruktor virtualnej klasy, znajdujący się w initializer list, jest ignorowany -> https://en.cppreference.com/w/cpp/language/initializer_list
  {
    cout << "Konstruktor B() wywolany" << endl;
  }
  B(int i)
  {
    x = i;
    cout << "Konstruktor B(int i) wywolany, x = " << x << endl;
  }
  ~B() { cout << "Destruktor B() wywolany" << endl; }
};

/* Poziom 2*/
class C : virtual public A
{
public:
  C()
  {
    // A(30);
    cout << "Konstruktor C() wywolany" << endl;
  }
  ~C() { cout << "Destruktor C() wywolany" << endl; }
};

/* Poziom 3*/
class D : public B, public C
{
public:
  D() : B(123), C()
  {
    cout << "Konstruktor D() wywolany" << endl;
  }
  ~D()
  {
    cout << "Destruktor D() wywolany" << endl;
  }
};

int main()
{
  D d;
  cout << "d.print() = ";
  d.print();

  d.A::print();
  d.B::print();
  d.C::print();
  return 0;
}