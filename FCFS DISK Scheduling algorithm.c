#include <stdio.h>
#include <stdlib.h>

void main(){
    
    int i,rq[100],initial,total_head=0,rqno;
    printf("Enter the number of requests: ");
    scanf("%d",&rqno);
    printf("Enter the requests sequence: ");
    for(i=0;i<rqno;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the head initial head position: ");
    scanf("%d",&initial);
    
    for(i=0;i<rqno;i++){
        
        total_head = total_head + abs(rq[i]-initial);
        initial = rq[i];
    }
    
    printf("The total head moment is %d", total_head);
    
    
}
