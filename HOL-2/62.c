/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Signal Handling with sigaction: Write a program to ignore a SIGINT signal and then reset it
              to the default action using the sigaction system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction act;    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    return(0);
}