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
		printf("run with ./a.out <filename>\n");
		exit(0);
	}
	char* filename = argv[1];
	int fd = open(filename, O_RDONLY);
	printf("this is the read program, it will read records\n");
	printf("we will implement a read record lock here\n");
	printf("which record do you want to lock enter 0 1 or 2\n");
	int recno;
	scanf("%d", &recno);
	struct flock lock;
	memset(&lock, 0, sizeof(lock));//clearing the lock
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = recno * sizeof(struct student);
	lock.l_len = sizeof(struct student);
	printf("trying to put a read lock on record %d........\n", recno);
	fcntl(fd, F_SETLKW, &lock);//this will block until the lock is acquired
	printf("read lock is set on record %d\n", recno);
	lseek(fd, recno*sizeof(struct student), SEEK_SET);
	struct student s1;
	int ret = read(fd, &s1, sizeof(struct student));
	printf("your record is %d-- --%s\n", s1.rollno, s1.name);
	fflush(stdin);
	fflush(stdout);
	char buff[10];
	scanf("%s", buff);
	printf("going to unlock....\n");
	lock.l_type = F_UNLCK;
	printf("unlocked\n");
	fcntl(fd, F_SETLKW, &lock);
	close(fd);
	return 0;


}
