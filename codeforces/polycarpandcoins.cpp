#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        if (n%3==0) {
            
            printf ("%d %d\n", n/3, n/3);
            
        }
        
        else {
            
            int a = (int)ceil(n/3.0);
            int b = n/3;
            
            if (a*1 + b*2 == n) printf ("%d %d\n", a, b);
            else printf ("%d %d\n", b, a);
            
        }
        
    }
    
    return 0;
    
}
