// Description : Write a program to find out the opening mode of a file. Use fcntl.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("test_12.txt", O_CREAT|O_RDWR);
	int res = fcntl(fd, F_GETFL);//F_GETFL is used to get the file status flags and file access modes.
	printf("fcntl returns:\t%d\n", res);

	if(res < 0){
		printf("Error...\n");
	}
	else if((res & O_ACCMODE) == O_RDONLY){//O_ACCMODE is used to mask the file access modes.
		printf("File opened in O_RDONLY mode.\n");
	}
	else if((res & O_ACCMODE) == O_RDWR){//to get the mode of the file, we use the bitwise AND operation with O_ACCMODE.
		printf("File opened in O_RDWR mode.\n");
	}
	else if((res & O_ACCMODE) == O_WRONLY){
		printf("File opened in O_WRONLY mode.\n");
	}
	else{
		printf("File opened in mode other than O_RDWR, O_RDONLY, O_WRONLY modes.\n");
	}

	return 0;
}
