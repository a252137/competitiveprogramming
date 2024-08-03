#include <bits/stdc++.h>

using namespace std;

int n, m;
int pai[100010];
int tam[100010];

int find (int a) {
    
    if (a==pai[a]) return a;
    
    return pai[a]=find(pai[a]);
    
}

void join (int a, int b) {
    
    a=find(a);
    b=find(b);
    
    if (tam[a]<=tam[b]) {
        
        pai[a]=b;
        tam[b]+=tam[a];
        
    }
    
    else {
        
        pai[b]=a;
        tam[a]+=tam[b];
        
    }
    
}

int main () {
    
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        
        pai[i]=i;
        tam[i]=1;
        
    }
    
    for (int i=1; i<=m; i++) {
        
        char c;
        int a, b;
        scanf (" %c %d %d", &c, &a, &b);
        
        if (c=='F') join(a, b);
        
        else {
            
            a=find(a);
            b=find(b);
            
            if (a==b) printf ("S\n");
            else printf ("N\n");
            
        }
        
    }
    
    return 0;
    
}
