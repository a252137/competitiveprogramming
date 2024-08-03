#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    long long int ans = -1000000010, cur = 0;
    for (int i=1; i<=n; i++) {
        cur += vet[i];
        ans = max(ans, cur);
        if (cur<0) cur = 0;
    }
    printf ("%lld\n", ans);
    return 0;
}
