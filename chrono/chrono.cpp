#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10'000; i++)
        auto x = i * i;
    end = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    double t = elapsed_seconds.count();

    std::cout << t << std::endl;

    return 0;
}