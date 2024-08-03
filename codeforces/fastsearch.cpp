#include <bits/stdc++.h>

using namespace std;

int vet[100010];

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort(vet+1, vet+n+1);
    int k;
    scanf ("%d", &k);
    for (int i=1; i<=k; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        int l=1, r=n, mid, ans1 = 0;
        while (l<=r) {
            mid = (l+r)/2;
            if (vet[mid]>=a) {
                ans1 = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        l = 1;
        r = n;
        int ans2 = 0;
        while (l<=r) {
            mid = (l+r)/2;
            if (vet[mid]<=b) {
                ans2 = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if (ans1 == 0 || ans2 == 0) printf ("0 ");
        else printf ("%d ", ans2-ans1+1);
    }
    printf ("\n");
    return 0;
}
