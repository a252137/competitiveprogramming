#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        if ((n/2)%2==1) {
            
            printf ("NO\n");
            continue;
            
        }
        
        printf ("YES\n");
        
        for (int i=1; i<=n/2; i++) {
            
            printf ("%d ", 2*i);
            
        }
        
        int imp = 1;
        
        for (int i=(n/2)+1; i<n; i++, imp+=2) {
            
            printf ("%d ", imp);
            
        }
        
        printf ("%d ", 2*(n/2)+((n/2)-1));
        printf ("\n");
        
    }
    
    return 0;
    
}
