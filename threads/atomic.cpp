#include <iostream>
#include <string>
#include <atomic>
#include <future>

using namespace std;

int main()
{
    std::atomic<int> counter{100};

    auto f = std::async(std::launch::deferred, [&]() { counter = {111}; });
    std::cout << counter.load() << std::endl;

    f.get();
    std::cout << counter.load() << std::endl;

    counter++;
    std::cout << counter.load() << std::endl;

    counter = 123;
    std::cout << counter.load() << std::endl;

    return 0;
}