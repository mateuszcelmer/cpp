#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    constexpr auto day = 24h;
    day.count();
    constexpr auto minutes = std::chrono::duration_cast<std::chrono::minutes>(day).count();
    constexpr auto secs = std::chrono::duration_cast<std::chrono::seconds>(day).count();

    static_assert(minutes == 24 * 60);
    static_assert(secs == 24 * 60 * 60);

    std::cout << "minutes: " << minutes << std::endl;
    std::cout << "secs: " << secs << std::endl;
    return 0;
}