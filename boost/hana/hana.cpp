#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <cassert>
#include <boost/hana.hpp>

using namespace std;
using namespace boost;

int main()
{
    // tuple =================
    auto tuple = hana::make_tuple(1, 2.2f, "hello"s, 3.4, 'x');
    auto no_floats = hana ::remove_if(tuple, [](auto const &t) {
        return hana::traits::is_floating_point(hana::typeid_(t));
    });

    assert(no_floats == hana::make_tuple(1, "hello"s, 'x'));

    // map ===================
    struct a;
    struct b;
    struct c;
    auto map = hana::make_map(
        hana::make_pair(hana::type<a>{}, 1),
        hana::make_pair(hana::type<b>{}, 'x'),
        hana::make_pair(hana::type<c>{}, "hello"s));

    assert(map[hana::type<a>{}] == 1);
    assert(map[hana::type<b>{}] == 'x');
    assert(map[hana::type<c>{}] == "hello"s);

    return 0;
}