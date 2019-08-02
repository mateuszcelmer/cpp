#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    Point p = {1, 2};

    //Structure binding
    auto [x_coord, y_coord] = p;

    std::cout << x_coord << " : " << y_coord << std::endl;

    return 0;
}