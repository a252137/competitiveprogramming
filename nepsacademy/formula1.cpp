#include <bits/stdc++.h>

using namespace std;

int cont, sistema[110][110], resultado[110][110], ponto[110][110], maximo[110];

int main() {
    
    int g, p, j, s, k, i, z;
    
    while (true) {
        
        scanf ("%d%d", &g, &p);
        
        if (g == 0 && p == 0) return 0;
        
        for (i = 1 ; i <= g ; i++) {
        
            for (j = 1 ; j <= p ; j++) {
                
                scanf ("%d", &resultado[i][j]);
                
            }
            
        }
        
        scanf ("%d", &s);
        
        for (i = 1 ; i <= s ; i++) {
            
            scanf ("%d", &k);
            
            for (j = 1 ; j <= k ; j++) {
                
                scanf ("%d", &sistema[i][j]);
            
            }
            
        }
        
        for (i = 1 ; i <= s ; i++) {
            
            for (j = 1 ; j <= p ; j++) {
                
                for (z = 1 ; z <= g ; z++){
                    
                    ponto[i][j] += sistema[i][resultado[z][j]];
                    
                }
                
                maximo[i] = max(ponto[i][j] , maximo[i]);
                
            }
        
        }    
         
        for (j = 1 ; j <= s ; j++){    
            
            for (i = 1 ; i <= p ; i++) {
            
                if (ponto[j][i] == maximo[j]) {
                
                    printf ("%d ", i);
                
                }
            
                ponto[j][i] = 0;
            
           }
           
           printf ("\n");
           
           maximo[j] = 0;
            
        }
        
        for (i = 1 ; i <= s ; i++) {
            
            for (j = 1 ; j <= p ; j++) {
                
                sistema[i][j] = 0;
            
            }
            
        }
        
    }
    
    
    return 0;
}











