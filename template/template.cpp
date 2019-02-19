#include <iostream>

using namespace std;

/*
  Because templates are compiled when required, this forces
  a restriction for multi-file projects: the implementation 
  (definition) of a template class or function must be in the 
  same file as its declaration. That means that we cannot 
  separate the interface in a separate header file, and that 
  we must include both interface and implementation in any file 
  that uses the templates.
*/

// Function templates

template <class theType>
theType getMax(theType a, theType b)
{
    return a > b ? a : b;
}

template <typename theType>
theType getMin(theType a, theType b)
{
    return a > b ? b : a;
}

// Class templates

template <class T>
class Para
{
    T values[2];

  public:
    Para(T first, T second)
    {
        values[0] = first;
        values[1] = second;
    }
    T getMax();
};

template <class T>
T Para<T>::getMax()
{
    return values[0] > values[1] ? values[0] : values[1];
}

int main()
{
    int x = 9, y = 5;
    cout << "getMax<int> (x,y) = " << getMax<int>(x, y) << endl;
    cout << "getMin<int> (x,y) = " << getMin<int>(x, y) << endl;

    Para<double> parka(3.14, 9.15);
    cout << "parka.getMax() = " << parka.getMax() << endl;
    Para<int> parka2(332, 123);
    cout << "parka2.getMax() = " << parka2.getMax() << endl;
    return 0;
}