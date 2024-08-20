#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int vet[MAXN], seg[4*MAXN];

int build (int node, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    return seg[node] = build(2*node, l, mid) + build(2*node+1, mid+1, r);
}

int ans (int node, int l, int r, int k) {
    if (l==r) return l;
    int mid = (l+r)/2;
    if (seg[2*node]>=k) return ans(2*node, l, mid, k);
    else return ans(2*node+1, mid+1, r, k-seg[2*node]);
}

int update (int node, int l, int r, int x) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    if (x<=mid) return seg[node] = seg[2*node+1] + update(2*node, l, mid, x);
    else return seg[node] = seg[2*node] + update(2*node+1, mid+1, r, x);
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    build (1, 1, n);
    while (m--) {
        int id, x;
        scanf ("%d%d", &id, &x);
        if (id == 2) {
            x++;
            printf ("%d\n", ans(1, 1, n, x)-1);
        }
        else {
            x++;
            vet[x] = vet[x]^1;
            update (1, 1, n, x);
        }
    }
    return 0;
}