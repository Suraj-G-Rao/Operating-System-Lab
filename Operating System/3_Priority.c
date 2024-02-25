#include<stdio.h>
#include<string.h>
struct processor{
    char name[20];
    int pr,at,bt,ct,tat,wt ;
};
void swap_process(struct processor *p1 , struct processor *p2){
    struct processor temp = *p1;
    *p1=*p2;
    *p2=temp;
}
int condition_asc(struct processor p[] , int k ,int j){
    if (((p[j].pr > p[j + 1].pr)  || ((p[j].pr == p[j + 1].pr) && (p[j].at > p[j + 1].at)) || ((p[j].pr == p[j + 1].pr) && (p[j].at == p[j + 1].at) && strcmp(p[j].name, p[j + 1].name) > 0))   &&  (p[k].ct >= p[j + 1].at))  return 1;
    return 0;
}
int condition_des(struct processor p[] , int k ,int j){
    if (((p[j].pr < p[j + 1].pr)  || ((p[j].pr == p[j + 1].pr) && (p[j].at < p[j + 1].at)) || ((p[j].pr == p[j + 1].pr) && (p[j].at == p[j + 1].at) && strcmp(p[j].name, p[j + 1].name) > 0))   &&  (p[k].ct >= p[j + 1].at))  return 1;
    return 0;
}
void Sort_Process_asc(struct processor p[],int k, int start , int end){
    for (int i = start; i < end; i++){
        for (int j = start; j < end - 1; j++){
            if (condition_asc(p,k,j))   swap_process(&p[j],&p[j+1]);
        }
    }
}
void Sort_Process_des(struct processor p[],int k , int start , int end){
    for (int i = start; i < end; i++){
        for (int j = start; j < end-1 ; j++){
            if (condition_des(p,k,j))   swap_process(&p[j],&p[j+1]);
        }
    }
}
void min_arrival_time(struct processor p[],int n){
    int mini=0;
    for (int i = 1; i < n; i++) {
        if((p[i].at < p[mini].at)  || (p[i].at == p[mini].at && p[i].pr<p[mini].pr)||(p[i].at == p[mini].at  && p[i].pr==p[mini].pr && strcmp(p[mini].name, p[i].name) > 0)) {
            mini = i;
        }
    }
    if (mini != -1)  swap_process(&p[0],&p[mini]);
}
void Sort_Lowest_priority(struct processor p[] , int n , int k){
    int count=n-1,ct=0;
    for(int i=k+1 ; i<n ;i++){
        if(p[i].at>p[k].ct) ct++;
    }
    if (ct != n - k - 1){
        for (int i = k + 1; i < count; i++){
            while (p[k].ct < p[i].at && count > i){
                swap_process(&p[i],&p[count]);
                count--;
            }
        }
        Sort_Process_asc(p,k,k+1,count+1);
        Sort_Process_asc(p,k,count,n);
    }
    else{
        Sort_Process_asc(p,k,k+1,n);
    }
}
void Sort_Highest_priority(struct processor p[] , int n , int k){
    int count=n-1,ct=0;
    for(int i=k+1 ; i<n ;i++){
        if(p[i].at>p[k].ct) ct++;
    }
    if (ct != n - k - 1){
        for (int i = k + 1; i < count; i++){
            while (p[k].ct < p[i].at && count > i){
                swap_process(&p[i],&p[count]);
                count--;
            }
        }
        Sort_Process_des(p,k,k+1,count+1);
        Sort_Process_des(p,k,count,n);
    }
    else{
        Sort_Process_des(p,k,k+1,n);
    }
}
void completion_time(struct processor p[], int n , int ch){
    int k=0;
    p[0].ct = p[0].at + p[0].bt;
    if(ch==1) Sort_Lowest_priority(p,n,k);
    else      Sort_Highest_priority(p,n,k);
    int ct = p[0].ct;
    for (int i = 1; i < n; i++){
        int lag=0;
        if(p[i].at>ct) lag = p[i].at-ct;  
        p[i].ct = lag + ct + p[i].bt;
        ct = p[i].ct;
        k=i;
        if(ch==1) Sort_Lowest_priority(p,n,k);
        else      Sort_Highest_priority(p,n,k);
    }
}
void waiting_turn_time(struct processor p[] , int n){
    for (int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}
void Sort_Pros_Name(struct processor p[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (strcmp(p[j].name, p[j + 1].name) > 0){
                struct processor temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void Avg_tat_wt(struct processor p[], int n){
    int T_TAT = 0, T_WT = 0;
    float m = n;
    for (int i = 0; i < n; i++){
        T_TAT += p[i].tat;
        T_WT += p[i].wt;
    }
    printf("Total TurnArounTime of the processor is %d and Average TurnArounTime of the processor is %.4f \n", T_TAT, T_TAT / m);
    printf("Total WaitingTime of the processor is %d and Average Waiting of the processor is %.4f\n ", T_WT, T_WT / m);
}
int main(){
    int n,k=0,ch;
    printf("ENTER THE PRIORITY ORDER : \n");
    printf("FOR LOWEST PRIORITY FIRST PRESS : 1 \n");
    printf("FOR HIGHEST PRIORITY FIRST PRESS : 2 \n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    printf("Enter The Number Of Processors : ");
    scanf("%d",&n);
    struct processor p[n];

    printf("Enter The Process Names : ");
    for(int i=0 ; i<n ; i++){
        scanf("%s",p[i].name);
    }
    printf("Enter The Priority of all process : ");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&p[i].pr);
    }
    printf("Enter The Arrival Time of all process : ");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&p[i].at);
    }
    printf("Enter The Burst Time of all process : ");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&p[i].bt);
    }
    min_arrival_time(p,n);
    completion_time(p,n,ch);
    waiting_turn_time(p,n);
    Sort_Pros_Name(p,n);

    printf("\nGantt Chart\n\n");
    printf("ProId\t   PRIO\t   AT\t   BT\t   CT\t  TAT\t   WT\t\n");
    for (int i = 0; i < n; i++) {
        printf("%s   \t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t\n", p[i].name,p[i].pr,p[i].at, p[i].bt, p[i].ct,p[i].tat,p[i].wt);
    } 
    printf("\n");
    Avg_tat_wt(p,n);

    return 0;
}