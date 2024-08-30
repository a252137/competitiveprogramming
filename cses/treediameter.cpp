#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

vector<int> adj[MAXN];
int vis[MAXN], nivel[MAXN];

void dfs (int x) {
    for (int i=0; i<(int)adj[x].size(); i++) {
        int u = adj[x][i];
        if (vis[u]==0) {
            vis[u]=1;
            nivel[u] = nivel[x]+1;
            dfs(u);
        }
    }
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[1]=1;
    dfs(1);
    int max_nivel = 0, node = 0;
    for (int i=1; i<=n; i++) {
        if (nivel[i]>max_nivel) {
            node = i;
            max_nivel = nivel[i];
        }
    }
    for (int i=1; i<=n; i++) vis[i] = 0;
    vis[node] = 1;
    nivel[node] = 0;
    dfs(node);
    max_nivel = 0;
    for (int i=1; i<=n; i++) max_nivel = max(max_nivel, nivel[i]);
    printf ("%d\n", max_nivel);
    return 0;
}