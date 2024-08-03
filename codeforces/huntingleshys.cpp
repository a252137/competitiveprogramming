#include <bits/stdc++.h>

using namespace std;

int n, m;
int poder[100010];
int pai[100010];
int mini[100010];

int find (int x) {
    
    if (x==pai[x]) {
        
        mini[x]=poder[x];
        return x;
        
    }
    
    int y = find(pai[x]);
    
    mini[x]=min(mini[x], mini[pai[x]]);
    
    return pai[x]=y;
    
}

void join (int a, int b) {
    
    pai[b]=a;
    mini[b]=min(mini[a], poder[b]);
    
}

int main () {
    
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        
        pai[i]=i;
        scanf ("%d", &poder[i]);
        mini[i]=poder[i];
        
    }
    
    for (int i=1; i<=m; i++) {
        
        char c;
        scanf (" %c", &c);
        
        if (c=='+') {
            
            int a, b;
            scanf ("%d%d", &a, &b);
            join(a, b);
            
        }
        
        else {
            
            int a;
            scanf ("%d", &a);
            
            find(a);
            
            printf ("%d\n", mini[a]);
            
        }
        
    }
    
    return 0;
    
}
