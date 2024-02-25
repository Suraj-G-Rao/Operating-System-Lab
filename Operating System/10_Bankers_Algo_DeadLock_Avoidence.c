/*

OUTPUT 1 : Request denied

Available resources: 3 3 2
Maximum demand matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter process id (0-4): 3
Enter the request for process 3:
1 1 0

Request denied



OUTPUT 2 : Request granted

Available resources: 5 4 3

Maximum demand matrix:
3 2 2
6 1 3
3 1 4
4 2 2
2 1 2

Allocation matrix:
1 0 0
5 1 1
2 1 1
0 0 2
0 0 2

Enter process id (0-4): 2
Enter the request for process 2:
1 0 2

Request granted


*/

#include <stdio.h>
#define P 5 
#define R 3 

int available[R];
int max[P][R];
int allocation[P][R];
int need[P][R];

void calculateNeed() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

int isSafe() {
    int work[R];
    int finish[P];

    for (int i = 0; i < R; i++)
        work[i] = available[i];
    for (int i = 0; i < P; i++)
        finish[i] = 0;

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0)
            return 0; 
    }
    return 1; 
}

int requestResources(int pid, int request[]) {
    for (int i = 0; i < R; i++) {
        if (request[i] > need[pid][i] || request[i] > available[i])
            return 0; 
    }

    for (int i = 0; i < R; i++) {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    if (!isSafe()) {
        for (int i = 0; i < R; i++) {
            available[i] += request[i];
            allocation[pid][i] -= request[i];
            need[pid][i] += request[i];
        }
        return 0; 
    }

    return 1;
}

void displayMatrix(int matrix[P][R], char *name) {
    printf("%s:\n", name);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter the available resources:\n");
    for (int i = 0; i < R; i++)
        scanf("%d", &available[i]);

    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &allocation[i][j]);

    calculateNeed();
    
    displayMatrix(max, "Maximum");
    displayMatrix(allocation, "Allocation");


    int pid;
    printf("Enter process id (0-%d): ", P - 1);
    scanf("%d", &pid);

    printf("Enter the request for process %d:\n", pid);
    int request[R];
    for (int i = 0; i < R; i++)
        scanf("%d", &request[i]);

    if (requestResources(pid, request))
        printf("Request granted\n");
    else
        printf("Request denied\n");

    return 0;
}
