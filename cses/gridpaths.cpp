#include <bits/stdc++.h>
#define MAXN 1010
#define mod (int)(1e9+7)

using namespace std;

long long int dp[MAXN][MAXN];

int main () {
    int n;
    scanf ("%d", &n);
    char vet[MAXN][MAXN];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf (" %c", &vet[i][j]);
        }
    }
    for (int i=n; i>=1; i--) {
        if (vet[i][n]=='*') break;
        dp[i][n]=1;
    }
    for (int j=n; j>=1; j--) {
        if (vet[n][j]=='*') break;
        dp[n][j]=1;
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=n-1; j>=1; j--) {
            long long int aux1  = 0, aux2 = 0;
            if (vet[i+1][j]=='.') aux1 = dp[i+1][j];
            if (vet[i][j+1]=='.') aux2 = dp[i][j+1];
            dp[i][j] = (aux1+aux2)%mod;
        }
    }
    if (vet[1][1]=='*') dp[1][1] = 0;
    printf ("%lld\n", dp[1][1]);
    return 0;
}