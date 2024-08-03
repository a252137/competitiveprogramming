#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        long long int n, m, k, ans=0;
        scanf ("%lld%lld%lld", &n, &m, &k);
        
        for (int i=1; i<=n-1; i++) ans++;
        
        for (int i=1; i<=m-1; i++) ans+=n;
        
        if (ans==k) printf ("YES\n");
        else printf ("NO\n");
        
    }
    
    return 0;
}
