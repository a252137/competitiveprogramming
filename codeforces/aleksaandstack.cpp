#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int ans[200010];
    ans[1]=1;
    for (int i=2; i<=200000; i++) ans[i] = ans[i-1] + 2;
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        int n;
        scanf ("%d", &n);
        for (int i=1; i<=n; i++) printf ("%d ", ans[i]);
        printf ("\n");
    }
    
    
    return 0;
}
