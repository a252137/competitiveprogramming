#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int vet[MAXN], seg[4*MAXN];

int build (int node, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    return seg[node] = min(build(2*node+1, l, mid), build(2*node+2, mid+1, r));
}

int update (int node, int pos, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = min(update(2*node+1, pos, l ,mid), seg[2*node+2]);
    else return seg[node] = min(seg[2*node+1], update(2*node+2, pos, mid+1, r));
}

int ans (int node, int lq, int rq, int l, int r) {
    if (lq<=l && rq>=r) return seg[node];
    if (lq>r || rq<l) return INT_MAX;
    int mid = (l+r)/2;
    return min(ans(2*node+1, lq, rq, l, mid), ans(2*node+2, lq, rq, mid+1, r));
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf ("%d", &vet[i]);
    build(0, 0, n-1);
    while (m--) {
        int id, a, b;
        scanf ("%d%d%d", &id, &a, &b);
        if (id==1) {
            vet[a]=b;
            update(0, a, 0, n-1);
        }
        else {
            printf ("%d\n", ans(0, a, b-1, 0, n-1));
        }
    }
    return 0;
}