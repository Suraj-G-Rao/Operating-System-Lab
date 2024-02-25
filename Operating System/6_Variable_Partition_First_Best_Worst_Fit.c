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
 3              125             1
 4              50              2
INTERNAL FRAGMENTATION : 0 KB
EXTERNAL FRAGMENTATION : 0 KB

Best Fit:

Process No.     Process Size    Block no.
 1              300             2
 2              25              2
 3              125             1
 4              50              Not Allocated
INTERNAL FRAGMENTATION : 50 KB
EXTERNAL FRAGMENTATION : 50 KB

Worst Fit:

Process No.     Process Size    Block no.
 1              300             2
 2              25              1
 3              125             1
 4              50              2
INTERNAL FRAGMENTATION : 0 KB
EXTERNAL FRAGMENTATION : 0 KB
*/
#include <stdio.h>
#include <string.h>
void print_memory(int allocation[],int process[], int n)
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
    int block1[m],IF=0,EF=0;
    for(int i=0; i<m ;i++)  block1[i]=block[i];
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (block1[j] >= process[i])
            {
                allocation[i] = j;
                block1[j] -= process[i];
                break;
            }
        }
        if(allocation[i]==-1) EF+=process[i];
    }
    for(int i=0 ; i<m ; i++){
        if(block1[i]!=block[i] && block1[i]!=0) IF+=block1[i];
    }
    print_memory(allocation,process,n);
    printf("INTERNAL FRAGMENTATION : %d KB\n",IF);
    printf("EXTERNAL FRAGMENTATION : %d KB\n",EF);

}

void Best_Fit(int block[], int m, int process[], int n)
{
    int block1[m],IF=0,EF=0;
    for(int i=0; i<m ;i++)  block1[i]=block[i];
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block1[j] >= process[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block1[bestIdx] > block1[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            block1[bestIdx] -= process[i];
        }
        if(allocation[i]==-1) EF+=process[i];
    }
    for(int i=0 ; i<m ; i++){
        if(block1[i]!=block[i]&& block1[i]!=0) IF+=block1[i];
    }
    print_memory(allocation,process,n);
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
            if (block1[j] >= process[i])
            {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (block1[worstIdx] < block1[j])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1){
            allocation[i] = worstIdx;
            block1[worstIdx] -= process[i];
        }
        if(allocation[i]==-1) EF+=process[i];

    }
    for(int i=0 ; i<m ; i++){
        if(block1[i]!=block[i]&& block1[i]!=0) IF+=block1[i];
    }
    print_memory(allocation,process,n);
    printf("INTERNAL FRAGMENTATION : %d KB\n",IF);
    printf("EXTERNAL FRAGMENTATION : %d KB\n",EF);
}

int main()
{
    int m,n;
    printf("Enter The No. of Blocks : ");
    scanf("%d",&m);
    int block[m];
    printf("Enter The size of each block1 :");
    for(int i=0 ;i<m ;i++)   scanf("%d",&block[i]);

    printf("Enter The No. of Process : ");
    scanf("%d",&n);
    int process[n];
    printf("Enter The size of each Process :");
    for(int i=0 ;i<n ;i++)   scanf("%d",&process[i]);



    printf("MEMORY ALLOCATION FOR VARIABLE SIZE PARTITIONING : \n");
    printf("First Fit:\n");
    First_Fit(block, m, process, n);

    printf("\nBest Fit:\n");
    Best_Fit(block, m, process, n);

    printf("\nWorst Fit:\n");
    Worst_Fit(block, m, process, n);

    return 0;
}