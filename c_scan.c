#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, size, totalheadmovement = 0, initial, move, rq[100], n;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
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
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(rq[j] > rq[j+1]) {
                int temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }

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

        // Move from last request to end of disk
        totalheadmovement += abs((size - 1) - initial);
        initial = 0;  // Jump to beginning
        totalheadmovement += (size - 1);  // Jump from end to beginning

        for(i = 0; i < index; i++) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }

    } else {  // Moving towards lower end
        for(i = index - 1; i >= 0; i--) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }

        // Move to start of disk
        totalheadmovement += abs(initial - 0);
        initial = size - 1;  // Jump to end
        totalheadmovement += (size - 1);  // Jump from start to end

        for(i = n - 1; i >= index; i--) {
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }
    }

    printf("Total head movement = %d\n", totalheadmovement);
    return 0;
}
