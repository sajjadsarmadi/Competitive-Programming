#include <stdio.h>

#define BESHTAREN 200005

int pedarMain[BESHTAREN];
int jaeghahMain[BESHTAREN];

int pNext[BESHTAREN];


static inline int khondan() {
    int x = 0;
    char c = getchar();
    
    while (c < '0' || c > '9') {
        c = getchar();
    }
    
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    
    return x;
}

void porkardan(int n) {
    for (int i = 1; i <= n + 1; i++) {
        pedarMain[i] = i;
        jaeghahMain[i] = 0;
        pNext[i] = i;
    }
}

int peydakardanMain(int i) {
    if (pedarMain[i] == i)
        return i;
    return pedarMain[i] = peydakardanMain(pedarMain[i]);
}

void planA(int i, int j) {
    int adad_i = peydakardanMain(i);
    int adad_j = peydakardanMain(j);
    
    if (adad_i != adad_j) {

        if (jaeghahMain[adad_i] < jaeghahMain[adad_j]) {
            pedarMain[adad_i] = adad_j;
        } else if (jaeghahMain[adad_i] > jaeghahMain[adad_j]) {
            pedarMain[adad_j] = adad_i;
        } else {
            pedarMain[adad_j] = adad_i;
            jaeghahMain[adad_i]++; 
        }
    }
}

int peydakardanNext(int i) {
    if (pNext[i] == i)
        return i;
    return pNext[i] = peydakardanNext(pNext[i]);
}

int main() {
    int n = khondan();
    int q = khondan();
    
    porkardan(n);
    
    while (q--) {
        int jens = khondan();
        int x = khondan();
        int y = khondan();
        
        if (jens == 1) {
            planA(x, y);
        } 
        else if (jens == 2) {
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            
            int fela = peydakardanNext(x);
            
            while (fela < y) {
                int nxt = fela + 1;
                
                planA(fela, nxt);
                
                pNext[fela] = peydakardanNext(nxt);
                
                fela = pNext[fela];
            }
        } 
        else if (jens == 3) {
            
            if (peydakardanMain(x) == peydakardanMain(y)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
