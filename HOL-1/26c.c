#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{   
    char*envp[] = {NULL};
    printf("Using execle() to call ls -Rl.\n");
    execle("/bin/ls","/bin/ls","-R","-l",NULL,envp);// The last argument is the environment variable.
    perror("execle.");
    return 0;
}