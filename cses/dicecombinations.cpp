#include <bits/stdc++.h>
 
using namespace std;
 
long long int dp[1000010];
 
int main () {
    int n;
    scanf ("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    if (n<=6) {
        printf ("%lld\n", dp[n]);
        return 0;
    }
    long long int mod = 1000000007;
    for (int i=7; i<=n; i++) {
        dp[i] = (dp[i-6] + dp[i-5] + dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1])%mod;
    }
    printf ("%lld\n", dp[n]);
    return 0;
}
