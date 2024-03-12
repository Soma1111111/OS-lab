/*
Program Number : 31
Name : Soma datta
Register Number : IMT2022077
Description : Pipe Creation and Communication: Write a simple program to create a pipe, write to the
              pipe, read from the pipe, and display the content on the monitor.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);
	printf("pipe created with fd1: %d, fd2: %d\n", fd[0], fd[1]);
	char buf[10];
	write(fd[1], "Hello\n", sizeof("Hello\n"));
	read(fd[0], buf, sizeof(buf));
	printf("Buffer: %s", buf);
	getchar();
	return(0);
}