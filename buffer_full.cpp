#include <stdio.h>

#define BUFFER_SIZE 5

int mutex = 1;
int full = BUFFER_SIZE;   // buffer is FULL
int empty = 0;
int item = 5;

void producer() {
    --mutex;
    ++full;
    --empty;
    ++item;
    printf("\nProducer produces item %d", item);
    ++mutex;
}

int main() {
    printf("\n--- Producer Waiting Condition ---");
    printf("\nBuffer size: %d", BUFFER_SIZE);
    printf("\nInitial state -> Full: %d, Empty: %d\n", full, empty);

    if (mutex == 1 && empty != 0) {
        producer();
    } else {
        printf("Buffer is FULL! Producer must wait.\n");
    }

    return 0;
}