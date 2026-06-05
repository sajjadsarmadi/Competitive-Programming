#include <stdio.h>
#include <stdbool.h>

#define BISHTARIN 1000005
#define MOD 1000000007LL

bool isValid[BISHTARIN];
int valids[BISHTARIN]; 
int tedadValid = 0;

void sakhtan(long long n) {
    
    for (long long i = 2; i <= n; i++) {
        isValid[i] = true;
    }
    
    for (long long i = 2; i *i <= n; i++) {
        if (isValid[i]) {
            for (long long j = i *i; j <= n; j += i) {
                isValid[j] = false;
            }
        }
    }
    
    for (long long i = 2; i <= n; i++) {
        if (isValid[i]) {
            valids[tedadValid++] = (int)i;
        }
    }
}

long long gereftanFactor(long long n, long long p) {
    long long tedad = 0;
    while (n > 0) {
        tedad += (n / p);
        n /= p;
    }
    return tedad;
}

int main() {
    long long a, b;
    
    if (scanf("%lld %lld", &a, &b) != 2) return 0;
    
    if (a == b) {
        printf("1\n");
        return 0;
    }
    
    sakhtan(b);
    
    long long taghsemat = 1;
    
    for (int i = 0; i < tedadValid; i++) {
        long long p = valids[i];
        
        long long factoB = gereftanFactor(b, p);
        long long factorA = gereftanFactor(a, p);
        long long finalFactor = factoB - factorA;
        
        taghsemat = (taghsemat * (finalFactor + 1)) % MOD;
    }
    
    printf("%lld\n", taghsemat);
    
    return 0;
}
