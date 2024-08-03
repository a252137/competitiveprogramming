#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int last = -1;
    int ans = 0;
    
    int n;
    scanf ("%d", &n);
    
    for (int i=1;i<=n; i++) {
        
        int x;
        scanf ("%d", &x);
        
        int y = x + 10;
        
        if (last>=x && last<=y) ans+=y-last;
        
        if (last<x) ans+=10;
        
        last = y;
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}
