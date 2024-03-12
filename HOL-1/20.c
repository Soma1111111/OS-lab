#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Before the fork\n");
    int i = fork();
    if(i == 0){
        printf("This is the child process.\n");
        printf("The PID of the child is %i\n",getpid());
    }
    else{
        printf("This is the parent process.\n");
        printf("The PID of the parent is %i\n",getpid());
    }
    return 0;    
}