/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Signal Handling with sigaction: Write separate programs using the sigaction system call to
                catch the following signals:
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig){
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main(){
    int choice = 0;
    printf("Enter 1 for sigsegv 2 for sigint ... so on\n");
    scanf("%d", &choice);
    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    ac.sa_handler = catch;
    if (choice == 1){
        sigaction(SIGSEGV, &ac, NULL); // Segmentation fault
        char *c = NULL;
        printf("%c", *c);
    }
    else if (choice == 2){
        sigaction(SIGINT, &ac, NULL);
        for (;;);
    }
    else if (choice == 3){
        sigaction(SIGFPE, &ac, NULL);
        int x, y;
        printf("Enter 0 to generate FPE: ");
        scanf("%d", &y);
        x = 1 / y;
        printf("%d\n", x);
    }
    return 0;
}