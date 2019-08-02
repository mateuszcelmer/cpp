#include <iostream>

using namespace std;

struct A
{
    virtual void foo();
    void bar();
};

struct B : A
{
    void foo() override; // correct -- B::foo overrides A::foo
    void bar() override; // error -- A::bar is not virtual
    void baz() override; // error -- B::baz does not override A::baz
};

int main()
{

    return 0;
}