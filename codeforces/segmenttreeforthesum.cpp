#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

long long int vet[MAXN], seg[4*MAXN];

long long int build (int node, int l, int r) {
    if (l==r) return seg[node]=vet[l];
    int mid = (l+r)/2;
    return seg[node] = build(2*node+1, l, mid)+build(2*node+2, mid+1, r);
}

long long int update (int node, int pos, int l, int r) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = update(2*node+1, pos, l, mid) + seg[2*node+2];
    else return seg[node] = seg[2*node+1] + update(2*node+2, pos, mid+1, r);
}

long long int ans (int node, int l, int r, int lq, int rq) {
    if (lq<=l && rq>=r) return seg[node];
    if (lq>r || rq<l) return 0;
    int mid = (l+r)/2;
    return ans(2*node+1, l, mid, lq, rq)+ans(2*node+2, mid+1, r, lq, rq);
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf ("%lld", &vet[i]);
    build(0, 0, n-1);
    while (m--) {
        int id;
        scanf ("%d", &id);
        if (id==1) {
            int ind;
            long long int v;
            scanf ("%d%lld", &ind, &v);
            vet[ind]=v;
            update(0, ind, 0, n-1);
        }
        else {
            int a, b;
            scanf ("%d%d", &a, &b);
            printf ("%lld\n", ans(0, 0,  n-1, a, b-1));
        }
    }
    return 0;
}