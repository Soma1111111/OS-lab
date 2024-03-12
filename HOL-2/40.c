/*
Program Number : 39
Name : Soma datta
Register Number : IMT2022077
Description : Process File Limit and Pipe Size: Write a program to print the maximum number of files that
              can be opened within a process and the size of a pipe (circular buffer).
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("Pipe_buf = %ld\nOpen_max = %ld\n", PIPE_BUF, OPEN_MAX);
    return(0);
}