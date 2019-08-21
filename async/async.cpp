#include <iostream>
#include <thread>
#include <future>

using namespace std;

int foo()
{
    std::this_thread::sleep_for(2s);
    return 1000;
}

int main()
{
    std::cout << "start" << std::endl;
    auto handle = std::async(std::launch::async, foo);
    // auto handle = std::async(std::launch::deferred, foo);

    std::cout << "---" << std::endl;
    auto result = handle.get();
    std::cout << result << "\nend" << std::endl;
    return 0;
}