#include <bits/stdc++.h>

using namespace std;

int vet[50010];
int soma[50010];

int main() {
    
    int n;
    scanf ("%d", &n);
    
    int ans = -1000000000;
    
    for (int i=1; i<=n; i++) {
        
        scanf ("%d", &vet[i]);
        ans = max (ans, vet[i]);
        
    }
    
    int mini = 1000000000;
    
    for (int i=1; i<=n; i++) soma[i]=soma[i-1]+vet[i];
    
    for (int i=1; i<=n; i++) {
        
        mini = min(soma[i-1], mini);
        ans = max (ans, soma[i]-mini);
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}
