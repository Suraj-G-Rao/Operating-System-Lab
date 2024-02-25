/*
Enter The No. of Blocks : 2
Enter The size of each block1 :150 350
Enter The No. of Process : 4
Enter The size of each Process :300 25 125 50
MEMORY ALLOCATION FOR VARIABLE SIZE PARTITIONING : 
First Fit:

Process No.     Process Size    Block no.
 1              300             2
 2              25              1
 3              125             Not Allocated
 4              50              Not Allocated
INTERNAL FRAGMENTATION : 175 KB
EXTERNAL FRAGMENTATION : 175 KB

Best Fit:

Process No.     Process Size    Block no.
 1              300             2
 2              25              1
 3              125             Not Allocated
 4              50              Not Allocated
INTERNAL FRAGMENTATION : 175 KB
EXTERNAL FRAGMENTATION : 175 KB

Worst Fit:

Process No.     Process Size    Block no.
 1              300             2
 2              25              1
 3              125             Not Allocated
 4              50              Not Allocated
INTERNAL FRAGMENTATION : 175 KB
EXTERNAL FRAGMENTATION : 175 KB

*/

#include <stdio.h>
#include <string.h>

void print_memory(int allocation[], int process[], int n)
{
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void First_Fit(int block[], int m, int process[], int n)
{
    int block1[m],IF=0,EF=0,i,j;
    for(int i=0; i<m ;i++)  block1[i]=block[i];
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (block1[j] >= process[i] && block1[j]==block[j])
            {
                allocation[i] = j;
                block1[j] -= process[i];
                break;
            }
        }
        if(allocation[i]==-1)  EF+=process[i];
        else if(process[i]<block[j]) IF+=block[j]-process[i];
    }
    print_memory(allocation, process, n);
    printf("INTERNAL FRAGMENTATION : %d KB\n",IF);
    printf("EXTERNAL FRAGMENTATION : %d KB\n",EF);
}

void Best_Fit(int block[], int m, int process[], int n)
{
    int block1[m],EF=0,IF=0,i,j;
    for(int i=0; i<m ;i++)  block1[i]=block[i];
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block1[j] >= process[i]  && block1[j]==block[j])
            {
                if (bestIdx == -1 || block1[bestIdx] > block1[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            block1[bestIdx] -= process[i]; 
        }
        if(allocation[i]==-1)              EF+=process[i];
        else if(process[i]<block[bestIdx]) IF+=block[bestIdx]-process[i];
    }
    print_memory(allocation, process, n);
    printf("INTERNAL FRAGMENTATION : %d KB\n",IF);
    printf("EXTERNAL FRAGMENTATION : %d KB\n",EF);
}

void Worst_Fit(int block[], int m, int process[], int n)
{
    int block1[m],IF=0,EF=0;
    for(int i=0; i<m ;i++)  block1[i]=block[i];
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block1[j] >= process[i] && block1[j]==block[j])
            {
                if (worstIdx == -1 || block1[worstIdx] < block1[j])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            block1[worstIdx] -= process[i]; 
        }
        if(allocation[i]==-1)               EF+=process[i];
        else if(process[i]<block[worstIdx]) IF+=block[worstIdx]-process[i];
    }
    print_memory(allocation, process, n);
    printf("INTERNAL FRAGMENTATION : %d KB\n",IF);
    printf("EXTERNAL FRAGMENTATION : %d KB\n",EF);
}

int main()
{
    int m, n;
    printf("Enter The No. of Blocks : ");
    scanf("%d", &m);
    int block[m];
    printf("Enter The size of each block1 :");
    for (int i = 0; i < m; i++)     scanf("%d", &block[i]);


    printf("Enter The No. of Process : ");
    scanf("%d", &n);
    int process[n];
    printf("Enter The size of each Process :");
    for (int i = 0; i < n; i++)    scanf("%d", &process[i]);

    printf("MEMORY ALLOCATION FOR VARIABLE SIZE PARTITIONING : \n");
 
    printf("First Fit:\n");
    First_Fit(block, m, process, n);

    printf("\nBest Fit:\n");
    Best_Fit(block, m, process, n);

    printf("\nWorst Fit:\n");
    Worst_Fit(block, m, process, n);



    return 0;
}
