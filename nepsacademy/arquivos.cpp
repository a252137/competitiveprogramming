#include <bits/stdc++.h>

using namespace std;

int vet[1000010];

int main () {
    
    int n, k, ans=0;
    scanf ("%d%d", &n, &k);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    sort (vet+1, vet+n+1);
    
    int l=1, r=n;
    
    while (l<=r) {
        
        if (vet[r]==k || vet[l]+vet[r]>k) {
            
            ans++;
            r--;
            
        }
        
        else if (vet[l]+vet[r]<=k) {
            
            ans++;
            r--;
            l++;
            
        }
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}
