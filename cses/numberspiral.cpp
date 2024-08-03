#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int x, y;
        scanf ("%d%d", &x, &y);
        
        long long int a = max(x, y);
        
        long long int base;
        
        if (a%2==0) base = a*a;
        else base = ((a-1)*(a-1))+1;
        
        long long int distX = abs(x - a);
        long long int distY = y - 1;
        
        if (a%2==0) printf ("%lld\n", base-distX-distY);
        else printf ("%lld\n", base+distX+distY);
        
    }
     
    return 0;
    
}
