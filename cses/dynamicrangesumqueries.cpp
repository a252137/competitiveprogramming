#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

long long int vet[MAXN], seg[4*MAXN];

void build (int node, int l, int r) {
    if (l==r) {
        seg[node] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node]=seg[2*node]+seg[2*node+1];
    return;
}

long long int update (int node, int pos, long long int dif, int l, int r) {
    if (l==r) return seg[node] = vet[pos]+dif;
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = update(2*node, pos, dif, l, mid) + seg[2*node+1];
    else return seg[node] = update(2*node+1, pos, dif, mid+1, r) + seg[2*node];
}

long long int ans (int node, int lq, int rq, int l, int r) {
    if (lq<=l && rq>=r) return seg[node];
    if (lq>r || rq<l) return 0;
    int mid = (l+r)/2;
    return ans(2*node, lq, rq, l, mid)+ans(2*node+1, lq, rq, mid+1, r);
}

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    build(1, 1, n);
    while (q--) {
        long long int id, a, b;
        scanf ("%lld%lld%lld", &id, &a, &b);
        if (id==1) {
            long long int dif = b-vet[a];
            update(1, a, dif, 1, n);
            vet[a]=b;
        }
        else {
            printf ("%lld\n", ans(1, a, b, 1, n));
        }
    }
    return 0;
}