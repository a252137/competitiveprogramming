#include <bits/stdc++.h>

using namespace std;

int faixa[100010];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<n; i++) scanf ("%d", &faixa[i]);
    int prem[100010];
    for (int i=1; i<=n; i++) scanf ("%d", &prem[i]);
    for (int i=1; i<=m; i++) {
        int o;
        scanf ("%d", &o);
        if (o>=faixa[n-1]) {
            printf ("%d ", prem[n]);
            continue;
        }
        int l = 1, r = n-1, mid, ans = 0;
        while (l<=r) {
            mid = (l+r)/2;
            if (o>=faixa[mid]) {
                l = mid + 1;
                ans = mid;
            }
            if (o<faixa[mid]) r = mid - 1;
        }
        printf ("%d ", prem[ans+1]);
    }
    printf ("\n");
    return 0;
}