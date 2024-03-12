// Description : Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	printf("In 25.c file...\n");
	execv("./tester", argv);
	/* printf("End of 26.c file...\n"); */
	return 0;
}
