#include <bits/stdc++.h>

using namespace std;

int vet[100010];

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=2; i<=n; i++) vet[i] = vet[i] + vet[i-1];
    int m;
    scanf ("%d", &m);
    for (int i=1; i<=m; i++) {
        int x;
        scanf ("%d", &x);
        int l=1, r=n, mid, ans = 0;
        while (l<=r) {
            mid = (l+r)/2;
            if (x<=vet[mid]) {
                ans = mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
