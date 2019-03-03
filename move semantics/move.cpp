#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Base
{
    string name;

  public:
    auto get_name() { return name; }
    Base() {}
    Base(const string &name) : name(name) {}
};
class Derived : public Base
{
  public:
    Derived() {}
    Derived(const string &name) : Base(name) {}
};

int main()
{
    vector<unique_ptr<Base>> v1, v2;
    Derived some("one");
    v1.push_back(unique_ptr<Derived>(&some));
    v2.push_back(make_unique<Derived>("two"));

    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    std::swap(v1, v2);

    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    std::swap(v1, v2);

    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    return 0;
}