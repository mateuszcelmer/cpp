#include <iostream>

using namespace std;

struct A
{
    virtual void foo() { cout << "foo from A" << endl; };
    virtual void bar() { cout << "bar from A" << endl; };
};

struct B : A
{
    void foo() override { cout << "foo from B" << endl; };
    void bar() { cout << "bar from B" << endl; };
};

struct C : B
{
    void foo() { cout << "foo from C" << endl; };
    void bar() { cout << "bar from C" << endl; };
};

int main()
{
    C c;
    c.foo();
    c.bar();
    B &b = c;
    b.foo();
    b.bar();
    return 0;
}