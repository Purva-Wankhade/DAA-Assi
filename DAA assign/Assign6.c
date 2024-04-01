#include <stdio.h>
#include <string.h>

typedef long long ll;
ll MOD(char num[], int mod) {
    ll res = 0;
    for (int i = 0; i < strlen(num); i++) {
        res = (res * 10 + num[i] - '0') % (mod - 1);
    }
    return res;
}
ll ModExponent(ll a, ll b, ll m) {
    ll result;
    if (a == 0) return 0;
    else if (b == 0) return 1;
    else if (b & 1) {
        result = a % m;
        result = (result * ModExponent(a, b - 1, m)) % m;
    } else {
        result = ModExponent(a, b / 2, m);
        result = ((result % m) * (result % m)) % m;
    }
    return (result % m + m) % m;
}
int main() {
    ll a=2;
    char b[]="100";
    ll m = 17;
    ll a=2;
    char b[]="10";
    
    ll remainderB = MOD(b, m);
    printf("%lld\n", ModExponent(a, remainderB, m));

    return 0;
}
