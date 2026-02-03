#include <stdio.h>

#define BUFFER_SIZE 5

int mutex = 1;
int full = 0;        // buffer is EMPTY
int empty = BUFFER_SIZE;
int item = 0;

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", item);
    --item;
    ++mutex;
}

int main() {
    printf("\n--- Consumer Waiting Condition ---");
    printf("\nBuffer size: %d", BUFFER_SIZE);
    printf("\nInitial state -> Full: %d, Empty: %d\n", full, empty);

    if (mutex == 1 && full != 0) {
        consumer();
    } else {
        printf("Buffer is EMPTY! Consumer must wait.\n");
    }

    return 0;
}