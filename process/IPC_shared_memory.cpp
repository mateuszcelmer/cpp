#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>

int main()
{
    auto pid = fork();

    if (pid)
    {
        // ftok to generate unique key
        key_t key = ftok("shmfile", 65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

        // shmat to attach to shared memory
        char *str = (char *)shmat(shmid, (void *)0, 0);

        strcpy(str,"ABCDFEGHIJK");

        printf("Data written in memory: %s\n", str);

        //detach from shared memory
        shmdt(str);
    }
    else
    {
        // ftok to generate unique key
        key_t key = ftok("shmfile", 65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

        // shmat to attach to shared memory
        char *str = (char *)shmat(shmid, (void *)0, 0);

        printf("Data read from memory: %s\n", str);

        //detach from shared memory
        shmdt(str);

        // destroy the shared memory
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}