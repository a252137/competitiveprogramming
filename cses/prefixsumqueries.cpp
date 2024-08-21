#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int
 
using namespace std;
 
int n;
lli vet[MAXN], sum[4*MAXN], pref[4*MAXN];
 
void build (int node, int l, int r) {
    if (l==r) {
        sum[node] = vet[l];
        pref[node] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    build (2*node, l, mid);
    build(2*node+1, mid+1, r);
    sum[node] = sum[2*node]+sum[2*node+1];
    pref[node] = max(pref[2*node], sum[2*node]+pref[2*node+1]);
    return;
}
 
void update (int node, int l, int r, int pos) {
    if (l==r) {
        sum[node] = vet[l];
        pref[node] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(2*node, l, mid, pos);
    else update(2*node+1, mid+1, r, pos);
    sum[node] = sum[2*node]+sum[2*node+1];
    pref[node] = max(pref[2*node], sum[2*node]+pref[2*node+1]);
    return;
}
 
lli ans_soma (int node, int l, int r, int lq, int rq) {
    if (lq>r ||rq<l) return 0;
    if (lq<=l && rq>=r) return sum[node];
    int mid = (l+r)/2;
    return ans_soma(2*node, l, mid, lq, rq) + ans_soma(2*node+1, mid+1, r, lq, rq);
}
 
lli ans (int node, int l, int r, int lq, int rq) {
    if (lq>r || rq<l) return 0;
    if (lq<=l && rq>=r) return pref[node];
    int mid = (l+r)/2;
    return max(ans(2*node, l, mid, lq, rq), ans_soma(1, 1, n, max(l, lq), min(mid, rq))+ans(2*node+1, mid+1, r, lq, rq));
}
 
int main () {
    int q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    build(1, 1, n);
    while (q--) {
        int id;
        scanf ("%d", &id);
        if (id==1) {
            int k;
            lli u;
            scanf ("%d%lld", &k, &u);
            vet[k]=u;
            update(1, 1, n, k);
        }
        else {
            int a, b;
            scanf ("%d%d", &a, &b);
            printf ("%lld\n", max(ans(1, 1, n, a, b), (lli)0));
        }
    }
    return 0;
}