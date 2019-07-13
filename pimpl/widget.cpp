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

Widget::~Widget() = default;

Widget::Widget(Widget &&rhs) = default;
Widget &Widget::operator=(Widget &&rhs) = default;
Widget::Widget(const Widget &rhs) : pImpl(std::make_unique<Impl>(*rhs.pImpl)) {}
Widget &Widget::operator=(const Widget &rhs)
{
    *pImpl = *rhs.pImpl;
    return *this;
}