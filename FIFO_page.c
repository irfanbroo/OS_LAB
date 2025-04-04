#include<stdio.h>
void main() {
    int rs[100], m[100];
    int i, j, k, n, f, pagefault=0, count = 0;

    printf("Enter the lenght of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        m[i] = -1;
    }

    for(i=0;i<n;i++) {
        for(k=0;k<f;k++) {
            if(m[k] == rs[i]) {
                break;
            }
        }

        if(k == f) {
            m[count++] = rs[i];
            pagefault++;
        }
        
        for(j=0;j<f;j++) {
            printf("%d\t", m[j]);

        }
        if(k == f) {
            printf("\t PF NO: %d ", pagefault);
            
        }
        printf("\n");
        if (count == f) {
            count = 0;
        }
    }
    printf("Total number of page faults: %d\n", pagefault);
}