// Description : Write a program to perform mandatory locking.
                // a. Implement write lock
                // b. Implement read lock

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
    int fd = open(argv[1], O_RDWR);
    printf("Press 1 for read lock, press 2 for write lock\n");
    int val;
    scanf("%d", &val);

    if(val == 1){
        //read lock
        char name[100];
        printf("Enter file name to lock: \n");
        scanf("%s", name);

        struct flock lock;//flock is a structure that is used to lock a file
        lock.l_start = 0;//l_start is the starting offset for the lock
        lock.l_len = 0;//l_len is the number of bytes to lock
        lock.l_whence = SEEK_SET;//l_whence is the starting point for the lock
        lock.l_type = F_RDLCK;//l_type is the type of lock

        int fd;
        fd = open(name, O_RDONLY, 0744);//O_RDONLY is used to open the file in read only mode,0744 is the permission
        printf("Before read lock\n");

        int res = fcntl(fd, F_SETLKW, &lock);//F_SETLKW is used to set the lock and wait if the lock is already set
        //fcntl is used to perform various operations on file descriptors
        if (res < 0){
            printf("Lock unsuccessful\n");
            return 0;
        }

        printf("Locked\n");

        getchar();
        getchar();
        printf("Unlocking\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &lock);  
        printf("Unlock successful");

        close(fd);
    }
    else if(val == 2){
        //write lock

        char name[100];
        printf("Enter file name to lock: \n");
        scanf("%s", name);

        struct flock lock;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_whence = SEEK_SET;
        lock.l_type = F_WRLCK;

        int fd = open(name, O_WRONLY, 0744);
        printf("Before write lock\n");
        
        int res = fcntl(fd, F_SETLKW, &lock);
        if (res < 0){
            printf("Lock unsuccessful\n");
            return 0;
        }
        
        printf("Locked\n");
        getchar();
        getchar();
        printf("Unlocking\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &lock);  
        printf("Unlock successful");

        close(fd);
    }
    else{
        printf("Invalid choice\n");
    }
    return 0;
}
