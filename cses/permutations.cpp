#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    
    int n;
    scanf ("%d", &n);
    
    if (n==2 || n==3) {
        
        printf ("NO SOLUTION\n");
        return 0;
        
    }
    
    for (int i=2; i<=n; i=i+2) printf ("%d ", i);
    
    for (int i=1; i<=n; i=i+2) printf ("%d ", i);
    
    printf ("\n");
     
    return 0;
    
}
