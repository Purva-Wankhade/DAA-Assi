#include <stdio.h>
#include <stdlib.h>

int findMajorityElement(int arr[], int size) {
    int *hash_table = (int *)calloc(1000, sizeof(int)); 
    for (int i = 0; i < size; i++) {
        hash_table[arr[i]]++;
    }
    for (int i = 0; i < 1000; i++) {
        if (hash_table[i] > size / 2) {
            free(hash_table); 
            return i;
        }
    }
    free(hash_table);
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
