#include <bits/stdc++.h>

using namespace std;

int vet[110];

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        int soma = 0;
        int um = 0;
        int dois = 0;
        
        for (int i=1; i<=n; i++) {
            
            scanf ("%d", &vet[i]);
            
            soma+=vet[i];
            
            if (vet[i]==1) um++;
            else dois++;
            
        }
        
        if (soma%2==1) printf ("NO\n");
        
        else {
            
            int alice = 0, bob = 0;
            
            sort (vet+1, vet+n+1);
            reverse (vet+1, vet+n+1);
            
            for (int i=1; i<=n; i++) {
                
                if (vet[i]==2) {
                    
                    if (alice<=bob) alice+=2;
                    else bob+=2;
                    
                }
                
                else {
                    
                    if (alice<=bob) alice++;
                    else bob++;
                    
                }
                
            }
            
            if (bob==alice) printf ("YES\n");
            else printf ("NO\n");
            
        }
        
    }
    
    return 0;
    
}
