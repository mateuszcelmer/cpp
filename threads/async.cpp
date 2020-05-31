#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

string foo(string in)
{
    this_thread::sleep_for(chrono::seconds(5));
    return "From foo"s + in + " 5 seconds";
}

string bar(string in)
{
    this_thread::sleep_for(chrono::seconds(5));
    return "From bar"s + in + " 5 seconds";
}



int main()
{
    cout << "START!\n"
         << endl;

    auto start = chrono::system_clock::now();

    auto fun = [](){return 123;};
    auto ret = std::async(std::launch::async, fun);
    cout << ret.get() << endl; 

    future<string> resultFromFoo = async(launch::async, foo, "YES");
    auto resultFromBar = async(launch::async, bar, "SECOND");

    auto result = resultFromFoo.get();
    cout << result << endl;
    result = resultFromBar.get();
    cout << result << endl;

    auto end = chrono::system_clock::now();
    auto dura = chrono::duration_cast<chrono::seconds>(end - start).count();

    cout << "\nFINISH!\ntotal time: " << dura << endl;
    return 0;
}