#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    fork();
    printf("hello\n");

    return 0;
}
