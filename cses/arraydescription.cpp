#include <bits/stdc++.h>
#define mod 1000000007
 
using namespace std;
 
int vet[100010];
long long int dp[100010][110];
//dp[i][j] é o número de possibilidades de vetores diferentes na posição i com valor j
 
int main() {
    
    int n, m;
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    if (vet[1]!=0) dp[1][vet[1]] = 1;
    
    else {
        
        for (int i=1; i<=m; i++) dp[1][i]=1;
        
    }
    
    for (int i=2; i<=n; i++) {
        
        if (vet[i]!=0) dp[i][vet[i]] = (((dp[i-1][vet[i]-1] + dp[i-1][vet[i]])%mod) + dp[i-1][vet[i]+1])%mod;
        
        else {
            
            for (int j=1; j<=m; j++) dp[i][j] = (((dp[i-1][j-1] + dp[i-1][j])%mod) + dp[i-1][j+1])%mod;
            
        }
        
    }
    
    int maxi = 0;
    
    if (vet[n]!=0) printf ("%lld\n", dp[n][vet[n]]);
    
    else {
        
        for (int i=1; i<=m; i++) maxi = ((long long int)maxi + dp[n][i])%mod;
        printf ("%lld\n", (long long int)maxi);
        
    }
    
    return 0;
    
}
