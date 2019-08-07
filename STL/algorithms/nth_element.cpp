#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int liczby[] = {10, 1, 2, 7, 2, 5, 9};
    int n = 7;
    std::nth_element(liczby,
                     liczby + (n - 1) / 2,
                     liczby + n);
    std::cout << liczby[(n - 1) / 2] << std::endl;

    for (auto &&x : liczby)
        std::cout << x << ", ";

    return 0;
}