#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    tuple<int, double, string> test(3, 2.3, "Text");

    auto v1 = get<0>(test);
    auto v2 = get<1>(test);
    auto v3 = get<2>(test);

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    // ---
    std::cout << std::endl;
    auto player = std::make_tuple(12, "asdasd", std::string{"sdasdasdasd"});
    std::cout << std::get<0>(player) << std::endl;
    std::cout << std::get<1>(player) << std::endl;
    std::cout << std::get<2>(player) << std::endl;

    return 0;
}