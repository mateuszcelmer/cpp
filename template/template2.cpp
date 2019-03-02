#include <iostream>

using namespace std;

template <class T>
void print(T t)
{
    cout << typeid(T).name() << endl;
};

template <class T>
void print_full(T t)
{
    auto type = typeid(T).name();
    auto int_type = typeid(int).name();
    auto double_type = typeid(double).name();
    auto constchars_type = typeid(const char *).name();
    if (type == int_type)
        cout << "int" << endl;
    if (type == double_type)
        cout << "double" << endl;
    if (type == constchars_type)
        cout << "const char*" << endl;
};

int main()
{
    print(1);
    print(1.3);
    print("tekst");
    cout << "\n"
         << endl;
    print_full(1);
    print_full(1.3);
    print_full("tekst");
    return 0;
}