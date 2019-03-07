#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
  private:
    static weak_ptr<Singleton> singleton;
    Singleton(){};
    Singleton(const Singleton &){};

  public:
    int data = 0;
    static shared_ptr<Singleton> getInstance();
    ~Singleton(){};
};

weak_ptr<Singleton> Singleton::singleton = shared_ptr<Singleton>();

shared_ptr<Singleton> Singleton::getInstance()
{
    shared_ptr<Singleton> _instance = singleton.lock();
    if (!_instance)
    {
        _instance.reset(new Singleton());
        singleton = _instance;
    }
    return _instance;
};

int main()
{
    auto singl = Singleton::getInstance();
    singl->data = 123;
    cout << singl->data << endl;

    auto singl2 = Singleton::getInstance();
    singl2->data = 321;

    cout << singl2->data << endl;
    cout << singl->data << endl;

    return 0;
}