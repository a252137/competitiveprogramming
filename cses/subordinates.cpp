#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int tam[MAXN], pai[MAXN];
vector<int> adj[MAXN];

int calc (int x) {
    if ((int)adj[x].size()==0) return tam[x] = 1;
    if (tam[x]!=-1) return tam[x];
    int ans = 1;
    for (int j=0; j<(int)adj[x].size(); j++) {
        ans += calc(adj[x][j]);
    }
    return tam[x] = ans;
}

int main () {
    int n;
    scanf ("%d", &n);
    pai[1]=1;
    for (int i=2; i<=n; i++) {
        int x;
        scanf ("%d", &x);
        pai[i]=x;
        adj[x].push_back(i);
    }
    for (int i=1; i<=n; i++)tam[i] = -1;
    calc(1);
    for (int i=1; i<=n; i++) printf ("%d ", tam[i]-1);
    printf ("\n");
    return 0;
}