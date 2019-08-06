#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/partition_point.hpp>
#include <cassert>

using namespace boost;

std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    auto result = boost::algorithm::partition_point(v1.begin(),
                                                    v1.end(),
                                                    [](int i) { return i < 5; });

    assert(*result == 5);

    return 0;
}