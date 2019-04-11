#include <iostream>

using namespace std;

template <typename Container, typename Index>
decltype(auto)
authAndAccess(Container &&c, Index i)
{
    authenticateUser();
    return std::forward<Container>(c)[i];
}

int main()
{

    return 0;
}