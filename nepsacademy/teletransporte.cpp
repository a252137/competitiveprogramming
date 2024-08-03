#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101010];
int camada[101010];
vector<int> fila;

int main() {
    
    int n, k, m, a;
    
    scanf ("%d%d%d", &n, &k, &m);
    
    for (int i=1; i<=m; i++) {
        
        for (int j=1; j<=k; j++) {
            
            scanf ("%d", &a);
            
            adj[n+i].push_back(a);
            adj[a].push_back(n+i);
            
        }
        
    }
    
    for (int i=1; i<=n+m+1; i++) {
        
        camada[i]=-1;
        
    }
    
    camada[1]=0;
    fila.push_back(1);
    
    int pont=0;
    
    while (pont<(int)fila.size()) {
        
        int atual=fila[pont];
        
        pont++;
        
        for (int i=0; i<(int)adj[atual].size(); i++) {
            
            int vizinho=adj[atual][i];
            
            if (camada[vizinho] == -1) {
                
                camada[vizinho]=camada[atual]+1;
                
                fila.push_back(vizinho);
                
            }
            
        }
        
    }
    
    if (camada[n]==-1) {
        
        printf ("-1\n");
        
        return 0;
        
    }
    
    printf ("%d\n", (camada[n]/2)+1);
    
    return 0;
    
}




