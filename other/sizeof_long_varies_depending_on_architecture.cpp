#include <iostream>

using namespace std;

int main()
{
    // compile with and compare:
    //   -> g++ -m32 sizeof_long_varies_depending_on_architecture.cpp -o sizeof_long_varies_depending_on_architecture && ./sizeof_long_varies_depending_on_architecture
    //   -> g++ -m64 sizeof_long_varies_depending_on_architecture.cpp -o sizeof_long_varies_depending_on_architecture && ./sizeof_long_varies_depending_on_architecture

    std::cout << "sizeof(int) : " << sizeof(int) << std::endl
              << "sizeof(long) : " << sizeof(long) << std::endl
              << "sizeof(void*) : " << sizeof(void*) << std::endl
              << "sizeof(size_t) : " << sizeof(size_t) << std::endl
              << "sizeof(long long) : " << sizeof(long long) << std::endl;
    return 0;
}