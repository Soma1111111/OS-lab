/*
Program Number : 39
Name : Soma datta
Register Number : IMT2022077
Description : Waiting for Data in FIFO: Write a program to wait for data to be written into a FIFO within
              10 seconds, utilizing the select system call with the FIFO.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

// Use 39_write.c as writer.
int main()
{
    fd_set rfds; // read file descriptor set
    struct timeval tv;
    int retval;
    int fd;
    printf("10 second timer will start when writer is available.\n");
    fd = open("myFifo", O_RDONLY, 0666);
    /* Watch fd of myFifo to see when it is ready for reading. */
    printf("Starting 10 second timer.\n");
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    /* Wait up to ten seconds. */
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    // Waiting
    // printf("Waiting...\n");
    retval = select(fd + 1, &rfds, NULL, NULL, &tv);
    // printf("Waiting Over\n");
    if (retval == -1){
        perror("select()");
    }
    else if (retval){
        printf("Data is available now.\n");
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
    }
    else{
        printf("No data within ten seconds.\n");
    }
    close(fd);
    exit(EXIT_SUCCESS);
    return (0);
}