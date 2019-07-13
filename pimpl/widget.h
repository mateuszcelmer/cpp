#ifndef __WIDGET_H_
#define __WIDGET_H_

#include <memory>

class Widget
{
public:
    Widget();
    ~Widget();
    Widget(Widget &&rhs);
    Widget &operator=(Widget &&rhs);
    Widget(const Widget &rhs);
    Widget &operator=(const Widget &rhs);

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // !__WIDGET_H_
