#include <bits/stdc++.h>
#define MAXN 110
#define MAXX 1000010

using namespace std;

int vet[MAXN];
int dp[MAXX];
int n;

int rec (int k) {
    //printf ("%d\n", k);
    if (k==0) return 0;
    if (dp[k]!=1000000000) return dp[k];
    for (int i=1; i<=n; i++) {
        if (vet[i]>k) break;;
        int aux = rec(k-vet[i]);
        if (aux != -1) dp[k] = min(dp[k], aux+1);
    }
    if (dp[k]==1000000000) return dp[k] = -1;
    return dp[k];
}

int main () {
    int x;
    scanf ("%d%d", &n, &x);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort(vet+1, vet+n+1);
    for (int i=1; i<=x; i++) dp[i] = 1000000000;
    for (int i=1; i<=n; i++) dp[vet[i]] = 1;
    printf ("%d\n", rec(x));
    return 0;
}