#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

void foo(promise<int> *prom)
{
    this_thread::sleep_for(chrono::seconds(5));
    prom->set_value(123);
}

int main()
{
    cout << "START" << endl;

    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();

    // start the thread
    thread t1(foo, &promiseObj);

    // wait for the object to be assigned
    auto val = futureObj.get();

    cout << "promise object assigned!" << endl;
    cout << "val = " << val << endl;

    t1.join();
    return 0;
}