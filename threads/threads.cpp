#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

using namespace std;

/*

Ways to lock:
    std::mutex TheLock;

    1)
    std::lock_guard<std::mutex> lock(TheLock);  // you should not call std::mutex::unlock() directly in this case, 
                                                // as std::lock_guard destructor would call std::mutex::unlock() again and that would lead to UB
    2)                                          
    std::unique_lock<mutex> lck(TheLock);       // is not lightweight as std::lock_guard but allows you to call unlock() on it
    ...
    lck.unlock();

    3)
    TheLock.lock();     // in some situations it is not safe, e.g. exceptions
    TheLock.unlock();

*/

int GetRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

std::mutex theLock;

void ExecuteThread(int id)
{
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime =
        std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);

    theLock.lock();
    cout << "Thread " << id << " Sleep Time : "
         << ctime(&sleepTime) << endl;
    theLock.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);

    theLock.lock();
    cout << "Thread " << id << " Awake Time : "
         << ctime(&sleepTime) << endl;
    theLock.unlock();
}

int main()
{
    std::thread th1(ExecuteThread, 1);
    std::thread th2(ExecuteThread, 2);
    th1.join();
    th2.join();
    return 0;
}