#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    
    long long int n;
    scanf ("%lld", &n);
    
    printf ("0\n");
    
    long long int cont = 1;
    
    if (n>=2) printf ("6\n");
    
    for (long long int i=3; i<=n; i++) {
        
        long long int a = ((i*i) * ((i*i)-1))/2;
        
        a = a - (8LL*cont);
        
        printf ("%lld\n", a);
        
        cont += i - 1;
        
    }
    
    return 0;
    
}
