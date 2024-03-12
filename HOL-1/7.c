// Description : Write a program to copy file1 into file2 ($cp file1 file2).

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fsrc = open("4.txt", O_CREAT|O_RDONLY);
	char t[10000];
	read(fsrc, t, 10000);

	/* for(int i = 0; i < 1000; i++){ */
	/* 	printf("%c\n", t[i]); */
	/* } */

	int fdes = open("file1.txt", O_CREAT | O_WRONLY); //O_CREAT is used to create the file if it does not exist. The O_WRONLY flag is used to open the file in write only mode.
	int i = 0;
	while(t[i] != '\0'){
		write(fdes, &t[i], 1);
		i++;
	}
	printf("Done!\n");

    close(fsrc);
    close(fdes);
	
	return 0;
}
