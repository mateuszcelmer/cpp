#include <iostream>

using namespace std;

enum class Color
{
    Red,
    Green,
    Blue
};

void foo(Color c)
{
    std::cout << static_cast<size_t>(c) << std::endl;
}

int main()
{
    Color c = Color::Blue;
    foo(c);
    return 0;
}