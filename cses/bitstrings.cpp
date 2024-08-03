#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    
    int n;
    scanf ("%d", &n);
    
    long long int ans = 1;
    
    for (int i=1; i<=n; i++) {
        
        ans = ( ans * 2 ) % 1000000007;
        
    }
    
    printf ("%lld\n", ans);
    
    return 0;
    
}
