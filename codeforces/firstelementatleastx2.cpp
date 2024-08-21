#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int vet[MAXN], seg[4*MAXN];

int build (int node, int l, int r) {
    if (l==r) return seg[node]=vet[l];
    int mid = (l+r)/2;
    return seg[node] = max(build(2*node, l, mid), build(2*node+1, mid+1, r));
}

int update (int node, int l, int r, int pos) {
    if (l==r) return seg[node]=vet[pos];
    int mid = (l+r)/2;
    if (pos<=mid) return seg[node] = max(update(2*node, l, mid, pos), seg[2*node+1]);
    else return seg[node] = max(seg[2*node], update(2*node+1, mid+1, r, pos));
}

int ans (int node, int l, int r, int x, int k) {
    if (seg[node]<x) return 0;
    if (l==r) {
        if (l>=k && seg[node]>=x) return l;
        else return 0;
    }
    int mid = (l+r)/2;
    int aux=0;
    if (seg[2*node]>=x && mid>=k) aux = ans(2*node, l, mid, x, k);
    if (aux==0) return ans(2*node+1, mid+1, r, x, k); 
    else return aux;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    build(1, 1, n);
    while (m--) {
        int id;
        scanf ("%d", &id);
        if (id==1) {
            int k, v;
            scanf ("%d%d", &k, &v);
            k++;
            vet[k]=v;
            update(1, 1, n, k);
        }
        else {
            int x, k;
            scanf ("%d%d", &x, &k);
            k++;
            printf ("%d\n", ans(1, 1, n, x, k)-1);
        }
    }
    return 0;
}