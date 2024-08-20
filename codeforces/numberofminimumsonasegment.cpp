#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

struct node{
    int mini;
    int cont;
};

node seg[4*MAXN];
int vet[MAXN];
node aux;

void build (int no, int l, int r) {
    if (l==r) {
        seg[no].mini = vet[l];
        seg[no].cont = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*no+1, l, mid);
    build(2*no+2, mid+1, r);
    if (seg[2*no+1].mini<seg[2*no+2].mini) {
        seg[no].mini = seg[2*no+1].mini;
        seg[no].cont = seg[2*no+1].cont;
    }
    else if (seg[2*no+2].mini<seg[2*no+1].mini) {
        seg[no].mini = seg[2*no+2].mini;
        seg[no].cont = seg[2*no+2].cont;
    }
    else {
        seg[no].mini = seg[2*no+1].mini;
        seg[no].cont = seg[2*no+1].cont + seg[2*no+2].cont;
    }
    return;
}

void update (int no, int pos, int l, int r) {
    if (l==r) {
        seg[no].mini = vet[pos];
        seg[no].cont = 1;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update (2*no+1, pos, l, mid);
    else update(2*no+2, pos, mid+1, r);

    seg[no].mini = min(seg[2*no+1].mini, seg[2*no+2].mini);
    if (seg[no].mini == seg[2*no+1].mini) {
        if (seg[no].mini == seg[2*no+2].mini) seg[no].cont = seg[2*no+1].cont + seg[2*no+2].cont;
        else seg[no].cont = seg[2*no+1].cont;
    }
    else if (seg[no].mini == seg[2*no+2].mini) seg[no].cont = seg[2*no+2].cont;
    return;
}

node ans (int no, int lq, int rq, int l, int r) {
    if (lq<=l && rq>=r) return seg[no];
    if (lq>r || rq<l) return aux;
    int mid = (l+r)/2;
    node esq = ans(2*no+1, lq, rq, l, mid);
    node dir = ans(2*no+2, lq, rq, mid+1, r);
    if (esq.mini<dir.mini) {
        return esq;
    }
    else if (dir.mini<esq.mini) {
        return dir;
    }
    else {
        esq.cont += dir.cont;
        return esq;
    }
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf ("%d", &vet[i]);
    aux.mini = INT_MAX;
    build(0, 0, n-1);
    while (m--) {
        int id, a, b;
        scanf ("%d%d%d", &id, &a, &b);
        if (id==1) {
            vet[a]=b;
            update(0, a, 0, n-1);
        }
        else {
            node resp = ans(0, a, b-1, 0, n-1);
            printf ("%d %d\n", resp.mini, resp.cont);
        }
    }
    return 0;
}