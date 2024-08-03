#include <bits/stdc++.h>

using namespace std;

int dp[4010];

int main() {
    
    int a, b, c, n;
    
    scanf ("%d%d%d%d", &n, &a, &b, &c);
    
    for (int i=1; i<=n; i++) {
        
        int op1=-n-5, op2=-n-5, op3=-n-5;
        
        if (i-a>=0) op1 = dp[i-a]+1;
        if (i-b>=0) op2 = dp[i-b]+1;
        if (i-c>=0) op3 = dp[i-c]+1;
        
        dp[i]=max(op1, max(op2, op3));
        
    }
    
    printf ("%d\n", dp[n]);
    
    return 0;
    
}
