#include <bits/stdc++.h>

using namespace std;

vector<int> cartas[50010];
vector<int> adj[50010];
int dp[50010][20];
int nivel[50010];

void dfs (int x) {
    
    for (int i=0; i<(int)adj[x].size(); i++) {
        
        int y = adj[x][i];
        if (y==dp[x][0]) continue;
        
        dp[y][0]=x;
        nivel[y]=nivel[x]+1;
        dfs(y);
        
    }
    
}

int lca (int u, int v) {
    
    if (nivel[u]>nivel[v]) swap (u, v);
    
    for (int i=19; i>=0; i--) {
        
        if (nivel[dp[v][i]]>=nivel[u]) v=dp[v][i];
        
    }
    
    if (u==v) return u;
    
    for (int i=19; i>=0; i--) {
        
        if (dp[v][i]!=dp[u][i]) {
            
            v=dp[v][i];
            u=dp[u][i];
            
        }
        
    }
    
    return dp[u][0];
    
}

int main () {
    
    int n;
    long long int ans = 0;
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) {
        
        int x;
        scanf ("%d", &x);
        cartas[x].push_back(i);
        
    }
    
    for (int i=1; i<n; i++) {
        
        int a, b;
        scanf ("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    
    nivel[1]=0;
    dfs(1);
    
    for (int i=1; i<=19; i++) {
        
        for (int j=1; j<=n; j++) {
            
            dp[j][i]=dp[dp[j][i-1]][i-1];
            
        }
        
    }
    
    for (int i=1; i<=n/2; i++) {
        
        int l = lca(cartas[i][0], cartas[i][1]);
        ans += (nivel[cartas[i][0]]-nivel[l]) + (nivel[cartas[i][1]]-nivel[l]);
        
    }
    
    printf ("%lld\n", ans);
    
    return 0;
    
}
