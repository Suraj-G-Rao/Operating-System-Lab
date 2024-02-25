/*
Page Reference String : 1 2 3 4 1 2 5 1 2 3 4 5 

Page Fault      Frames: 1 -1 -1 
Page Fault      Frames: 1 2 -1 
Page Fault      Frames: 1 2 3 
Page Fault      Frames: 4 2 3 
Page Fault      Frames: 4 1 3 
Page Fault      Frames: 4 1 2 
Page Fault      Frames: 5 1 2 
Page Hit        Frames: 5 1 2 
Page Hit        Frames: 5 1 2 
Page Fault      Frames: 3 1 2 
Page Fault      Frames: 3 4 2 
Page Fault      Frames: 3 4 5 

Total Page Faults: 10
*/
#include <stdio.h>
#include <stdbool.h>

void lru(int pages[], int n, int capacity) {
    int frames[capacity]; 
    int pageLastUsed[capacity]; 
    int pageFaults = 0; 

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        pageLastUsed[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        bool pageFound = false; 

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == currentPage) {
                pageFound = true;
                pageLastUsed[j] = i; 
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = 0;
            int minLastUsed = pageLastUsed[0];
            for (int j = 1; j < capacity; j++) {
                if (pageLastUsed[j] < minLastUsed) {
                    minLastUsed = pageLastUsed[j];
                    lruIndex = j;
                }
            }
            frames[lruIndex] = currentPage;
            pageLastUsed[lruIndex] = i; 
            pageFaults++;
            printf("Page Fault   \t");
        } else {
            printf("Page Hit     \t");
        }

        printf("Frames: ");
        for (int j = 0; j < capacity; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int num,frames;
    
    printf("Enter the number of pages : ");
    scanf("%d", &num);
    int pages[num];
    printf("Enter The Reference String : ");
    for (int i = 0; i < num; i++)    scanf("%d", &pages[i]);
    
    printf("Enter the number of frames : ");
    scanf("%d", &frames);

    printf("Page Reference String : ");
    for (int i = 0; i < num; i++)    printf("%d ", pages[i]);
    printf("\n\n");

    lru(pages, num, frames);

    return 0;
}
