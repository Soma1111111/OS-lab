// Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>

int main(){
    fd_set fds;//fd_set is a datatype which represents file descriptor set.
    struct timeval t_val; //struct timeval is a datatype which represents time in seconds and microseconds.
    int retval;//retval is a variable which stores the return value of select.

    t_val.tv_sec = 10; //tv_sec is a variable which stores the time in seconds.
    t_val.tv_usec = 0; //tv_usec is a variable which stores the time in microseconds.

    FD_ZERO(&fds); //FD_ZERO is a macro which clears the file descriptor set.
    FD_SET(0, &fds); //FD_SET is a macro which adds the file descriptor to the file descriptor set.

    retval = select(1 ,&fds, NULL, NULL, &t_val); //select is a system call which monitors the file descriptor set for some activity.
    //select(nfds,reaadfds,writefds,exceptfds,timeout)
    //nfds is the highest-numbered file descriptor in any of the three sets, plus 1.
    //readfds is the set of file descriptors to be monitored for read operation.
    //writefds is the set of file descriptors to be monitored for write operation.
    //exceptfds is the set of file descriptors to be monitored for exceptions.
    //timeout is the maximum time for which select should wait before returning.
    if (retval == -1)
    {
        perror("Error");
    }
    else if(retval){
        printf("Data is available now.\n");
    }
    else{
        printf("No data available in ten seconds.\n");
    }
}