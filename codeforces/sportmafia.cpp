#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long int n, k;
    scanf ("%lld%lld", &n, &k);
    
    long long int l=0, r=n, mid, ans=0;
    
    while (l<=r) {
        
        mid = (l+r)/2;
        long long int a = n-mid;
        long long int b = (1+a)*(a/2.0);
        
        if (b-mid==k) {
            
            ans=mid;
            break;
            
        }
        
        else if (b-mid<k) r=mid-1;
        else l=mid+1;
        
    }
    
    printf ("%lld\n", ans);
    
    return 0;
    
}
