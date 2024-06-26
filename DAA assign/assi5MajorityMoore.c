#include <stdio.h>
int findMajorityElement(int arr[], int size) {
    int candidate = arr[0]; 
    int count = 1; 

    for (int i = 1; i < size; i++) {
        if (arr[i] == candidate) { 
            count++;
        } else { 
            count--; 
            if (count == 0) { 
                candidate = arr[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < size; i++) { 
        if (arr[i] == candidate) {
            count++;
        }
    }
    if (count > size / 2) {
        return candidate;
    } else { 
        return -1;
    }
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
