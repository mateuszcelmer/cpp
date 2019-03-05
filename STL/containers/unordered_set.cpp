#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    // Best case: O(1)
    // Searching for an element in best case will be of complexity O(1)
    // - If there is only one element in the bucket of hash table
    //
    // Worst case O(n) in hashing will happen if Hash Function is not implemented properly i.e. its producing same hash code for many element.
    // complexity will be O(n)

    unordered_set<string> uset = {"one", "two", "three", "A", "b", "C"};

    uset.insert("two");
    uset.insert("one");

    for (auto i : uset)
        cout << i << endl;

    return 0;
}