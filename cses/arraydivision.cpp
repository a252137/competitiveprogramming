#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010], n, k;
 
bool buscaB (long long int x) {
    
    int cont = 1;
    long long int atual = 0;
    
    for (int i=1; i<=n; i++) {
        
        if (atual+vet[i]<=x) atual+=vet[i];
        
        else {
            
            cont++;
            atual = vet[i];
            
        }
        
    }
    
    if (cont<=k) return true;
    else return false;
    
}
 
int main() {
    
    scanf ("%d%d", &n, &k);
    
    int maxi = 0;
    
    for (int i=1; i<=n; i++) {
        
        scanf ("%d", &vet[i]);
        maxi = max(maxi, vet[i]);
        
    }
    
    long long int l = maxi, r = 10000000000000010, mid, ans=0;
    
    while (l<=r) {
        
        mid = (l+r)/2;
        
        if (buscaB(mid)==true) {
            
            ans = mid;
            r = mid - 1;
            
        }
        
        
        else l = mid + 1;
        
    }
    
    printf ("%lld\n", ans);
    
    return 0;
    
}

