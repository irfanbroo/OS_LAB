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
