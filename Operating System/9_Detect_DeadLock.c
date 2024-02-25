/*
Enter the number of processes: 3
Enter the number of resources: 3
Enter allocation matrix:
0 1 0
1 1 0
0 0 1
Enter maximum demand matrix:
1 0 0
0 0 1
0 1 0
Enter available resources vector:
0 0 0
System is in deadlock.


Enter the number of processes: 3
Enter the number of resources: 3
Enter allocation matrix:
0 1 0
1 1 0
0 0 1
Enter maximum demand matrix:
1 0 0
0 0 1
0 0 0
Enter available resources vector:
0 0 0
System is in a safe state. Safe sequence: 2 1 0 

*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

int main() {
    int processes, resources, i, j ,allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max_demand[MAX_PROCESSES][MAX_RESOURCES] ,available[MAX_RESOURCES],work[MAX_RESOURCES];
    bool finished[MAX_PROCESSES],safe_state = true;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++)   scanf("%d", &allocation[i][j]);
    }

    printf("Enter maximum demand matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++)   scanf("%d", &max_demand[i][j]);
    }

    printf("Enter available resources vector:\n");
    for (j = 0; j < resources; j++)    scanf("%d", &available[j]);
    
    for (i = 0; i < processes; i++)   finished[i] = false;
    for (j = 0; j < resources; j++)    work[j] = available[j];
    

    int safe_sequence[MAX_PROCESSES];
    int count = 0;
    while (count < processes) {
        bool found = false;
        for (i = 0; i < processes; i++) {
            if (!finished[i]) {
                bool can_allocate = true;
                for (j = 0; j < resources; j++) {
                    if (max_demand[i][j] - allocation[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finished[i] = true;
                    safe_sequence[count] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            safe_state = false;
            break;
        }
    }

    if (safe_state) {
        printf("System is in a safe state. Safe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
    } else {
        printf("System is in deadlock.\n");
    }

    return 0;
}