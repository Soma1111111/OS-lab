#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Using execlp() to call ls -Rl.\n");
    execlp("ls","ls","-R","-l",NULL); // execlp() is used to call a program from the PATH environment variable.
    perror("execlp.");
    return 0;
}