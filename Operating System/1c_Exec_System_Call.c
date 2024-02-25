#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    int i=0;
    long sum;
    int pid;
    int status,ret;
    printf("parent : hi\n");
    pid=fork();
    if(pid==0){
        execl("child",NULL);
        printf("parent waiting for child\n");
    }
    if(ret==waitpid(pid,&status,0)==-1){
        printf("parent:error\n");
    }
    if(ret==pid){
        printf("parent:child process waited for\n");
    }
    return 0;
}