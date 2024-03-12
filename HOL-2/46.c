/*
Program Number : 46
Name : Soma datta
Register Number : IMT2022077
Description : Removing Message Queue: Write a program to remove the message queue.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Remove a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);
    if (msgctl(msqid, IPC_RMID, NULL) == -1){
        printf("Delete unsuccessful\n");
    }
    else{
        printf("Delete successful\n");
    }
    return (0);
}