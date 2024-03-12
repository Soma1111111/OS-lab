/*
Program Number : 42
Name : Soma datta
Register Number : IMT2022077
Description : Message Queue Information: Write a program to print information about a message queue
              using msqid_ds and ipc_perm structures:
              a. Access permission
              b. UID, GID
              c. Time of last message sent and received
              d. Time of last change in the message queue
              e. Size of the queue
              f. Number of messages in the queue
              g. Maximum number of bytes allowed
              h. PID of the msgsnd and msgrcv
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    // printf("%d\n", msqid);
    
    struct msqid_ds st;
    msgctl(msqid, IPC_STAT, &st);

    printf("Access Permission - %o\n", st.msg_perm.mode);
    printf("Uid and gid of owner - %d %d\n", st.msg_perm.uid, st.msg_perm.gid);
    printf("Uid and gid of creator - %d %d\n", st.msg_perm.cuid, st.msg_perm.cgid);
    printf("Time of last message sent and received in queue - %ld %ld\n", st.msg_stime, st.msg_rtime);
    printf("Time of last change in the message queue - %ld\n", st.msg_ctime);
    printf("Size of the queue - %ld\n", st.__msg_cbytes);
    printf("Number of messages in queue - %ld\n", st.msg_qnum);
    printf("Maximum number of bytes allowed in queue - %ld\n", st.msg_qbytes);
    printf("Pid of the msgsnd and msgrcv - %d %d\n", st.msg_lspid, st.msg_lrpid);

    return (0);
}