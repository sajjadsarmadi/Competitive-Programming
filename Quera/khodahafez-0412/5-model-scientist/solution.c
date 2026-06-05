#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100005
#define MAXM 100005

static inline int khondan() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    return x;
}

int avalDir[MAXN], entehaDir[MAXM], nxtDir[MAXM], labeDir = 0;
int avalUndir[MAXN], entehaUndir[MAXM * 2], nxtUndir[MAXM * 2], labeUndir = 0;

bool checkWcc[MAXN];       
int rang[MAXN];          

int idNodes[MAXN];
int adadSize = 0;
bool flgCharlhesh = false;    

void addDirLabe(int u, int v) {
    entehaDir[labeDir] = v;
    nxtDir[labeDir] = avalDir[u];
    avalDir[u] = labeDir++;
}

void addUndirLabe(int u, int v) {
    entehaUndir[labeUndir] = v;
    nxtUndir[labeUndir] = avalUndir[u];
    avalUndir[u] = labeUndir++;
    
    entehaUndir[labeUndir] = u;
    nxtUndir[labeUndir] = avalUndir[v];
    avalUndir[v] = labeUndir++;
}

void CheckWcc(int u) {
    checkWcc[u] = true;
    idNodes[adadSize++] = u; 
    
    for (int i = avalUndir[u]; i != -1; i = nxtUndir[i]) {
        int v = entehaUndir[i];
        if (!checkWcc[v]) {
            CheckWcc(v);
        }
    }
}

void dfs_cycle(int u) {
    rang[u] = 1; 
    
    for (int i = avalDir[u]; i != -1; i = nxtDir[i]) {
        int v = entehaDir[i];
        if (rang[v] == 1) {
            flgCharlhesh = true;
        } else if (rang[v] == 0) {
            dfs_cycle(v);
        }
    }
    
    rang[u] = 2;
}

int main() {
    
    memset(avalDir, -1, sizeof(avalDir));
    memset(avalUndir, -1, sizeof(avalUndir));
    
    int n = khondan();
    int m = khondan();
    
    
    for (int i = 0; i < m; i++) {
        int u = khondan();
        int v = khondan();
        addDirLabe(u, v);
        addUndirLabe(u, v);
    }
    
    int kol = 0;
    
    
    for (int i = 1; i <= n; i++) {
    
        if (!checkWcc[i] && avalUndir[i] != -1) {
            
            adadSize = 0;
            flgCharlhesh = false;
            
            CheckWcc(i);
            
            
            for (int j = 0; j < adadSize; j++) {
                int node = idNodes[j];
                if (rang[node] == 0) {
                    dfs_cycle(node);
                }
            }
            
            if (flgCharlhesh) {
                kol += adadSize;
            } else {
                kol += (adadSize - 1);
            }
        }
    }
    
    printf("%d\n", kol);
    
    return 0;
}
