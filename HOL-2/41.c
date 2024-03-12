/*
Program Number : 41
Name : Soma datta
Register Number : IMT2022077
Description : Message Queue Creation: Write a program to create a message queue, and print the key
              and message queue ID.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Create a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666); // 0666 is the permission,msgset is the message queue id
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}