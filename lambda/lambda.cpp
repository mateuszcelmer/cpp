#include <iostream>
using namespace std;

int main()
{
    auto foo = [](int i) -> double { return 2 * i; };
    double d = foo(7);
    cout << "d = " << d << endl;

    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}