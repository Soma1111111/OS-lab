#include <stdio.h>
#include <sched.h>
#include<stdlib.h>

int main()
{
    int maxp,minp;
    maxp = sched_get_priority_max(SCHED_FIFO);
    if(maxp==-1){
        perror("Error retrieving maximum real-time priority.");
        exit(1);
    }
    minp = sched_get_priority_min(SCHED_FIFO);
    if(minp==-1){
        perror("Error retrieving minimum real-time priority.");
        exit(1);
    }
    printf("Maximum real-time priority: %d\n",maxp);
    printf("Minimum real-time priority: %d\n",minp);

    return 0;
}
