#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int n, k, vet[150010];
    
    scanf ("%d%d", &n, &k);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    int atual=0;
    
    for (int i=1; i<=k; i++) atual+=vet[i];
    
    int ans=atual, pos=1;
    
    for (int i=k+1; i<=n; i++) {
        
        atual-=vet[i-k];
        
        atual+=vet[i];
        
        if (ans<=atual) continue;
        
        ans=atual;
        
        pos=i-k+1;
        
    }
    
    printf ("%d\n", pos);
    
    return 0;
    
}
