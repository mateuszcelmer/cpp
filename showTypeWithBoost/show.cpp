#include <iostream>
#include <boost/type_index.hpp>
template <typename T>
void f(const T &param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;

    // show T
    cout << "T =    "
         << type_id_with_cvr<T>().pretty_name()
         << '\n';

    // show param's type
    cout << "param = "
         << type_id_with_cvr<decltype(param)>().pretty_name()
         << '\n';
}

using namespace std;

int main()
{
    int x = 10;
    f(x);
    return 0;
}