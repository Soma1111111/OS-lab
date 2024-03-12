// Description : Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// Run: ./a.out <file_name>
int main(int argc, char *argv[]) {
    struct stat s;
    
    // Error handling.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    if (lstat(argv[1], &s) == -1) {
        perror("stat");
        return 2;
    }

    stat(argv[1], &s);

    printf("File type: ");
    // With normal stat, softlink was giving wrong answer

    // Use man inode to get info about all this
    // printf("%d\n", (s.st_mode & __S_IFMT)>>12);

    // Macros to test the mode of the file, in <sys/stat.h>
    // Mode contains the opening mode as well as the file info
    if (S_ISREG(s.st_mode)){
        printf("Regular file\n");
    }
    else if (S_ISDIR(s.st_mode)){
        printf("Directory\n");
    }
    else if (S_ISCHR(s.st_mode)){
        printf("Character Device File\n");
    }
    else if (S_ISBLK(s.st_mode)){
        printf("Block device file\n");
    }
    else if (S_ISFIFO(s.st_mode)){
        printf("FIFO file\n");
    }
    else if (S_ISLNK(s.st_mode)){
        printf("Softlink file\n");
    }
    else if (S_ISSOCK(s.st_mode)){
        printf("Socket file\n");
    }
    else{
        printf("Unknown?\n");
    }
    return(0);
}