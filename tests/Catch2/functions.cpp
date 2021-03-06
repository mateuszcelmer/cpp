#include "functions.h"

double sum(double a, double b)
{
    return a + b;
}

long factorial(long n)
{
    return n > 1 ? factorial(n - 1) * n : n;
}

std::vector<int> amplify(std::vector<int> v, int i)
{
    auto ff = factorial(i);
    auto ss = sum(i, ff);
    std::cout << "ss = " << ss << std::endl;
    std::vector<int> nowy;
    for (auto it = v.begin(); it != v.end(); ++it)
        nowy.push_back((*it) * i);
    return nowy;
}