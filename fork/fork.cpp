#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main()
{
    int x = 5;

    int pid = fork();

    if (pid)
    {
        x = 10;
        std::cout << "I'm a father, p_id : " << pid << " : " << x << std::endl;
    }
    else
    {
        std::cout << "I'm a child, p_id : " << pid << " : " << x << std::endl;
    }

    return 0;
}