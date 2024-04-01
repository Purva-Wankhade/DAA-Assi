#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int numbers[MAX_SIZE];
    int input, count = 0;
    double sum = 0;

    while (1) {
        printf("Enter an integer:");
        scanf("%d", &input);

        if (input == -3) {
            printf("Exit\n");
            break;
        } else if (input == -2) {
            if (count == 0) {
                printf("No numbers\n");
            } else {
                double average = sum/count;
                printf("Average of last 10 numbers: %.2f\n", average);
            }
        } else if (input == -1) {
            if (count == 0) {
                printf("No numbers entered yet.\n");
            } else {
                int largest = numbers[0];
                for (int i = 1; i < count; i++) {
                    if (numbers[i] > largest) {
                        largest = numbers[i];
                    }
                }
                printf("Largest of last 10 numbers:%d\n", largest);
            }
        } else {
            numbers[count % MAX_SIZE] = input;
            count++;
            sum += input;
        }
    }
    return 0;
}
