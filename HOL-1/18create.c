#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include"18.h"


int main(int argc, char * argv[]){
	if(argc < 2){
		printf("run with ./a.out <filename> or ./18create <filename>\n");
		exit(0);
	}
	char* filename = argv[1];
	int fd = open(filename, O_WRONLY);
	printf("this program will store records of 3 students to a file\n");
	struct student students[3] = {{1, "abc"}, {2, "def"}, {3, "ghi"}};
	for(int i=0; i<3; i++){
		struct student s1 = students[i];
		write(fd, &s1, sizeof(struct student));
	}
	printf("data stored\n");
	return 0;
}
