#include <bits/stdc++.h>
#define MAXN 100010
#define lli long long int

lli seg[4*MAXN], v[MAXN];

using namespace std;

lli build (int node, int l, int r) {
    if (l==r) return seg[node] = v[l];
    int mid = (l+r)/2;
    return seg[node] = __gcd(build(2*node, l, mid), build(2*node+1, mid+1, r));
}

lli ans (int node, int l, int r, int li, int ri) {
    if (l>ri || r<li) {
        return -1;
    }
    if (l==r) {
        return seg[node];
    }
    if (l>=li && r<=ri) {
        return seg[node];
    }
    int mid = (l+r)/2;
    lli ans1 = ans(2*node, l, mid, li, ri), ans2 = ans(2*node+1, mid+1, r, li, ri);
    if (ans1 == -1 && ans2 == -1) {
        return -1;
    }
    if (ans1 == -1) {
        return ans2;
    }
    if (ans2 == -1) {
        return ans1;
    }
    return __gcd(ans1, ans2);
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%lld", &v[i]);
    build(1, 1, n);
    int l=1;
    int resp = n+1;
    for (int r=1; r<=n; r++) {
        lli mdc = ans(1, 1, n, l, r);
        if (mdc != 1) continue;
        while (ans(1, 1, n, l+1, r) == 1 && l<r) {
            l++;
        }
        resp = min(resp, r-l+1);
    }
    if (resp == n+1) printf ("-1\n");
    else printf ("%d\n", resp);
    return 0;
}