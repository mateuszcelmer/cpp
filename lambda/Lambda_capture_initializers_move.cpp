#include <iostream>
#include <memory>

using namespace std;

int main()
{

    auto p = std::make_unique<int>(1);

    /*
    auto task1 = [=] { *p = 3; }; // ERROR: std::unique_ptr cannot be copied
    */

    auto task2 = [p = std::move(p)]() { *p = 5; }; // OK: p is move-constructed into the closure object
    // the original p is empty after task2 is created

    std::cout << *p << std::endl;
    return 0;
}