#include <stdio.h>
#include <stdlib.h>

int mutex = 1;     // mutual exclusion
int full = 0;      // filled buffer slots
int empty = 10;    // empty buffer slots (buffer size = 10)
int item = 0;      // item counter

void producer() {
    --mutex;
    ++full;
    --empty;
    ++item;
    printf("\nProducer produces item %d", item);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", item);
    --item;
    ++mutex;
}

int main() {
    int choice;

    printf("\n--- Producer Consumer Problem ---");
    printf("\n1. Producer");
    printf("\n2. Consumer");
    printf("\n3. Exit");

    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1 && empty != 0) {
                    producer();
                } else {
                    printf("\nBuffer is FULL! Producer cannot produce.");
                }
                break;

            case 2:
                if (mutex == 1 && full != 0) {
                    consumer();
                } else {
                    printf("\nBuffer is EMPTY! Consumer cannot consume.");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }

        printf("\nStatus -> Full: %d | Empty: %d", full, empty);
    }

    return 0;
}