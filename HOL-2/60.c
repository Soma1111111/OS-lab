/*
Program Number : 60
Name : Soma datta
Register Number : IMT2022077
Description : Ignoring and Resetting Signals: Write a program to ignore a SIGINT signal and then reset it
                to the default action using the signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Ignoring SIGINT signal\n");
    signal(SIGINT, SIG_IGN); //// CTRL + C is ignored.
    sleep(7);
    printf("\nDefault action of SIGINT signal\n");
    signal(SIGINT, SIG_DFL);
    // CTRL + C is no longer ignored.
    sleep(7);
    return 0;
}