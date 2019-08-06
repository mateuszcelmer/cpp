#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <cassert>

using namespace boost;

std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> v2{11, 10, 6, 4, 2, 0, 7, 2, 9};

int main()
{
    {
        auto &v = v1;
        auto result = boost::algorithm::is_sorted(v.begin(), v.end());
        assert(result);
    }
    {
        auto &v = v2;
        auto result = boost::algorithm::is_sorted(v.begin(), v.end());
        assert(!result);
    }
    {
        auto &v = v1;
        auto result = boost::algorithm::is_sorted(v.begin(), v.end(), std::less<int>());
        assert(result);
    }
    {
        auto &v = v2;
        auto result = boost::algorithm::is_sorted_until(v.begin(), v.end(), std::greater<int>());
        std::cout << "sorted until: " << result - v.begin() << "th element: " << *result << std::endl;
        for (auto &el : v)
            std::cout << el << ", ";
    }

    return 0;
}