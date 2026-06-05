#include <stdio.h>


int main() {
    int t;
    
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        int d1, d2, d3, d4, d5, d6;
        
        if (scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6) == 6) {
            
            
            int fsum = d1 + d2 + d3;
            int ssum = d4 + d5 + d6;

            if (fsum == ssum) {
                printf("Possible\n");
            } else {
                printf("Impossible\n");
            }
        }
    }

    return 0;
}
