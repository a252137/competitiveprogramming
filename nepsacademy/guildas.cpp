#include <bits/stdc++.h>

using namespace std;

int n, m;
int tam[100010];
int pai[100010];
int poder[100010];

int find (int x) {
    
    if (x==pai[x]) return x;
    
    return pai[x] = find (pai[x]);
    
}

void join (int a, int b) {
    
    a = find(a);
    b = find(b);
    
    if (tam[a]>tam[b]) swap (a, b);
    
    pai[a]=b;
    poder[b]+=poder[a];
    tam[b]+=tam[a];
    
}

int main() {
    
    while (true) {
        
        int ans=0;
        
        scanf ("%d%d", &n, &m);
        
        if (n==0 && m==0) return 0;
        
        for (int i=1; i<=n; i++) {
            
            scanf ("%d", &poder[i]);
            pai[i]=i;
            tam[i]=1;
            
        }
        
        for (int i=1; i<=m; i++) {
            
            int a, b, c;
            scanf ("%d%d%d", &c, &a, &b);
            
            if (c==1) {
                
                join(a,b);
                
            }
            
            else {
                
                a = find(a);
                b = find(b);
                
                if (a==find(1)) {
                    
                    if (poder[a]>poder[b]) ans++;
                    
                }
                
                if (b==find(1)) {
                    
                    if (poder[a]<poder[b]) ans++;
                    
                }
                
            }
            
        }
        
        printf ("%d\n", ans);
        
    }
    
    return 0;
    
}
