// Description : Write a program to open a file with read write mode, write 10 bytes,
// move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
// a. check the return value of lseek
// b. open the file with od and check the empty spaces in between the data.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("10.txt", O_CREAT | O_RDWR | O_EXCL);//O_CREAT is used to create the file if it does not exist. The O_RDWR flag is used to open the file in read-write mode. The O_EXCL flag is used to ensure that the file is created and not already present.
	
    if (fd == -1){
        perror("Error");
    }

    char t[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	write(fd, t, 10);
	int ret_l = lseek(fd, 10, SEEK_CUR);
	write(fd, t, 10);

	printf("%d\n", ret_l);

    close(fd);
	return 0;;
}

// use command od -c filename to see proper output
// cat filename to just see whether the value is correctly written or not