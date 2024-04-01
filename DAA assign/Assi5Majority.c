#include <stdio.h>

int findMajorityElement(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;

        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > size / 2) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, size);
    if (majorityElement != -1) {
        printf("The majority element is %d\n", majorityElement);
    } else {
        printf("There is no majority element\n");
    }
    return 0;
}
