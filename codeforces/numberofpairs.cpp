#include <bits/stdc++.h>

using namespace std;

int vet[200010];

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n, a, b;
        scanf ("%d%d%d", &n, &a, &b);
        
        for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
        
        sort (vet+1, vet+n+1);
        
        long long int ans = 0;
        
        for (int i=1; i<n; i++) {
            
            int l = i+1, r=n, mid;
            int resp1 = 0, resp2 = 0;
            
            //ultima posição do vetor q vet[i]+vet[mid]>=a
            
            while (l<=r) {
                
                mid = (l+r)/2;
                
                if (vet[mid]+vet[i]>=a) {
                    
                    resp1 = mid;
                    r = mid - 1;
                    
                }
                
                else l = mid + 1;
                
            }
            
            l = i+1;
            r = n;
            
            //ultima posição em que vet[i]+vet[mid]<=b
            
            while (l<=r) {
                
                mid = (l+r)/2;
                
                if (vet[mid]+vet[i]<=b) {
                    
                    resp2 = mid;
                    l = mid + 1;
                    
                }
                
                else r = mid - 1;
                
            }
            
            if (resp2==0 || resp1==0) continue;
            
            ans += (resp2-resp1+1);
            
        }
        
        printf ("%lld\n", ans);
        
    }
    
    return 0;
    
}
