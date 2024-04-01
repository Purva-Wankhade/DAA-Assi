#include <stdio.h>
#include <limits.h>

void Merge(int A[], int l, int mid1, int mid2, int h) {
    int i = l, j = mid1 + 1, k = l, m = mid2 + 1;
    int B[100];

    while (i <= mid1 || j <= mid2 || m <= h) {
        int val1 = (i <= mid1) ? A[i] : INT_MAX;
        int val2 = (j <= mid2) ? A[j] : INT_MAX;
        int val3 = (m <= h) ? A[m] : INT_MAX;

        if (val1 <= val2 && val1 <= val3) {
            B[k++] = A[i++];
        } else if (val2 <= val1 && val2 <= val3) {
            B[k++] = A[j++];
        } else {
            B[k++] = A[m++];
        }
    }

    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h) {
    int mid1, mid2;
    if (l < h) {
        mid1 = l + (h - l) / 3;
        mid2 = l + 2 * (h - l) / 3;
        MergeSort(A, l, mid1);
        MergeSort(A, mid1 + 1, mid2);
        MergeSort(A, mid2 + 1, h);
        Merge(A, l, mid1, mid2, h);
    }
}

int main() {
    int a[] = {6,7,2,1,9,8,3,9};
    int n = sizeof(a) / sizeof(a[0]);
    
    MergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}