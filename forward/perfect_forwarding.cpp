#include <iostream>
#include <utility>

using namespace std;

struct A {
    A() = default;
    A(const A& a) {std::cout << "copied" << std::endl;}
    A(A&& a) {std::cout << "moved" << std::endl;}
    A(int a, int b) {std::cout << "two params" << std::endl;}
};


template <typename... Args>
A wrapper(Args &&... args)
{
    return A{std::forward<Args>(args)...};
}

int main()
{
    wrapper(A{});
    A a;
    wrapper(a);
    wrapper(std::move(a));
    wrapper(1,2);
    return 0;
}