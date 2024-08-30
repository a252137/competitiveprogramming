#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int vis[MAXN], cont[MAXN];
vector<int> adj[MAXN];
int ans;

void dfs (int x) {
    if (adj[x].size()==1 && x!=1) {
        if (cont[x]==0 && cont[adj[x][0]]==0) {
            ans++;
            cont[x]=1;
            cont[adj[x][0]]=1;
            return;
        }
    }
    for (int i=0; i<(int)adj[x].size(); i++) {
        int u = adj[x][i];
        if (vis[u]==0) {
            vis[u]=1;
            dfs(u);
        }
    }
    for (int i=0; i<(int)adj[x].size(); i++) {
        int u = adj[x][i];
        if (cont[x]==0 && cont[u]==0) {
            ans++;
            cont[x]=1;
            cont[u]=1;
        }
    }
    return;
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
    printf ("%d\n", ans);
    return 0;
}