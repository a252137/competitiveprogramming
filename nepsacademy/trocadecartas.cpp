#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    set<int> s;
    set<int> v;
    int ans1=0, ans2=0;
    
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        
        int x;
        scanf ("%d", &x);
        s.insert(x);
        
    }
    
    for (int i=1; i<=m; i++) {
        
        int x;
        scanf ("%d", &x);
        v.insert(x);
        
    }
    
    for (set<int>::iterator it = s.begin(); it!=s.end(); ++it) {
        
        int x=*it;
        
        if (v.find(x)==v.end()) ans1++;
        
    }
    
    for (set<int>::iterator it = v.begin(); it!=v.end(); ++it) {
        
        int x=*it;
        
        if (s.find(x)==s.end()) ans2++;
        
    }
    
    printf ("%d\n", min(ans1, ans2));
    
    return 0;
    
}






