#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int tam[MAXN], pai[MAXN];

int find (int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join (int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a==b) return;
    if (tam[a]>tam[b]) {
        pai[b] = a;
        tam[a] += tam[b];
    }
    else {
        pai[a] = b;
        tam[b] += tam[a];
    }
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) tam[i]=1;
    for (int i=1; i<=n; i++) pai[i]=i;
    while (m--) {
        char s[10];
        int u, v;
        scanf ("%s", s);
        scanf ("%d%d", &u, &v);
        if (strcmp(s, "union") == 0) join(u, v);
        else {
            if (find(u) == find(v)) printf ("YES\n");
            else printf ("NO\n");
        }
    }
    return 0;
}