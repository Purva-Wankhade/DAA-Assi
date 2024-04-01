#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void kWayMerge(int arr[], int left, int right, int k) {
    if (left < right) {
        int n = (right - left + 1) / k;
        for (int i = 0; i < k; i++) {
            int subArrayLeft = left + i * n;
            int subArrayRight = (i == k - 1) ? right : (left + (i + 1) * n - 1);
            kWayMerge(arr, subArrayLeft, subArrayRight, k);
        }
        for (int i = 1; i < k; i++) {
            merge(arr, left, left + i * n - 1, left + (i + 1) * n - 1);
        }
    }
}

int main() {
    int k = 3; 
    int arr[] = {12, 18, 27, 9, 14, 19, 7, 11, 13};
    printf("Before Sorting\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int totalElements = n;
    kWayMerge(arr, 0, totalElements - 1, k);
    printf("\nAfter Sorting: ");
    for (int i = 0; i < totalElements; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
