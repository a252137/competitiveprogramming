#include <bits/stdc++.h>

const int maxn=1000010;

using namespace std;

/* dp[i] é o maior valor que consigo roubar 
começando a tirar da joia i
*/

int n, vet[maxn], dp[maxn], ans, maximo[maxn];

int main() {
    
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    dp[1]=vet[1];
    maximo[1]=vet[1];
    
    dp[2]=vet[2];
    maximo[2]=max(vet[1], vet[2]);
    
    dp[3]=vet[3];
    maximo[3]=max(maximo[2], vet[3]);
    
    ans=max(ans, maximo[3]);
    
    int anterior=maximo[3];
    
    for (int i=4; i<=n; i++) {
        
        dp[i]=vet[i]+maximo[i-3];
        
        maximo[i]=vet[i]+maximo[i-3];
        
        if (anterior>maximo[i]) {
            
            maximo[i]=anterior;
            
        }
        
        else {
            
            anterior=maximo[i];
            
        }
        
        ans=max(dp[i], ans);
        
    }
    
    printf ("%d\n", ans);
    
    return 0;
    
}








