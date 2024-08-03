#include <bits/stdc++.h>

using namespace std;

int dp[25][25];
//guarda o menor resultado dos índices i a j
char s[25];

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        for (int i=1; i<=n; i++) scanf (" %c", &s[i]);
        if (n==2) {
            int ans = (s[1]-'0')*10 + (s[2]-'0');
            printf ("%d\n", ans);
            continue;
        }
        if (n==3) {
            int ans1 = ((s[1]-'0')*10 + (s[2]-'0')) * (s[3]-'0');
            int ans2 = ((s[1]-'0')*10 + (s[2]-'0')) + (s[3]-'0');
            int ans3 = ((s[2]-'0')*10 + (s[3]-'0')) * (s[1]-'0');
            int ans4 = ((s[2]-'0')*10 + (s[3]-'0')) + (s[1]-'0');
            printf ("%d\n", min(ans1, min(ans2, min(ans3, ans4))));
            continue;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) dp[i][j] = 1000000000;
        }
        for (int i=1; i<=n; i++) {
            dp[i][i] = s[i]-'0';
        }
        for (int j=2; j<=n; j++) {
            for (int i=1; i<=n; i++) {
                //j é o tamanho da subsequência analisada
                if (i+j-1>n) break;
                for (int k=i; k<=i+j-2; k++) {
                    dp[i][i+j-1] = min(dp[i][j+i-1], min(dp[i][k]*dp[k+1][i+j-1], dp[i][k]+dp[k+1][i+j-1]));
                }
            }
        }
        int ans = 1000000000;
        for (int i=1; i<=n-1; i++) {
            int prov;
            int at = s[i] - '0';
            at = at*10;
            int next = s[i+1] - '0';
            at += next;
            if (i==1) prov = min(at+dp[3][n], at*dp[3][n]);
            else if (i==n-1) prov = min(at+dp[1][n-2], at*dp[1][n-2]);
            else {
                prov = min(dp[1][i-1]*at*dp[i+2][n], min(dp[1][i-1]+at+dp[i+2][n], min(dp[1][i-1]*at+dp[i+2][n], dp[1][i-1]+at*dp[i+2][n])));
            }
            ans = min(ans, prov);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
