#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Using execl() to call ls -Rl.\n");
    execl("/bin/ls","/bin/ls","-R","-l",NULL);//execl() is used to execute a file which is present in the path specified in the first argument.
    perror("execl.");
    return 0;
}