#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <cassert>

using namespace boost;

std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    auto result = boost::algorithm::none_of(v.begin(), v.end(), [](int i) {
        return i > 333;
    });

    assert(result);

    return 0;
}