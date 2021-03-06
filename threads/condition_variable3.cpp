// conditionVariables.cpp

#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

std::mutex mutex_;
std::condition_variable condVar;
bool dataReady{false};

void waitingForWork()
{
    std::cout << "Waiting for work..." << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, [] { return dataReady; });
    std::cout << "Running... " << std::endl;
    std::this_thread::sleep_for(4s);
    std::cout << "Work done!" << std::endl;
}

void setDataReady()
{
    std::this_thread::sleep_for(4s);
    {
        std::lock_guard<std::mutex> lck(mutex_);
        dataReady = true;
    }
    std::cout << "Data prepared" << std::endl;
    std::this_thread::sleep_for(1s);
    condVar.notify_all();
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