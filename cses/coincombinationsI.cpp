#include <bits/stdc++.h>
#define MAXN 110
#define MAXX 1000010
#define MOD 1000000007

using namespace std;

int vet[MAXN], n;
long long int dp[MAXX];

long long int rec (int k) {
    if (k==0) return 1;
    if (dp[k]!=1000000000) return dp[k];
    for (int i=1; i<=n; i++) {
        if (vet[i]>k) break;
        long long int aux = rec(k-vet[i]);
        if (aux != -1) {
            if (dp[k]==1000000000) dp[k] = 0;
            dp[k] = (dp[k]+aux)%MOD;
        }
    }
    if (dp[k]==1000000000) return dp[k]=0;
    else return dp[k];
}

int main () {
    int x;
    scanf ("%d%d", &n, &x);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort (vet+1, vet+n+1);
    for (int i=1; i<=x; i++) dp[i] = 1000000000;
    printf ("%lld\n", rec(x));
    return 0;
}