/*
Program Number : 36
Name : Soma datta
Register Number : IMT2022077
Description : FIFO File Creation: Create a FIFO file using:
              a. mknod command
              b. mkfifo command
              c. Use strace command to determine which command (mknod or mkfifo) is more
                 efficient.
              d. mknod system call
              e. mkfifo library function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

// Using commands
// mkfifo 19_mkfifo_command --mode=0666
// mknod --mode=0666 19_mknod_command p

// Which is faster (better)?
// Answer: mkfifo calls mknod internally (see strace) => mknod is faster.
// Library functions may internally have mappings which may make them faster than system calls in some cases.

int main()
{
    char name[40];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int choice;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Using mknod system call...\n");

        if (mknod(name, __S_IFIFO | 0766, 0) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo system call...\n");

        if (mkfifo(name, 0744) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}