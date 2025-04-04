#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, size, totalheadmovement = 0, initial, move, rq[100], n;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rq[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    printf("Enter the disk size: ");
    scanf("%d", &size);

    printf("Enter the head movement direction (1 for high, 0 for low): ");
    scanf("%d", &move);

    // Sort the request array
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(rq[j] > rq[j+1]) {
                int temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }

    // Find index of first request greater than initial
    int index;
    for(i = 0; i < n; i++) {
        if(initial < rq[i]) {
            index = i;
            break;
        }
    }

    if(move == 1) {  // Moving towards higher end
        for(i = index; i < n; i++) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }

        // Move to end of disk
        totalheadmovement += abs((size - 1) - initial);
        initial = size - 1;

        // Then go to the lower requests
        for(i = index - 1; i >= 0; i--) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }

    } else {  // Moving towards lower end
        for(i = index - 1; i >= 0; i--) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }

        // Move to start (0)
        totalheadmovement += abs(initial - 0);
        initial = 0;

        // Then move up to remaining requests
        for(i = index; i < n; i++) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }
    }

    printf("The total head movement is %d\n", totalheadmovement);
    return 0;
}
