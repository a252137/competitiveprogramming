#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int

using namespace std;

lli vet[MAXN], sum[4*MAXN], seg[4*MAXN], pref[4*MAXN], suf[4*MAXN];

void build (int node, int l, int r) {
    if (l==r) {
        sum[node]=vet[l];
        seg[node]=vet[l];
        pref[node]=vet[l];
        suf[node]=vet[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    sum[node] = sum[2*node]+sum[2*node+1];
    pref[node] = max(pref[2*node], sum[2*node]+pref[2*node+1]);
    suf[node] = max(suf[2*node+1], sum[2*node+1]+suf[2*node]);
    seg[node] = max(suf[2*node]+pref[2*node+1], max(seg[2*node], seg[2*node+1]));
    return;
}

void update (int node, int l, int r, int pos) {
    if (l==r) {
        seg[node] = vet[pos];
        sum[node] = vet[pos];
        pref[node] = vet[pos];
        suf[node] = vet[pos];
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(2*node, l, mid, pos);
    else update(2*node+1, mid+1, r, pos);
    sum[node] = sum[2*node]+sum[2*node+1];
    pref[node] = max(pref[2*node], sum[2*node]+pref[2*node+1]);
    suf[node] = max(suf[2*node+1], sum[2*node+1]+suf[2*node]);
    seg[node] = max(suf[2*node]+pref[2*node+1], max(seg[2*node], seg[2*node+1]));
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    build(1, 1, n);
    while (m--) {
        int k;
        lli x;
        scanf ("%d%lld", &k, &x);
        vet[k]=x;
        update(1, 1, n, k);
        printf ("%lld\n", max(seg[1], (lli)0));
    }
    return 0;
}