#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{   
    int ret1 =  creat("source3",O_CREAT|0777);//The return value ret1 will contain the file descriptor for "source3" or -1 if an error occurs.
    //The O_CREAT flag is used to create the file if it does not exist. The 0777 is the permission for the file.
	int ret2 = creat("source4",O_CREAT|0777);
    int ret3 = creat("source5",O_RDWR|0777);
    printf("%d %d %d\n",ret1,ret2,ret3);
    //Random file descriptors
	return 0;
}
