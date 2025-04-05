#include<stdio.h>
void main() {
    int at[100], bt[100], rt[100];
    int i =0, flag = 0, n, time = 0, remain, ts, sumwt=0,sumtat=0;

    printf("Enter the no of process :");
    scanf("%d",&n);
    remain = n;

    for(i=0;i<n;i++) {
        printf("Enter the arrival time and burst time for the process P%d :",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the time slice :");
    scanf("%d",&ts);

    while (remain != 0) {
        if (rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag =1;

        }
        else if(rt[i]>0) {
            rt[i]= rt[i]-ts;
            time+=ts;
            
        }

        if(rt[i] ==0 && flag == 1) {
            remain--;
            sumtat += time - at[i];
            sumwt += time - at[i] - bt[i]; 
            flag = 0;
        }

        if(i == n-1) {
            i = 0;
        } else if(at[i+1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }
    printf("Total waiting time: %d\n", sumwt);
    printf("Total turnaround time: %d\n", sumtat);
    printf("Average waiting time: %f\n", (float)sumwt/n); //convert to float for average calculation otherwise u will be fucked up
    printf("Average turnaround time: %f\n", (float)sumtat/n);
}

// My implementaion

#include <stdio.h>
void main(){
int at[100],bt[100],rt[100],n,i=0;
int ts,remain,flag=0,time=0,totalwt=0,totaltat=0;
printf("Enter the number of process: ");
scanf("%d",&n);

for(i=0;i<n;i++){
    printf("Enter the number of arrival time and burst time for %d process", i+1);
    scanf("%d %d",&at[i],&bt[i]);
    rt[i] = bt[i];
}

printf("Enter the time slice");
scanf("%d",&ts);
remain = n;

while(remain!=0){
    if(rt[i] <= ts && rt[i] > 0){
        time +=rt[i];
        rt[i] = 0;
        flag = 1;

    }
    else if(rt[i]> ts){
        time +=ts;
        rt[i] -=ts;

    }
    if(rt[i] == 0 && flag == 1){
        remain--;
        totalwt += time - at[i] - bt[i];       
        totaltat += time - at[i];
        flag = 0;

    }
    if(i == n-1) {
        i = 0;
    } else if(at[i+1] <= time) {
        i++;
    } else {
        i = 0;
    }

}
    printf("Total waiting time: %d\n", totalwt);
    printf("Total turnaround time: %d\n", totaltat);
    printf("Average waiting time: %f\n", (float)totalwt/n); //convert to float for average calculation otherwise u will be fucked up
    printf("Average turnaround time: %f\n", (float)totaltat/n);

}
