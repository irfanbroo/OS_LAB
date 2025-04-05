#include <stdio.h>

struct Process{
    int pid;
    int bt;
    int at;
    int ct;
    int wt;
    int tat;
}p[20],temp;
int totaltat =0, totalwt =0;
void main(){
    int i,j,n;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    
    for(i=0;i<n;i++){
        printf("Enter the pid, arrival time and burst time of process %d: ",i+1);
        scanf("%d%d%d", &p[i].pid,&p[i].at,&p[i].bt);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }

        }
    }

    p[0].ct = p[0].bt + p[0].at;
    for(i =0;i<n;i++){
        if(p[i].at > p[i-1].ct){
            p[i].ct = p[i].bt + p[i].at;
        }
        else{
            p[i].ct = p[i].bt + p[i-1].ct;
        }
    } 

    for(i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    printf("\nPROCESS ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n", 
            p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totaltat += p[i].tat;
        totalwt += p[i].wt;

}
    printf("\nAverage tat is %.2f: ",(float)totaltat/n);
    printf("\n Average wt is %.2f", (float)totalwt/n);



}
