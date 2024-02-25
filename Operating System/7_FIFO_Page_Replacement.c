/*
Page Reference String : 1 2 3 4 1 2 5 1 2 3 4 5 

Frames: -1 -1 -1        Page Fault   
Frames: 1 -1 -1         Page Fault   
Frames: 1 2 -1          Page Fault   
Frames: 1 2 3           Page Fault   
Frames: 4 2 3           Page Fault   
Frames: 4 1 3           Page Fault   
Frames: 4 1 2           Page Fault   
Frames: 5 1 2           Page Hit     
Frames: 5 1 2           Page Hit     
Frames: 5 1 2           Page Fault   
Frames: 5 3 2           Page Fault   
Frames: 5 3 4           Page Hit  

Total Page Faults: 9
*/
#include <stdio.h>
void fifo(int pages[], int n, int capacity) {
    int frames[capacity]; 
    int frameIndex = 0; 
    int pageFaults = 0; 
    for (int i = 0; i < capacity; i++)    frames[i] = -1;


    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0; 

        
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }
        if (!pageFound) {
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % capacity;
            pageFaults++;
            printf("Page Fault   \t");
        } else {
            printf("Page Hit     \t");
        }

        printf("Frames: ");
        for (int j = 0; j < capacity; j++)   printf("%d ", frames[j]);


        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n,frames;
    printf("Enter the number of pages : ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter The Reference String : ");
    for (int i = 0; i < n; i++)    scanf("%d", &pages[i]);
    
    printf("Enter the number of frames : ");
    scanf("%d", &frames); 

    printf("Page Reference String : ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);
    printf("\n\n");

    fifo(pages, n, frames);

    return 0;
}