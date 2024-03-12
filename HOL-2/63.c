/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Creating an Orphan Process: Write a program to create an orphan process. Utilize the kill
              system call to send a SIGKILL signal from the child process to the parent process.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    // Child Process
    if (!fork())
    {
        sleep(5);
        printf("Child is waiting, pid: %d\n", getpid());
        kill(getppid(), 9); // Sending SIGKILL signal to parent process
        printf("Parent process killed\n");
        sleep(10);
    }
    else
    {
        printf("Parent Process, pid: %d\n", getpid());
        sleep(15);
    }

    return 0;
}