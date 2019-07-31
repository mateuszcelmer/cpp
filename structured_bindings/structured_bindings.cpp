#include <iostream>

using namespace std;

using Coordinate = std::pair<int, int>;
Coordinate origin()
{
    return Coordinate{0, 0};
}

int main()
{
    const auto [x, y] = origin();

    std::cout << x << std::endl
              << y << std::endl;
    return 0;
}