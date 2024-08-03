#include <bits/stdc++.h>

using namespace std;

int n, k, vet[500010], soma;

bool bb (int x) {
    
    soma=0;
    
    for (int i=1; i<=n; i++) {
        
        if (vet[i]>=x) soma++;
        
    }
    
    if (soma>=x) return true;
    
    else return false;
    
}

int main() {
    
    int ans=0;
    
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    int l=1, r=500010, mid;
    
    while (l<=r) {
        
        mid=(l+r)/2;
        
        if (bb(mid)==true) {
            
            ans=mid;
            l=mid+1;
            
        }
        
        else r=mid-1;
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}





