#include <iostream>

class B
{
  public:
    int x;
    void foo(int i) { x = i; }
};

class C
{
  public:
    int y;
    void foo(int i) { y = i; }
};

class D : virtual public B, virtual public C
{
  public:
    void foo(int o)
    {
        B::foo(o);
        C::foo(2 * o);
    }
};

int main()
{
    D d;
    d.foo(12);
    std::cout << "x = " << d.x << " y = " << d.y << std::endl;
}