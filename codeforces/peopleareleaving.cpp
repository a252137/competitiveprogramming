#include <bits/stdc++.h>
#define MAXN (int)(1e6+10)

using namespace std;

int pai[MAXN], n;

void remove (int x) {
    if (x==n) pai[x] = -1;
    else pai[x] = pai[x+1];
}

int find (int x) {
    if (pai[x]==-1) return -1;
    if (x==pai[x]) return x;
    return pai[x] = find(pai[x]);
}

int main () {
    int m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) pai[i]=i;
    while (m--) {
        char c;
        int u;
        scanf (" %c %d", &c, &u);
        if (c=='-') {
            remove(u);
        }
        else {
            printf ("%d\n", find(u));
        }
    }
    return 0;
}