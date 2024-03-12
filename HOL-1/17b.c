// Description : Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

int main(int argc,char*argv[]){
    int n;
    scanf("%d", &n);

    int fd = open("tickets.txt", O_CREAT|O_WRONLY, 0744);
    write(fd, &n, sizeof(int));
    printf("Write successsful\n");

    close(fd);
    return 0;
}
