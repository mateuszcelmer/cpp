#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

using namespace std;

int main()
{
    std::vector<int> longVector;

    // Find element using parallel execution policy
    auto result1 = std::find(std::execution::par, std::begin(longVector), std::end(longVector), 2);

    // Sort elements using sequential execution policy
    std::sort(std::execution::seq, std::begin(longVector), std::end(longVector));

    return 0;
}