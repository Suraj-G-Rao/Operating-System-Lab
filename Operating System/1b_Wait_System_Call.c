#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    if(fork==0){
        printf("hello world\n");
    }
    else{
        printf("hi\n");
        wait(NULL);
        printf("hi hello\n");
    }
    printf("bye\n");

    return 0;
}