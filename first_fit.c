#include <stdio.h>

void main(){
    int bno,pno,bsize[100],psize[100],i,j,allocation[100];

    printf("Enter the number of process and number of blocks: ");
    scanf("%d %d", &pno, &bno);
    printf("Enter the processes: ");
    for(i=0;i<pno;i++){
        scanf("%d",&psize[i]);
    }
    printf("Enter the blocks: ");
    for(i=0;i<bno;i++){
        scanf("%d",&bsize[i]);
    }

    for(i=0;i<50;i++){
        allocation[i] = -1;
    }
    
    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(psize[i]<=bsize[j]){
                allocation[i] = bsize[j];
                bsize[j] -=psize[i];
                break;
            }

        }
    }


    printf("process Number\t process size\t block size \n");
    for(i=0;i<pno;i++){
        printf("%d\t\t%d\t\t", i+1,psize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]);
        }
        else{
            printf("Not allocated\n");
        }
    }












}
