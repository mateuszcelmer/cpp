// WARNING!
// Using atomic here is not a perfect solution, here's why:
// https://www.modernescpp.com/index.php/c-core-guidelines-be-aware-of-the-traps-of-condition-variables

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex mtx;
std::condition_variable condv;
std::atomic<bool> dataReady{false};

void waitingForWork()
{
    std::cout << "Waiting" << std::endl;
    std::unique_lock<std::mutex> lck(mtx);
    condv.wait(lck, []() { return dataReady.load(); });
    std::cout << "Running" << std::endl;
}

void setDataReady()
{
    dataReady = true;
    std::cout << "Data prepared" << std::endl;
    condv.notify_one();
}

int main()
{
    std::cout << std::endl;

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << std::endl;
}

/*
The program is quite straightforward compared to the first version because dataReady has not to be protected by a mutex. Once more, the program has a race condition which can cause a deadlock. Why? dataReady is atomic! Right, but the wait expression (condVar.wait(lck, []{ return dataReady.load(); });) in line (1) is way more complicated then it seems.

The wait expression is equivalent to the following four lines:

std::unique_lock<std::mutex> lck(mutex_);
while ( ![]{ return dataReady.load(); }() {
    // time window (1)
    condVar.wait(lck);
}
Even if you make dataReady an atomic, it must be modified under the mutex; if not the modification to the waiting thread may be published, but not correctly synchronised. This race condition may cause a deadlock. What does that mean: published, but not correctly synchronised. Let's have a closer look at the previous code snippet and assume that data is atomic and is not protected by the mutex mutex_.

Let me assume the notification is sent while the condition variable condVar is in the wait expression but not in the waiting state. This means the execution of the thread is in the source snippet in the line with the comment time window ( line 1). The result is that the notification is lost. Afterwards, the thread goes back in the waiting state and presumably sleeps forever. 

This wouldn't have happened if dataReady had been protected by a mutex. Because of the synchronisation with the mutex, the notification would only be sent if the condition variable and, therefore, the receiver thread is in the waiting state. 

What a scary story? Is there no possibility to make the initial program conditionVariables.cpp easier? No, not with a condition variable, but you can use a promise and future pair the make the job done. For the details, read the post Thread Synchronisation with Condition Variables or Tasks.
 */