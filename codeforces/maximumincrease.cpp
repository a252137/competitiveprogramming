#include <bits/stdc++.h>

using namespace std;

int vet[100010];

int main() {
    
    int n;
    scanf ("%d", &n);
    
    int ans = 1;
    int atual = 1;
    int ultimo;
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    ultimo = vet[1];
    
    for (int i=2; i<=n; i++) {
        
        if (vet[i]>ultimo) {
            
            atual++;
            
        }
        
        else {
            
            ans = max(ans, atual);
            atual = 1;
            
        }
        
        ultimo = vet[i];
        
    }
    
    ans = max(ans, atual);
    
    printf ("%d\n", ans);
    
    return 0;
    
}
