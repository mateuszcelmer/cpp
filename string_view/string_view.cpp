#include <iostream>
#include <string_view>
#include <string>

using namespace std;

int main()
{
    // Regular strings
    std::string_view cppstr{"foo"};

    // Wide strings
    std::wstring_view wcstr_v{L"baz"};

    // Character arrays
    char array[3] = {'b', 'a', 'r'};
    std::string_view array_v(array, std::size(array));

    std::string str{"    trim me"};
    std::string_view v{str};
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));

    std::cout << str << std::endl;
    std::cout << v << std::endl;

    str[5] = '2';

    std::cout << str << std::endl;
    std::cout << v << std::endl;

    return 0;
}