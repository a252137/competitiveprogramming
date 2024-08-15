#include <bits/stdc++.h>
#define MAXN 300010

using namespace std;

int tam[MAXN], pai[MAXN], maxi[MAXN], mini[MAXN];

int find (int x) {
    if (x==pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join (int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a==b) return;
    if (tam[a]>tam[b]) {
        pai[b]=a;
        tam[a]+=tam[b];
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
    }
    else {
        pai[a]=b;
        tam[b]+=tam[a];
        maxi[b] = max(maxi[a], maxi[b]);
        mini[b] = min(mini[a], mini[b]);
    }
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        tam[i] = 1;
        pai[i] = i;
        maxi[i] = i;
        mini[i] = i;
    }
    while (m--) {
        char s[10];
        int u, v;
        scanf ("%s", s);
        if (strcmp(s, "union") == 0) {
            scanf ("%d%d", &u, &v);
            join(u, v);
        }
        else {
            scanf ("%d", &u);
            u = find(u);
            printf ("%d %d %d\n", mini[u], maxi[u], tam[u]);
        }
    }
    return 0;
}