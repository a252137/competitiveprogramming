#include <bits/stdc++.h>
#define sec second
#define fir first
#define ll long long 

using namespace std;

vector<pair<int, int>> adj[100010];
int dp[100010][20];
int nivel[100010];
ll int dist[100010];
int pai[100010];

void dfs (int x) {
    
    for (int i=0; i<(int)adj[x].size(); i++) {
        
        int y = adj[x][i].fir;
        if (y==pai[x]) continue;
        
        pai[y]=x;
        nivel[y]=nivel[x]+1;
        dp[y][0]=x;
        dist[y]=dist[x]+adj[x][i].sec;
        dfs(y);
        
    }
    
}

int lca (int u, int v) {
    
    if (nivel[u]>nivel[v]) swap (u, v);
    
    for (int i=19; i>=0; i--) {
        
        if (nivel[dp[v][i]]>=nivel[u]) v = dp[v][i];
        
    }
    
    if (u==v) return u;
    
    for (int i=19; i>=0; i--) {
        
        if (dp[u][i]!=dp[v][i]) {
            
            u=dp[u][i];
            v=dp[v][i];
            
        }
        
    }
    
    return pai[u];
    
} 

int main () {
    
    while (true) {
    
    int n;
    scanf ("%d", &n);
    
    if (n==0) return 0;
    
    for (int i=1; i<=n-1; i++) {
        
        int a, b;
        scanf ("%d%d", &a, &b);
        
        adj[i].push_back(make_pair(a, b));
        adj[a].push_back(make_pair(i, b));
        
    }
    
    nivel[0]=1;
    pai[0]=0;
    dfs(0);
    
    for (int i=1; i<=19; i++) {
        
        for (int j=0; j<n; j++) {
            
            dp[j][i]=dp[dp[j][i-1]][i-1];
            
        }
        
    }
    
    int q;
    scanf ("%d", &q);
    
    for (int i=1; i<=q; i++) {
        
        int u, v;
        scanf ("%d%d", &u, &v);
        
        int ans = lca(u,v);
        
        printf ("%lld ", (dist[u] - dist[ans])+(dist[v] - dist[ans]));
        
    }
    
    printf ("\n");
    
    for (int i=0; i<=n-1; i++) {
        
        adj[i].clear();
        nivel[i]=0;
        pai[i]=0;
        
    }
    
    }
    
    return 0;
    
}






