/*
Program Number : 50
Name : soma datta
Register Number : IMT2022077
Description :Deadlock: Develop a program that intentionally induces a deadlock scenario using
             semaphores.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int main(){
    sem_t s1, s2;
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    sem_wait(&s1);
    sem_wait(&s2);
    printf("This will never be printed\n");
    sem_post(&s1);
    sem_post(&s2);
    return 0;
}