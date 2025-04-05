// Producer Consumer problem

#include <stdio.h>

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    printf("Producer Produces item: %d\n", ++x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item: %d\n", x--);
    ++mutex;
}

int main() {
    int n;
    printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 to Exit\n");
    do {
        printf("\nEnter the choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full\n");
                break;

            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(n != 3);

    return 0;
}
