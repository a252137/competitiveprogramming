#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n, m;
        scanf ("%d%d", &n, &m);
        
        char vet[25][25];
        
        for (int i=1; i<=n; i++) {
            
            for (int j=1; j<=m; j++) {
                
                scanf (" %c", &vet[i][j]);
                
            }
            
        }
        
        int v = 0, ii = 0, k = 0, a = 0;
        
        for (int j=1; j<=m; j++) {
            
            for (int i=1; i<=n; i++) {
                
                if (vet[i][j] == 'v' && v==0) v = j;
                else if (vet[i][j] == 'i' && (v!=0 && (v!=j && ii==0))) ii = j;
                else if (vet[i][j] == 'k' && (v!=0 && (ii!=0 && (ii!=j && k==0)))) k = j;
                else if (vet[i][j] == 'a' && (v!=0 && (ii!=0 && (k!=0 && (k!=j && a==0))))) a = j;
                
            }
            
        }
        
        if (v!=0 && (ii!=0 && (k!=0 && (a!=0)))) printf ("YES\n");
        else printf ("NO\n");
        
    }
    
    return 0;
    
}
