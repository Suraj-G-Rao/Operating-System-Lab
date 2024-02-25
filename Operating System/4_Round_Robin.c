/*
Gantt Chart

ProId      AT      BT      CT     TAT      WT      RT
p1         13       3      21       8       5       1
p2          8       2      10       2       0       0
p3          5       1       6       1       0       0
p4         12       4      18       6       2       0
p5         16       5      24       8       3       2

*/

#include<stdio.h>
#include<string.h>
struct processor{
    char name[20];
    int at,arrived,bt,rt,rst,ct,tat,wt;
};
int redeque[100],done=0,z=0;
void min_arrival_time(struct processor p[],int n){
    int mini=0;
    for (int i = 1; i < n; i++) {
        if((p[i].at < p[mini].at) ||(p[i].at == p[mini].at  && strcmp(p[mini].name, p[i].name) > 0)) {
            mini = i;
        }
    }
    if(p[mini].at!=0)  redeque[z++]=(p[mini].at)*(-1);
    redeque[z++]=mini;
    p[mini].arrived=1;
}
void add_redeque(struct processor p[], int n , int k){
    int arr=0;
    for(int i=0 ; i<n ;i++){
        if( p[i].arrived==0 && p[i].at<=p[redeque[k]].ct){
            redeque[z++]=i;
            p[i].arrived=1;
            arr=1;
        }
    }
    if(arr==0 && p[redeque[k]].rt==0){
        int m=100,t=-1;
        for(int i=0 ; i<n ;i++){
            if(p[i].rt>0 && p[i].at>p[redeque[k]].ct && m>(p[i].at - p[redeque[k]].ct)){
                m=p[i].at-p[redeque[k]].ct;
                t=i;
            }
        }
        redeque[z++]=m*(-1);
        redeque[z++]=t;
        p[t].arrived=1;
    }
    done=0;
    for(int i=0 ; i<n ; i++){
        if(p[i].arrived==1){
            done++;
        }
    }

}
void completion_time(struct processor p[], int n,int tq){
    int k=1,j=1,ct=0;
    for (int i = 0 ; i<z ; i++){
        if(i==0 && redeque[i]<0)  continue;
        if(redeque[i]>=0){
            if (p[redeque[i]].rt > tq){
                int q=z-2;
                p[redeque[i]].ct+=ct;
                while(q>=0 && redeque[q]<0){
                    p[redeque[i]].ct+=redeque[q]*(-1);
                    ct = p[redeque[i]].ct;
                    q--;
                }
                if (p[redeque[i]].rt == p[redeque[i]].bt)  p[redeque[i]].rst = ct - p[redeque[i]].at;
                p[redeque[i]].ct = ct + tq;
                ct = p[redeque[i]].ct;
                p[redeque[i]].rt -= tq;
                if (done != n)    add_redeque(p, n, i);
                redeque[z++] = redeque[i];
                printf("\n");
            }
            else if (p[redeque[i]].rt <= tq){
                int q=z-2;
                p[redeque[i]].ct+=ct;
                while(q>=0 && redeque[q]<0){
                    p[redeque[i]].ct+=redeque[q]*(-1);
                    ct = p[redeque[i]].ct;
                    q--;
                }
                if (p[redeque[i]].rt == p[redeque[i]].bt)  p[redeque[i]].rst = ct - p[redeque[i]].at;
                p[redeque[i]].ct = ct + p[redeque[i]].rt;
                ct = p[redeque[i]].ct;
                p[redeque[i]].rt = 0;
                if (done != n)   add_redeque(p, n, i);
            }
        }
    }
}
void waiting_turn_time(struct processor p[] , int n){
    for (int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}
void Sort_Pros_Name(struct processor p[] ,int n){
   for(int i=0; i<n-1; i++){     
     for(int j=0; j<n-i-1; j++){
       if(strcmp(p[j].name, p[j + 1].name) > 0){
           struct processor temp = p[j];
           p[j] = p[j + 1];
           p[j + 1] = temp; 
       }
     }
   }
}
void Avg_tat_wt(struct processor p[], int n){
    int T_TAT = 0, T_WT = 0 , T_RT=0;
    float m = n;
    for (int i = 0; i < n; i++){
        T_TAT += p[i].tat;
        T_WT += p[i].wt;
        T_RT += p[i].rst;
    }
    printf("Total TurnArounTime of the processor is %d and Average TurnArounTime of the processor is %.4f \n\n", T_TAT, T_TAT / m);
    printf("Total WaitingTime of the processor is %d and Average Waiting of the processor is %.4f\n\n", T_WT, T_WT / m);
    printf("Total Response Time of the processor is %d and Average Response Time of the processor is %.4f\n\n ", T_RT, T_RT / m);
}
int main(){
    int n,tq;
    printf("Enter The Number Of Processors : ");
    scanf("%d",&n);
    struct processor p[n+1];

    printf("Enter The Process Names : ");
    for(int i=0 ; i<n ; i++){
        scanf("%s",p[i].name);
    }
    printf("Enter The Arrival Time of all process : ");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&p[i].at);
    }
    printf("Enter The Burst Time of all process : ");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].ct=0;
        p[i].arrived=0;
        p[i].rst=0;
    }
    p[n].ct=0;
    printf("Enter The Time Quantum : ");
    scanf("%d",&tq);
    min_arrival_time(p,n);
    completion_time(p,n,tq);
    waiting_turn_time(p,n);
    Sort_Pros_Name(p,n);

    printf("\n\nGantt Chart\n\n");
    printf("ProId\t   AT\t   BT\t   CT\t  TAT\t   WT\t   RT\n");
    for (int i = 0; i < n; i++) {
        printf("%s   \t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", p[i].name,p[i].at, p[i].bt, p[i].ct,p[i].tat,p[i].wt,p[i].rst);
    } 
    printf("\n");
    Avg_tat_wt(p,n);

    return 0;
}