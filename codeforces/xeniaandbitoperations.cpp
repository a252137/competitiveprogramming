#include <bits/stdc++.h>
#define MAXN 150010

using namespace std;

int seg[4*MAXN], vet[MAXN];

int build (int node, int l, int r, int par) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    build (2*node, l, mid, par-1);
    build (2*node+1, mid+1, r, par-1);
    if (par%2==1) seg[node] = seg[2*node]|seg[2*node+1];
    else seg[node] = seg[2*node]^seg[2*node+1];
    return seg[node];
}

int update (int node, int l, int r, int par, int pos) {
    if (l==r) return seg[node] = vet[l];
    int mid = (l+r)/2;
    if (pos<=mid) update(2*node, l, mid, par-1, pos);
    else update(2*node+1, mid+1, r, par-1, pos);
    if (par%2==1) seg[node]=seg[2*node]|seg[2*node+1];
    else seg[node]=seg[2*node]^seg[2*node+1];
    return seg[node];
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    int tam = pow(2, n);
    for (int i=1; i<=tam; i++) scanf ("%d", &vet[i]);
    build (1, 1, tam, n);
    while (m--) {
        int a, b;
        scanf ("%d%d", &a, &b);
        vet[a] = b;
        update(1, 1, tam, n, a);
        printf ("%d\n", seg[1]);
    }
    return 0;
}