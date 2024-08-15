#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int tam[MAXN], pai[MAXN];
int maxi, comp;

int find (int x) {
    if (x==pai[x]) return x;
    return pai[x]=find(pai[x]);
}

void join (int u, int v) {
    int a = find(u), b = find(v);
    if (a==b) return;
    if (tam[a]>tam[b]) {
        pai[b]=a;
        tam[a]+=tam[b];
    }
    else {
        pai[a]=b;
        tam[b]+=tam[a];
    }
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    maxi = 1;
    comp = n;
    for (int i=1; i<=n; i++) {
        tam[i]=1;
        pai[i]=i;
    }
    while (m--) {
        int u, v;
        scanf ("%d%d", &u, &v);
        if (find(u)==find(v)) {
            printf ("%d %d\n", comp, maxi);
            continue;
        }
        join(u ,v);
        comp--;
        maxi = max(maxi, tam[find(u)]);
        printf ("%d %d\n", comp, maxi);
    }
    return 0;
}