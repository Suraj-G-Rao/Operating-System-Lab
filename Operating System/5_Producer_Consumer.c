#include <stdio.h>
#include <stdlib.h>
#define size 5 

int mutex = 1 , full = 0 ,empty = size , buffer[size]; 
void producer() {
    int item;
    if (mutex == 1 && empty != 0) {
        --mutex;
        ++full;
        --empty;
        printf("\nEnter the item to produce: ");    scanf("%d", &item);
        buffer[full - 1] = item;
        ++mutex;
    } else {
        printf("\nBuffer is full!");
    }
}
void consumer() {
    if (mutex == 1 && full != 0) {
        --mutex;
        ++empty;
        printf("\nConsumer consumes item %d", buffer[full - 1]);
        --full;
        ++mutex;
    } else {
        printf("\nBuffer is empty!");
    }
}

void displayBuffer() {
    printf("\nItems in Buffer:\n");
    for (int i = 0; i < full; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

int main() {
    int n, item;
    printf("\n1. Producer\n2. Consumer\n3. Display Buffer\n4. Exit");

    while (1) {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n) {
            case 1: if (full < size)   producer(item);
                    else             printf("\nBuffer is full!");
                    break;
            case 2: consumer();
                    break;
            case 3: displayBuffer();
                    break;
            case 4: printf("Exiting The Program .");
                    exit(0);
                    break;
            default:printf("Invalid choice!");
        }
    }

    return 0;
}
