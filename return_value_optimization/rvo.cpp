#include <iostream>

using namespace std;

struct C
{
    C() {}
    C(const C &) { std::cout << "A copy was made.\n"; }
};

C f()
{
    return C();
}

int main()
{
    std::cout << "Hello World!\n";
    C obj = f();
    return 0;
}

/*
Depending on the compiler & settings, the following outputs are all valid:

Hello World!
A copy was made.
A copy was made.
---
Hello World!
A copy was made.
---
Hello World!

*/