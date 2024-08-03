#include <bits/stdc++.h>

using namespace std;

int c[100010], t[100010];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &c[i]);
    for (int i=1; i<=m; i++) scanf ("%d", &t[i]);
    long long int l=0, r = 2000000010, mid, ans;
    while (l<=r) {
        mid = (l+r)/2;
        bool check = true;
        for (int i=1; i<=n; i++) {
            int l2=1, r2=m, mid2, ans2=0;
            while (l2<=r2) {
                mid2 = (l2+r2)/2;
                long long int inf = t[mid2]-mid, sup = t[mid2]+mid;
                if (c[i]>=inf && c[i]<=sup) {
                    ans2 = mid2;
                    break;
                }
                else if (c[i]<inf) r2=mid2-1;
                else if (c[i]>sup) l2=mid2+1;
            }
            if (ans2==0) {
                check = false;
                break;
            }
        }
        if (check == true) {
            ans = mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf ("%lld\n", ans);
    return 0;
}
