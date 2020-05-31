#include <iostream>

using namespace std;

class A {
    public:
        A() {std::cout << "A" << std::endl;}
};

class B {
    public:
        B() {std::cout << "B" << std::endl;}
};

class C : public A, B {
    public:
        C() {std::cout << "C" << std::endl;}
};



int main()
{
    C c;   
    return 0;
}