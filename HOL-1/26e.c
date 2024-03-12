#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{   
    char *args[] = {"ls","-R","-l",NULL};
    printf("Using execvp() to call ls -Rl.\n");
    execvp("ls", args); 
    perror("execvp.");
    return 0;
}