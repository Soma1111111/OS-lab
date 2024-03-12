// Description : Find out the priority of your running program. Modify the priority with nice command.

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
	int pid = getpid();
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of the process: %d\n", priority);
    int n; 
    printf("To what value you want to increment(0-19)?\n");
    scanf("%d", &n);
    nice(n);
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of the process: %d\n", priority);
    return 0;
}