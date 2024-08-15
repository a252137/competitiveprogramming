#include <bits/stdc++.h>
#define MAXN 200010
#define iii pair<pair<int, int>, int>

using namespace std;

int pai[MAXN], tam[MAXN];

int find (int x) {
    if (x==pai[x]) return x;
    return pai[x]=find(pai[x]);
}

void join (int u, int v) {
    int a = find(u);
    int b = find(v);
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
    for (int i=1; i<=n; i++) {
        pai[i]=i;
        tam[i]=1;
    }
    vector<iii> adj;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        adj.push_back({{c, a}, b});
    }
    sort(adj.begin(), adj.end());
    long long int ans = 0;
    for (int i=0; i<m; i++) {
        int c = adj[i].first.first;
        int a = adj[i].first.second;
        int b = adj[i].second;
        if (find(a)==find(b)) continue;
        join(a, b);
        ans += c;
    }
    printf ("%lld\n", ans);
    return 0;
}