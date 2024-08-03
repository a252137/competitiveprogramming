#include <bits/stdc++.h>

using namespace std;

int vet1[200010], vet2[200010];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &vet1[i]);
    for (int i=1; i<=m; i++) scanf ("%d", &vet2[i]);
    sort (vet1+1, vet1+n+1);
    for (int i=1; i<=m; i++) {
        int x = vet2[i];
        int l=1, r=n, mid, ans=0;
        while (l<=r) {
            mid = (l+r)/2;
            if (vet1[mid]<=x) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        printf ("%d ", ans);
    }
    printf ("\n");
    return 0;
}
