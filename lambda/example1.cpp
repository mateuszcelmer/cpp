#include <iostream>
#include <string>

using namespace std;

void test(std::string str)
{
    std::cout << "123ABC : " << str << std::endl;
}

int main()
{
    auto timeFuncInvocation =
        [](auto &&func, auto &&... params) {
            // start timer
            std::forward<decltype(func)>(func)(
                std::forward<decltype(params)>(params)...);
            // stop timer and calculate elapsed time
        };

    timeFuncInvocation(test, "abc");

    return 0;
}