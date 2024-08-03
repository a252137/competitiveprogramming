#include <bits/stdc++.h>

using namespace std;

long long int vet[100010];

int main() {
    int n, k;
    scanf ("%d%d", &n, &k);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    for (int i=1; i<=k; i++) {
        long long int x;
        scanf ("%lld", &x);
        int ans = n+1;
        int l = 1, r = n, mid;
        while (l<=r) {
            mid = (l+r)/2;
            if (vet[mid]<x) l = mid + 1;
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
