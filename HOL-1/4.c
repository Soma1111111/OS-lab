#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

/*
 Opening Existing File: Write a program to open an existing file in read-write mode. 
Experiment with the O_EXCL flag.
*/

int main() {
    char entered_Name[1000];
    printf("Enter the file name:");
    scanf("%s", entered_Name);
    int x = open(entered_Name, O_CREAT|O_EXCL|O_RDWR); //O_EXCL is used to ensure that the file is created and not already present.
    if(x > 2){
        printf("File opened with fd = %d\n", x);
    }
    else{
        printf("%d\n",x);
        perror("Error");
    }
}