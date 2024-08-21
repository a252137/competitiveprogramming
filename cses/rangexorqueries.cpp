#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int

using namespace std;

lli vet[MAXN], seg[4*MAXN];

lli build (int node, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    return seg[node] = build(2*node, l, mid)^build(2*node+1, mid+1, r);
}

lli ans (int node, int l, int r, int lq, int rq) {
    if (lq<=l && rq>=r) return seg[node];
    if (lq>r || rq<l) return 0;
    int mid = (l+r)/2;
    return ans(2*node, l, mid, lq, rq)^ans(2*node+1, mid+1, r, lq, rq);
}

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    build(1, 1, n);
    while (q--) {
        int a, b;
        scanf ("%d%d", &a, &b);
        printf ("%lld\n", ans(1, 1, n, a, b));
    }
    return 0;
}