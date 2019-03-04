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

string GetTime()
{
    auto nowTime = chrono::system_clock::now();
    time_t sleepTime =
        chrono::system_clock::to_time_t(nowTime);
    return ctime(&sleepTime);
}

std::mutex theLock;
vector<uint> primeVect;

void FindPrimes(uint start,
                uint end)
{
    for (size_t x = start; x <= end; x += 2)
    {
        for (size_t y = 2; y < end; y++)
        {
            if (x % y == 0)
            {
                break;
            }
            else if (y + 1 == x)
            {
                theLock.lock();
                primeVect.push_back(x);
                theLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(uint start,
                           uint end, uint numThreads)
{
    vector<thread> threadVect;
    uint threadSpread = end / numThreads;
    uint newEnd = start + threadSpread - 1;
    for (uint x = 0; x < numThreads; x++)
    {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    for (auto &&t : threadVect)
    {
        t.join();
    }
}

int main()
{
    // without threads

    int startTime = clock();
    FindPrimes(1, 100000);
    for (auto &&i : primeVect)
        cout << i << endl;
    int endTime = clock();
    cout << "czas: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;

    // with threads

    primeVect.clear();

    startTime = clock();
    FindPrimesWithThreads(1, 100000, 7);
    endTime = clock();
    for (auto &&i : primeVect)
        cout << i << endl;

    cout << "czas: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;

    return 0;
}