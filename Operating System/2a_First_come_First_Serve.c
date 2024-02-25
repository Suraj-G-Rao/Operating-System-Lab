#include <stdio.h>
#include <string.h>
struct processor
{
  char name[10];
  int AT;
  int BT;
  int CT;
  int TAT;
  int WT;
};
void SortAccToArrTime(struct processor pros[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if ((pros[j].AT > pros[j + 1].AT) || (pros[j].AT == pros[j + 1].AT && strcmp(pros[j].name, pros[j + 1].name) > 0))
      {
        struct processor temp = pros[j];
        pros[j] = pros[j + 1];
        pros[j + 1] = temp;
      }
    }
  }
}
void CalCompletionTime(struct processor pros[], int n)
{
  int Completion_Time = 0;
  for (int i = 0; i < n; i++)
  {
    int lag = 0;
    if (pros[i].AT > Completion_Time)
      lag = pros[i].AT - Completion_Time;
    pros[i].CT = lag + Completion_Time + pros[i].BT;
    Completion_Time = pros[i].CT;
  }
}
void CalTatWt(struct processor pros[], int n)
{
  for (int i = 0; i < n; i++)
  {
    pros[i].TAT = pros[i].CT - pros[i].AT;
    pros[i].WT = pros[i].TAT - pros[i].BT;
  }
}
void SortAccToProsName(struct processor pros[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (strcmp(pros[j].name, pros[j + 1].name) > 0)
      {
        struct processor temp = pros[j];
        pros[j] = pros[j + 1];
        pros[j + 1] = temp;
      }
    }
  }
}
void Avg_tat_wt(struct processor pros[], int n)
{
  int T_TAT = 0, T_WT = 0;
  float Avg_TAT, Avg_WT, m = n;
  for (int i = 0; i < n; i++)
  {
    T_TAT += pros[i].TAT;
    T_WT += pros[i].WT;
  }
  printf("Total TurnArounTime of the processor is %d and Average TurnArounTime of the processor is %.4f \n", T_TAT, T_TAT / m);
  printf("Total WaitingTime of the processor is %d and Average Waiting of the processor is %.4f\n ", T_WT, T_WT / m);
}
int main()
{
  int i, n;
  printf("Enter the number of processor\n");
  scanf("%d", &n);
  struct processor pros[n];

  for (i = 0; i < n; i++)
  {
    printf("Enter processor name\n");
    scanf("%s", pros[i].name);
    printf("%s Ariving Time(AT)\n", pros[i].name);
    scanf("%d", &pros[i].AT);
    printf("%s Bursting Time(BT)\n", pros[i].name);
    scanf("%d", &pros[i].BT);
  }
  SortAccToArrTime(pros, n);
  CalCompletionTime(pros, n);
  CalTatWt(pros, n);
  SortAccToProsName(pros, n);

  printf("\nGantt Chart\n\n");
  printf("ProId\t   AT\t   BT\t   CT\t  TAT\t   WT\t\n");
  for (i = 0; i < n; i++)
  {
    printf("%s   \t%5d\t%5d\t%5d\t%5d\t%5d\t\n", pros[i].name, pros[i].AT, pros[i].BT, pros[i].CT, pros[i].TAT, pros[i].WT);
  }
  Avg_tat_wt(pros, n);
  return 0;
}