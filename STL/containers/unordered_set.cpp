#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    // Best case: O(1)
    // Searching for an element in best case will be of complexity O(1)
    // - If there is only one element in the bucket of hash table
    //
    // Worst case O(n) in hashing will happen if Hash Function is not implemented properly
    // i.e. its producing same hash code for many element.
    // complexity will be O(n)

    std::unordered_set<string> uset{"one", "two", "three", "A", "b", "C"};

    uset.insert("two");
    uset.insert("one");

    for (auto &i : uset)
        std::cout << i << ", ";

    // set

    std::cout << "" << std::endl;
    std::set<string> set{"a", "b", "c", "d", "e", "f", "g", "h", "z", "x", "w", "e", "r", "t", "o", "m", "p", "n", "i"};

    for (auto &s : set)
    {
        std::cout << s << ", ";
    }
    std::cout << std::endl;

    return 0;
}