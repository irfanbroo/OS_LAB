#include <stdio.h>
void main(){
    int bsize[10],psize[10],pno,bno,flag[10],allocation[10],i,j;

    for(i=0;i<10;i++){
        flag[i]=0;
        allocation[i]=-1;
    }
    printf("Enter the number of process: ");
    scanf("%d",&pno);
    printf("Enter the number of blocks: ");
    scanf("%d",&bno);
    printf("Enter the size of each blocks: ");
    for(i=0;i<bno;i++){
        scanf("%d",&bsize[i]);
    }
    printf("Enter the size of each process: ");
    for(i=0;i<pno;i++){
        scanf("%d",&psize[i]);
    }

    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(psize[i]<=bsize[j]){
                allocation[i] = j;
                bsize[j] -=psize[i];
                break;
            }

        }
    }

    printf("\n Process number\t Process size\t Block Number \n");
    for(i=0;i<pno;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }

    }


}
