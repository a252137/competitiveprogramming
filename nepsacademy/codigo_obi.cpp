#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int n;
    // n = qtd de inteiros que vamos receber
    
    scanf ("%d", &n);
    
    int vet[10010];
    
    for (int i=1; i<=n; i++) {
        
        scanf ("%d", &vet[i]);
        
    }
    
    int resp = 0;
    
    for (int i=1; i<=n-2; i++) {
        
        if (vet[i]==1 && (vet[i+1]==0 && vet[i+2]==0)) resp++;
        
    }
    
    printf ("%d\n", resp);
    
    return 0;
    
}
