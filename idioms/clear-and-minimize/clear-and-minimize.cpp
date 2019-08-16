#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> v(123, 100);
    auto counter = 10;
    while (counter--)
        v.pop_back();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
 
    // idiom
    std::vector<int>().swap(v);
    
    std::cout << "---" << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    return 0;
}