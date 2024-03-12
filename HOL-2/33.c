/*
Program Number : 33
Name : Soma datta
Register Number : IMT2022077
Description : Two-Way Communication: Write a program to send and receive data between the parent
              and child processes using two-way communication.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd_pc[2];
	int fd_cp[2];
	pipe(fd_cp);
	pipe(fd_pc);
	if(!fork()){
		// Child to parent send.
		int c_value = 101;
		close(fd_cp[0]);
		write(fd_cp[1], &c_value, sizeof(int));
		// Parent to child receive.
		int c_val;
		close(fd_pc[1]);
		read(fd_pc[0], &c_val, sizeof(int));
		printf("Data from parent to child: %d\n", c_val);
	}
	else{
		// Child to parent receive.
		int p_value;
		close(fd_cp[1]);
		read(fd_cp[0], &p_value, sizeof(int));
		printf("Data from child to parent: %d\n", p_value);
		// Parent to child send.
		int p_val = 201;
		close(fd_pc[0]);
		write(fd_pc[1], &p_val, sizeof(int));
	}
	return 0;
}