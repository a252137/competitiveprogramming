#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int tin[MAXN], tout[MAXN], t;
int chefe[MAXN][20];
vector<int> grafo[MAXN];
int nivel[MAXN];

bool ancestral (int d, int a) {
    if (tin[d]>tin[a] && tout[d]<tout[a]) return true;
    else return false;
}

void dfs (int x) {
    tin[x] = ++t;
    for (int i=0; i<(int)grafo[x].size(); i++) {
        int adj = grafo[x][i];
        if (tin[adj]==0) {
            nivel[adj] = nivel[x]+1;
            dfs(adj);
        }
    }
    tout[x] = ++t;
    return;
}

int lca (int x, int y) {
    if (x==y) return x;
    if (ancestral(x, y)==true) return y;
    if (ancestral(y, x)==true) return x;
    if (nivel[y]>nivel[x]) swap(x, y);
    int cont = 19;
    while (cont>=0) {
        if (ancestral(y, chefe[x][cont]) == false) x = chefe[x][cont];
        cont--;
    } 
    return chefe[x][0];
}

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    chefe[1][0]=1;
    for (int i=2; i<=n; i++) {
        scanf ("%d", &chefe[i][0]);
        grafo[chefe[i][0]].push_back(i);
    }
    for (int i=1; i<20; i++) {
        for (int j=1; j<=n; j++) {
            chefe[j][i] = chefe[chefe[j][i-1]][i-1];
        }
    }
    nivel[1] = 1;
    dfs(1);
    while (q--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        printf ("%d\n", lca(x, y));
    }
    return 0;
}