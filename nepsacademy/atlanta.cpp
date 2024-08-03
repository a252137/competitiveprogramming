#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a, b;
    scanf ("%d%d", &a, &b);
    
    int maxi = a+b;
    
    for (int i=1; i<=maxi; i++) {
        
        int l=1, r=maxi, mid;
        
        while (l<=r) {
            
            mid = (l+r)/2;
            
            if (i*mid==maxi && ((i==(a-2*mid+4)/2) || (mid==(a-2*i+4)/2))) {
                
                printf ("%d %d\n", min(i, mid), max(i, mid));
                return 0;
                
            }
            
            else if (i*mid==maxi) break;
            
            else if (i*mid<maxi) l = mid + 1;
            
            else if (i*mid>maxi) r = mid - 1;
            
        }
        
    }
    
    printf ("-1 -1\n");
    
    return 0;
    
}
