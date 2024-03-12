/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Signal SIGSTOP Handling: Create two programs: the first program awaits the SIGSTOP
              signal, while the second program sends the signal using the kill system call. Determine
              whether the first program successfully catches the signal or not.
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    printf("pid (reciever): %d\n", getpid());
    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    // The handler will be ignored, as SIGSTOP and SIGKILL can not be caught.
    ac.sa_handler = catch;
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
    return (0);
}