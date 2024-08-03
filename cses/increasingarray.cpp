#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    
    int n;
    scanf ("%d", &n);
    
    long long int ans = 0;
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    for (int i=2; i<=n; i++) {
        
        if (vet[i]<vet[i-1]) {
            
            ans += vet[i-1]-vet[i];
            vet[i]=vet[i-1];
            
        }
        
    }
    
    printf ("%lld\n", ans);
    
    return 0;
    
}
