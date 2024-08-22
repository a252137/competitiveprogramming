#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int vet[MAXN], seg[4*MAXN];

int build (int node, int l, int r) {
    if (l==r) return seg[node]=vet[l];
    int mid = (l+r)/2;
    return seg[node] = max(build(2*node, l, mid), build(2*node+1, mid+1, r));
}

int ans (int node, int l, int r, int x) {
    if (seg[node]<x) return 0;
    if (l==r) return l;
    int mid = (l+r)/2;
    if (seg[2*node]>=x) return ans(2*node, l, mid, x);
    else return ans(2*node+1, mid+1, r, x);
}

int update (int node, int l, int r, int pos) {
    if (l==r) return seg[node] = vet[pos];
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = max(update(2*node, l, mid, pos), seg[2*node+1]);
    else return seg[node] = max(seg[2*node], update(2*node+1, mid+1, r, pos));
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    build(1, 1, n);
    while (m--) {
        int x;
        scanf ("%d", &x);
        int y = ans (1, 1, n, x);
        printf ("%d ", y);
        if (y!=0) {
            vet[y]-=x;
            update(1, 1, n, y);
        }
    }
    printf ("\n");
    return 0;
}