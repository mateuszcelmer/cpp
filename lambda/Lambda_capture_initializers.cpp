#include <iostream>

using namespace std;

int factory(int i) { return i * 10; }

auto f = [x = factory(2)] { return x; };

int main()
{
    std::cout << f() << std::endl; // 20

    return 0;
}