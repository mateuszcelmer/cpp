#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool foo(std::string str)
{
    std::stack<char> sta;
    for (auto s : str)
    {
        if (s == '(')
        {
            sta.push(s);
        }
        if (s == ')')
        {
            if (sta.empty() || sta.top() != '(')
                return false;
            sta.pop();
        }
    }
    return sta.empty() ? true : false;
}

int main()
{
    std::cout << std::boolalpha << foo("()") << std::endl;
    std::cout << std::boolalpha << foo("(())") << std::endl;
    std::cout << std::boolalpha << foo(")") << std::endl;
    std::cout << std::boolalpha << foo("(()()))") << std::endl;
    std::cout << std::boolalpha << foo("(((((") << std::endl;
    return 0;
}