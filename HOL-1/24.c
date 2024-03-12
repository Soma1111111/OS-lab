// Description : Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void wait_example(){
    int i, stat;
    pid_t pid[3];//pid_t is a signed integer type which is capable of representing a process ID.
    for (i = 0; i < 3; i++){
        pid[i] = fork();
        if (pid[i] == 0){
            printf("child %d, %d\n", i, getpid());
            if(i == 1){
                sleep(10);
            }
            else{
                sleep(2);
            }
            exit(100 + i);
        }
    }
 
    // Using waitpid() and printing exit status
    // of children.
    // wait for child 1 (second child out of 0, 1, 2).
    pid_t cpid_to_wait = waitpid(pid[1], &stat, 0);//waitpid() is used to make the parent process wait for a particular child process to complete.
    printf("Child %d terminated with status: %d\n", cpid_to_wait, WEXITSTATUS(stat)); //WEXITSTATUS returns the exit status of the child.
}

int main(){
    wait_example();
    return 0;
}
