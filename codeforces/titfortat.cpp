#include <iostream>

using namespace std;

int main() {
    
    int t, vet[110];
    scanf ("%d", &t);
    
    while (t--) {
        
        int n, k;
        scanf ("%d%d", &n, &k);
        
        for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
        
        for (int i=1; i<=n; i++) {
            
            if (k>=vet[i]) {
                
                int aux=vet[i];
                vet[i]=0;
                k=k-aux;
                vet[n]=vet[n]+aux;
                
            }
            
            else {
                
                vet[i]=vet[i]-k;
                vet[n]=vet[n]+k;
                k=0;
                
            }
        
        }
        
        for (int i=1; i<=n; i++) printf ("%d ", vet[i]);
        
        printf ("\n");
        
    }
    
    return 0;
    
}
