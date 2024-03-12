#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{   
    printf("Executes ls -Rl using execv");
    char* arr[] = {"/bin/ls", "/bin/ls", "-R", "-l", NULL};// The last argument is the environment variable.
    execv(arr[0], arr);
    return(0);
}