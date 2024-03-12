#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
File Descriptor Duplication and Appending: Write a program to open a file, duplicate the 
file descriptor, append the file with both descriptors, and verify whether the file is updated 
correctly. 
a. Use dup
b. Use dup2
c. Use fcntl
*/

int main()
{
    char buffer_1[1000];
    char buffer_2[1000];
    char buffer_3[1000];
    char buffer_4[1000];
    int fd_1 = open("xyz2.txt", O_CREAT | O_WRONLY | O_APPEND);
    int fd_2 = dup(fd_1);
    write(fd_1, "Hello How are you\n", 19);
    write(fd_2, "Did you have lunch?\n", 21);
    dup2(fd_1, 4);//dup2 is used to duplicate the file descriptor. It takes two arguments, the first is the file descriptor to be duplicated and the second is the file descriptor to be duplicated to.
    write(4, "Yes sir, thanks for asking\n", 28);//The file descriptor 4 is now a duplicate of the file descriptor 1. So, the file is appended with the given string.
    //write the string in the file descriptor 4
    int fd_3 = fcntl(fd_1, F_DUPFD, 3);//fcntl is used to duplicate the file descriptor. It takes three arguments, the first is the file descriptor to be duplicated, the second is the command, and the third is the file descriptor to be duplicated to.
    write(fd_3, "Two bowls of porridge\n", 23);
    close(fd_1);
    close(fd_2);
    close(4);
    close(fd_3);
}
