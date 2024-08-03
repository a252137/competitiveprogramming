#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, ans=0;
    
    set<int> s;
    
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) {
        
        int x;
        scanf ("%d", &x);
        
        if (s.find(x)==s.end()) {
            
            s.insert(x);
            ans=ans+2;
            
        }
        
        else {
            
            s.erase(x);
            
        }
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}
