#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    long long int n;
    scanf ("%lld", &n);
    
    printf ("%lld ", n);
    
    while (n!=1) {
        
        if (n%2==0) n = n/2;
        else n = (3*n) + 1;
        
        printf ("%lld ", n);
        
    }
    
    printf ("\n");
    
    return 0;
    
}
