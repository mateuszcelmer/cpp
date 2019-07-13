#include <memory>

class Widget
{
public:
    Widget();

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};