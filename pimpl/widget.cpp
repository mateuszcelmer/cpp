#include "widget.h"
#include <string>
#include <vector>

struct Widget::Impl
{
    std::string name;
    std::vector<double> data;
};

Widget::Widget()
    : pImpl(std::make_unique<Impl>()) {}