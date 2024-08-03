#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        bool check = false;
        
        for (int i=1; i<=n; i++) {
            
            int x;
            scanf ("%d", &x);
            int y = sqrt(x);
            if (y*y!=x) check = true;
            
        }
        
        if (check==true) printf ("YES\n");
        else printf ("NO\n");
        
    }
    
    return 0;
    
}
