#include <stdio.h>

void main(){
    int bsize[10],psize[10],bno,pno,i,j,allocation[10];

    for(i=0;i<10;i++){
        allocation[i] = -1;
    }

    printf("Enter the number of process: " );
    scanf("%d", &pno);
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each process: ");
    for(i=0;i<pno;i++){
        scanf("%d",&psize[i]);
    }
    printf("Enter the size of each block");
    for(i=0;i<bno;i++){
        scanf("%d",&bsize[i]);
    }
    for(i=0;i<pno;i++){
        int best = -1;
        for(j=0;j<bno;j++){
            if(psize[i]<=bsize[j]){
                if(best == -1 || bsize[j]<bsize[best]){
                    best = j;
                }


            }

        }

        if(best !=-1){
            allocation[i] = best;
            bsize[best] -= psize[i];


        }

    }

    // time to print stuffs babyy
    printf("\n Process number\t Process size\t Allocated block\n");
    for(i=0;i<pno;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i] !=-1){
            printf("%d \n",allocation[i]+1);
        }
        else{
            printf("Not allcated\n");
        }
    }



}
