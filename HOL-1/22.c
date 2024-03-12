// Description : Write a program to create a Zombie state of the running program.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int result = fork();
	if(result == 0){
		printf("Child: %d\n", getpid());
		sleep(25);
	}
	else{
		printf("Parent: %d\n", getpid());
		exit(0);
	}
	return 0;
}
