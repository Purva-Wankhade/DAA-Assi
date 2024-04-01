#include <stdio.h>
#include <stdlib.h>

int josephus(int n, int k) {
    if (n == 1) {
        return 0;
    } else {
        int eliminated[n];
        for (int i = 0; i < n; i++) {
            eliminated[i] = 0; 
        }
        int current = 0; 
        for (int count = 0; count < n - 1; count++) {
            int step = 0; 

            while (step < k) {
                current = (current + 1) % n; 
                if (!eliminated[current]) {
                    step++;
                }
            }
            eliminated[current] = 1; 
        }
        for (int i = 0; i < n; i++) {
            if (!eliminated[i]) {
                return i;
            }
        }
        return -1; 
    }
}
int main() {
    int n, k;

    printf("Enter the total number of people (n): ");
    scanf("%d", &n);

    printf("Enter the counting interval (k): ");
    scanf("%d", &k);

    int survivor = josephus(n, k);
    printf("The survivor is at position %d.\n", survivor + 1);

    return 0;
}
