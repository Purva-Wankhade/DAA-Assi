#include <stdio.h>

long long int powerMod_bruteForce(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

long long int powerMod_recursive(long long int base, long long int exp, long long int mod) {
    if (exp == 0)
        return 1;
    long long int temp = powerMod_recursive(base, exp / 2, mod);
    temp = (temp * temp) % mod;
    if (exp % 2 == 0)
        return temp;
    else
        return (base * temp) % mod;
}

int main() {
    long long int base, exp, mod;

    printf("Enter base: ");
    scanf("%lld", &base);
    printf("Enter exponent: ");
    scanf("%lld", &exp);
    printf("Enter modulus: ");
    scanf("%lld", &mod);

    printf("brute force approach: %lld\n", powerMod_bruteForce(base, exp, mod));
    printf("recursive approach: %lld\n", powerMod_recursive(base, exp, mod));

    return 0;
}

