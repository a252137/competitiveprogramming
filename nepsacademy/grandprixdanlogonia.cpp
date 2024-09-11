#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int arestas[MAXN][4];
vector<int> grafo[4*MAXN];
int n, m;
int cor[4*MAXN];
bool ciclo = false;

int find (int node, int alvo, int l, int r) {
    if (l==r) return node;
    int mid = (l+r)/2;
    if (alvo<=mid) return find(2*node, alvo, l, mid);
    else return find(2*node+1, alvo, mid+1, r);
}

void build (int node, int u, int l0, int r0, int l, int r) {
    if (l0<=l && r0>=r) {
        grafo[u].push_back(node);
        return;
    }
    if (l>r0 || r<l0) return;
    int mid = (l+r)/2;
    build(2*node, u, l0, r0, l, mid);
    build(2*node+1, u, l0, r0, mid+1, r);
}

void dfs (int x) {
    cor[x]=1;
    for (int i=0; i<(int)grafo[x].size(); i++) {
        int adj = grafo[x][i];
        if (cor[adj]==0) {
            dfs(adj);
        }
        else if (cor[adj]==1) {
            ciclo = true;
            return;
        }
    }
    cor[x]=2;
    return;
}

void ini (int node, int l, int r) {
    if (l==r) return;
    grafo[node].push_back(2*node);
    grafo[node].push_back(2*node+1);
    int mid = (l+r)/2;
    ini(2*node, l, mid);
    ini(2*node+1, mid+1, r);
    return;
}

bool check (int mid) {
    ciclo = false;
    for (int i=1; i<=4*n; i++) {
        grafo[i].clear();
        cor[i] = 0;
    }
    ini(1, 1, n);
    for (int i=1; i<=mid; i++) {
        int u = arestas[i][1], l = arestas[i][2], r = arestas[i][3];
        u = find(1, u, 1, n);
        build(1, u, l, r, 1, n);
    }
    for (int i=1; i<=4*n; i++) {
        if (cor[i]==0) dfs(i);
        if (ciclo == true) return true;
    }
    return false;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=m; i++) scanf ("%d%d%d", &arestas[i][1], &arestas[i][2], &arestas[i][3]);
    int l=1, r=m, mid, ans=-1;
    ini(1, 1, n);
    while (l<=r) {
        mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    printf ("%d\n", ans);
    return 0;
}