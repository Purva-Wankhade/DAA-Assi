#include <stdio.h>
int main()
{
    int n = 0;
    printf("Enter the number of cards : ");
    scanf("%d", &n);
    int pile[n];
    
    int onePosition = 0;
    printf("Enter the number of cards you want to remove from the top : ");
    scanf("%d", &onePosition);
    pile[onePosition] = 1;
    
    int count = 2;
    for(int i = 0; i<n; i++){
        if(onePosition != i){
            pile[i] = count;
            count++;
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d", pile[i]);
    }
    return 0;
}



