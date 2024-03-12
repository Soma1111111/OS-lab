/*
Process States: Develop a program to initiate a process in distinct states: 
a. running
b. sleeping
c. stopped
Confirm the current state of the process using the relevant commands.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    printf("select 1 out of 3 options: \n1. Running\n2. Sleeping\n3. Stopped\n");
    printf("print any other to exit\n");
    while(1){
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
                // Running state
                printf("Process is in the running state.\n");
        }
        else if(choice ==2){ 
                printf("Process will sleep for 15 seconds...\n");
                sleep(15);
                printf("Process woke up from sleep.\n");
        }
        else if(choice == 3){
                // Stopped state
                printf("Process will be stopped\n");
                raise(SIGSTOP);  // Send SIGSTOP signal to itself
                printf("Process resumed from stopped state.\n"); // Won't happen
        }
        else{
            break;
        }
    }
    return 0;
}