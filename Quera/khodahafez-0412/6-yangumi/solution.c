#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OMEGA 9223372036854775807LL

long long zeta[201];
long long gamma_prime[201];
long long chi[201][201];

int comparator(const void *p, const void *q) {
    long long l = *(const long long *)p;
    long long r = *(const long long *)q;
    if (l < r) return -1;
    if (l > r) return 1;
    return 0;
}

int main() {
    int n_val, k_val;
    scanf("%d %d", &n_val, &k_val);

    long long alpha[k_val];
    for (int i = 0; i < k_val; ++i) {
        scanf("%lld", &alpha[i]);
    }

    qsort(alpha, k_val, sizeof(long long), comparator);

    for (int i = 0; i <= n_val; ++i) {
        zeta[i] = OMEGA;
    }
    zeta[1] = 0;

    for (int i = 2; i <= n_val; ++i) {
        for (int p = 0; p <= k_val; ++p) {
            for (int q = 0; q <= i; ++q) {
                chi[p][q] = OMEGA;
            }
        }
        
        for (int q = 0; q <= i; q++) {
             if (zeta[q] != OMEGA) {
                chi[1][q] = zeta[q] + (long long)q * alpha[0];
             }
        }

        for (int p = 2; p <= k_val; ++p) {
            for (int q = p; q <= i; ++q) {
                for (int s = 1; s <= q - (p - 1); ++s) {
                    if (chi[p - 1][q - s] != OMEGA && zeta[s] != OMEGA) {
                        long long current_val = chi[p - 1][q - s] + zeta[s] + (long long)s * alpha[p - 1];
                        if (current_val < chi[p][q]) {
                            chi[p][q] = current_val;
                        }
                    }
                }
            }
        }
        
        for (int j = 2; j <= k_val; ++j) {
            if (chi[j][i] < zeta[i]) {
                zeta[i] = chi[j][i];
            }
        }
    }

    printf("%lld\n", zeta[n_val]);

    return 0;
}
