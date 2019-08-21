#include <iostream>

using namespace std;

class MyException : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "nowy wyjątek";
    }
} myexcept;

int main()
{
    try
    {
        throw myexcept;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}