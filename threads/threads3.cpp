// C++11

#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void foo(bool clause)
{
    auto i = 100;
    long x = 0;
    while (i--)
    {
        x += 1;
        std::cout << i << ", ";
    }
}

int main()
{
    std::vector<std::thread> threadsVector;
    threadsVector.emplace_back(foo, true);
    threadsVector.emplace_back([]() {
        cout << "Lambda function, ";
    });
    for (auto &thread : threadsVector)
    {
        thread.join();
    }
    return 0;
}