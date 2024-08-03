#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[300010];
int pai[300010];
int dist[300010];

int find (int x) {
    
    if (pai[x]==x) {
        
        dist[x]=0;
        return x;
        
    }
    
    int y = find (pai[x]);
    
    dist[x]+=dist[pai[x]];
    
    return pai[x]=y;
    
}

void join (int a, int b) {
    
    pai[a]=b;
    dist[a]++;
    
}

int main() {
    
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) pai[i]=i;
    
    for (int i=1; i<=m; i++) {
        
        int a;
        scanf ("%d", &a);
        
        if (a==2) {
            
            int c;
            scanf ("%d", &c);
            find(c);
            
            printf ("%d\n", dist[c]);
            
        }
        
        else {
            
            int b, c;
            scanf ("%d%d", &b, &c);
            join (b, c);
            
        }
        
    }
    
    return 0;
    
}
