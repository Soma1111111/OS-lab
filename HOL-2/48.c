/*
Program Number : 48
Name : soma datta
Register Number : IMT2022077
Description : Semaphore Creation and Initialization: Write a program to create a semaphore and
              initialize its value:
              a. Create a binary semaphore
              b. Create a counting semaphore
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun
{
    int val;                   // Value for SETVAL
    struct semid_ds *buf;      // Buffer for IPC_STAT, IPC_SET.
    unsigned short int *array; // Array for GETALL, SETALL.
};

// Creating binary semaphore and initializing value to the semaphore.
int main()
{
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);
    int choice;
    printf("Choose an option:\n1.) Binary Semaphore\n2.) Counting Semaphore\n=> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Creating binary semaphore\n");
        arg.val = 1; // Binary semaphore.
        break;
    case 2:
        printf("Creating counting semaphore\n");
        arg.val = 5; // Counting semaphore.
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    // Set value of semaphore.
    semctl(semid, 0, SETVAL, arg);
    return (0);
}