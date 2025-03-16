#include <stdio.h>

struct Process{
    
    int id;
    int Bt;
    int Pr;
    int Wt;
    int Tat;
    
} P[20],temp;

void main(){
    int i,j,n;
    
    printf("Enter the number of processes");
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        printf("Enter the process id, burst time, priority number of p-%d: ",i+1);
        scanf("%d%d%d",&P[i].id,&P[i].Bt,&P[i].Pr );
        
    }    
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(P[j].Pr > P[j+1].Pr){
                temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;
            }
        }
        
    }
    
    P[0].Wt = 0;
    P[0].Tat = P[0].Bt;
    for(i=1;i<n;i++){
        P[i].Wt = P[i-1].Tat;
        P[i].Tat = P[i].Bt + P[i].Wt;
        
        
        
    }
    printf("PROCESS ID\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");
    printf("__________\t_________\t_________\t_________\t_________\n");

    // Loop to print each process's details
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].id, P[i].Bt, P[i].Pr, P[i].Wt, P[i].Tat);
    }
    
    
    
}
