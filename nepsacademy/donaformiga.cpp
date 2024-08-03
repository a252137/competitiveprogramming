#include <bits/stdc++.h>
#define inf 210

using namespace std;

int h[inf];
vector<int> adj[inf];
int visitado[inf];

int main () {
    
    int n, t, p;
    scanf ("%d%d%d", &n, &t, &p);
    
    for (int i=1; i<=n; i++) scanf ("%d", &h[i]);
    
    for (int i=1; i<=t; i++) {
        
        int a, b;
        scanf ("%d%d", &a, &b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    
    visitado[p]=1;
    queue<int> fila;
    fila.push(p);
    
    while (!fila.empty()) {
        
        int x = fila.front();
        fila.pop();
        
        for (int i=0; i<(int)adj[x].size(); i++) {
            
            int y = adj[x][i];
            
            if (visitado[y]==1 || h[y]>=h[x]) continue;
            visitado[y] = 1;
            fila.push(y);
            
        }
        
    }
    
    visitado[p]=0;
    
    int ans = 0;
    
    for (int i=1; i<=n; i++) {
        
        if (visitado[i]==1) ans++;
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}
