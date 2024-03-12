/*
Program Number : 49-d
Name : soma datta
Register Number : IMT2022077
Description : Program to implement semaphore to protect any critical section.
              d. remove the created semaphore
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

// Remove a semaphore.
int main()
{
    union semun arg;
    key_t key = ftok(".", 'a');
    int semid = semget(key, 1, 0);
    semctl(semid, 0, IPC_RMID, arg);
    return (0);
}