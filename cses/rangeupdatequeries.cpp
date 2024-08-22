#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int

using namespace std;

lli vet[MAXN], seg[4*MAXN];

void update (int node, int l, int r, int a, int b, lli u) {
    if (a<=l && b>=r) {
        seg[node]+=u;
        return;
    }
    if (b<l || a>r) return;
    int mid = (l+r)/2;
    update(2*node, l, mid, a, b, u);
    update(2*node+1, mid+1, r, a, b, u);
    return;
}

lli ans (int node, int l, int r, int k) {
    if (l==r) return seg[node];
    int mid = (l+r)/2;
    if (k<=mid) return seg[node]+ans(2*node, l, mid, k);
    else return seg[node]+ans(2*node+1, mid+1, r, k);
}

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    while (q--) {
        int id;
        scanf ("%d", &id);
        if (id == 1) {
            int a, b;
            lli u;
            scanf ("%d%d%lld", &a, &b, &u);
            update (1, 1, n, a, b, u);
        }
        else {
            int k;
            scanf ("%d", &k);
            printf ("%lld\n", vet[k]+ans (1, 1, n, k));
        }
    }
    return 0;
}