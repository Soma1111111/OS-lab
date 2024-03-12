/*
Program Number : 59
Name : Soma datta
Register Number : IMT2022077
Description : Program using signal system call to catch the following signals.
                a. SIGSEGV(signal segmentation violation)
                b. SIGINT (termination of the program/CTRL+C)
                c. SIGFPE (floating point exception)
                d. SIGALRM (use alarm system call) (time interval specified in a call to the alarm or alarmd function expires)
                e. SIGALRM (use setitimer system call) (time interval specified in a call to the alarm or alarmd function expires)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

void handler1()
{
    printf("Segmentation fault caught\n");
    exit(0);
}

void handler2(){
    printf("\nSIGINT received\n");
    exit(0);
}

void handler3()
{
    printf("Floating point error caught\n");
    exit(0);
}

void handler4(int signum)
{
    printf("Signal received (alarm related)\n");
    // exit(0);
}

int main(){
    int choice;
    while(1){
        printf("Choose an option:\n1.) SIGSEGV\n2.) SIGINT\n3.) SIGFPE\n4.) SIGALRM (alarm system call)\n5.) SIGALRM (setitimer system call)\n6.) SIGVTALRM (setitimer system call)\n7.) SIGPROF (setitimer system call)\n=> ");
        scanf("%d", &choice);
        int x,y;
        struct itimerval it;
        // Set timer value.
        it.it_value.tv_sec = 2;
        it.it_value.tv_usec = 0;

        // Reset value on timer after completion.
        it.it_interval.tv_sec = 2;
        it.it_interval.tv_usec = 0;
        
        switch(choice){
            case 1:
                signal(SIGSEGV, handler1);
                char *str;
                str = NULL;
                printf("%c\n", *(str + 1));
                printf("No segmentation fault\n");
                break;
            case 2:
                signal(SIGINT, handler2);
                printf("Waiting 5 seconds for SIGINT\n");
                sleep(5);
                break;
            case 3:
                x = 3;
                y = 0;
                printf("%d\n", x / y);
                signal(SIGFPE, handler3);
                printf("No error\n");
                break;
            case 4:
                signal(SIGALRM, handler4);
                while (1)
                {
                    printf("Alarm set\n");
                    alarm(2);
                    sleep(3);
                }
                break;
            case 5:
                signal(SIGALRM, handler4);
                setitimer(ITIMER_REAL, &it, NULL); // ITIMER_REAL is used for real time interval
                while (1)
                {
                }
                break;
            case 6:
                signal(SIGVTALRM, handler4);
                setitimer(ITIMER_REAL, &it, NULL); // ITIMER_REAL is used for real time interval
                while (1)
                {
                }
                break;
            case 7:
                signal(SIGPROF, handler4);
                setitimer(ITIMER_PROF, &it, NULL);
                while (1)
                {
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

//while SIGALRM is sent after a certain amount of real time has passed, 
//SIGPROF is sent after a certain amount of time has been spent running the process and running system code on behalf of the process.
