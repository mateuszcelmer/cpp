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
    vector<unique_ptr<Base>> v1, v2, v2a;
    v1.push_back(make_unique<Derived>("one"));
    v2.push_back(make_unique<Derived>("two"));

    cout << "1." << endl;
    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    std::swap(v1, v2);

    cout << "2." << endl;
    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    std::swap(v1, v2);

    cout << "3." << endl;
    cout << v1[0]->get_name() << endl;
    cout << v2[0]->get_name() << endl;

    v2a = move(v1);

    cout << "4." << endl;
    cout << "v2a[0]->get_name() " << v2a[0]->get_name() << endl;
    cout << "v1.size() " << v1.size() << endl;
    cout << "v2a.size() " << v2a.size() << endl;

    //================================

    vector<unique_ptr<Base>> v3, v4;
    v3.push_back(make_unique<Derived>());
    // v4 = v3; // compile time error - This is not a copyable type.
    v4 = move(v3);

    return 0;
}