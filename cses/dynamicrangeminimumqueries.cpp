#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int vet[MAXN], seg[4*MAXN];

int build(int node, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    return seg[node] = min(build(2*node, l ,mid), build(2*node+1, mid+1, r));
}

int update (int node, int pos, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = min(update(2*node, pos, l, mid), seg[2*node+1]);
    else return seg[node] = min(seg[2*node], update(2*node+1, pos, mid+1, r));
}

int ans (int node, int lq, int rq, int l, int r) {
    if (lq<=l && rq>=r) return seg[node];
    if (lq>r || rq<l) return INT_MAX;
    int mid = (l+r)/2;
    return min(ans(2*node, lq, rq, l, mid), ans(2*node+1, lq, rq, mid+1, r));
}

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    build(1, 1, n);
    while (q--) {
        int id, a, b;
        scanf ("%d%d%d", &id, &a, &b);
        if (id == 1) {
            vet[a]=b;
            update(1, a, 1, n);
        }
        else {
            printf ("%d\n", ans(1, a, b, 1, n));
        }
    }
    return 0;
}