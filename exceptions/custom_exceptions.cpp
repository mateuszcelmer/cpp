#include <iostream>

/*
    void func1() noexcept;        // does not throw
    void func2() noexcept(true);  // does not throw
    void func3() throw();         // does not throw

    void func4() noexcept(false); // may throw
*/

class MyException : public std::exception
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