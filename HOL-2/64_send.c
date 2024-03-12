/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Signal SIGSTOP Handling: Create two programs: the first program awaits the SIGSTOP
              signal, while the second program sends the signal using the kill system call. Determine
              whether the first program successfully catches the signal or not.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter pid of process to stop\n");
    scanf("%d", &pid);
    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);
    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}  