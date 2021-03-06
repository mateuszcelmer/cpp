#include <iostream>
#include <boost/xpressive/xpressive.hpp>

using namespace boost::xpressive;

int main()
{
    std::string hello("hello world!");

    sregex rex = sregex::compile("(\\w+) (\\w+)!");
    // is same as
    sregex rex1 = (s1 = +_w) >> ' ' >> (s2 = +_w) >> '!';

    smatch what;

    if (regex_match(hello, what, rex))
    {
        std::cout << what[0] << '\n'; // whole match
        std::cout << what[1] << '\n'; // first capture
        std::cout << what[2] << '\n'; // second capture
    }

    if (regex_match(hello, what, rex1))
    {
        std::cout << what[0] << '\n'; // whole match
        std::cout << what[1] << '\n'; // first capture
        std::cout << what[2] << '\n'; // second capture
    }
    return 0;
}