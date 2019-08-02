#include <iostream>

using namespace std;

struct A
{
    virtual void foo();
};

struct B : A
{
    virtual void foo() final;
};

struct C : B
{
    virtual void foo(); // error -- declaration of 'foo' overrides a 'final' function
};

// ========= class ================

struct X final
{
};

struct Y : X
{ // error -- base 'A' is marked 'final'
};
`

    int
    main()
{

    return 0;
}