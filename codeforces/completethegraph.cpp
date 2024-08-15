#include <bits/stdc++.h>
#define MAXN 1010
#define lli pair<long long int, int>

using namespace std;

int main () {
    int n, m, s, t;
    long long int l;
    long long int adj[MAXN][MAXN];
    int pai[MAXN];
    scanf ("%d%d%lld%d%d", &n, &m, &l, &s, &t);
    vector<pair<lli, int>> arestas;
    vector<lli> grafo[MAXN];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) adj[i][j]=-1;
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        arestas.push_back({{c, a}, b});
        grafo[a].push_back({c, b});
        grafo[b].push_back({c, a});
        adj[a][b]=c;
        adj[b][a]=c;
    }
    long long int ini = 1, fim = pow(10, 18), mid;
    long long int dist[MAXN];
    long long int ans = -1, dist_t=-1;
    while (ini<=fim) {
        mid = (ini+fim)/2;
        for (int i=0; i<n; i++) dist[i] = pow(10, 18) + 10;
        dist[s] = 0;
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            long long int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d>dist[u]) continue;
            for (int i=0; i<(int)grafo[u].size(); i++) {
                int v = grafo[u][i].second;
                long long int dv = grafo[u][i].first;
                if (dv == 0) dv = mid;
                if (dist[u]+dv<dist[v]) {
                    dist[v] = dist[u]+dv;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[t]>=l) {
            ans = mid;
            dist_t=dist[t];
            fim = mid-1;
        }
        else ini = mid+1;
    }
    if (ans == -1) {
        printf ("NO\n");
        return 0;
    }
    if (ans==1 && dist_t>l) {
        printf ("NO\n");
        return 0;
    }
    printf ("YES\n");
    for (int i=0; i<n; i++) dist[i] = pow(10, 18) + 10;
    dist[s] = 0;
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    pq.push({0, s});
    pai[s]=s;
    while (!pq.empty()) {
        int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if (d>dist[u]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (dv == 0) dv = ans;
            if (dist[u]+dv<dist[v]) {
                dist[v]=dist[u]+dv;
                pq.push({dist[v], v});
                pai[v] = u;
            }
        }
    }
    int p = t;
    int arestas_aux = dist_t - l;
    while (p!=pai[p]) {
        if (adj[p][pai[p]] == 0) {
            if (arestas_aux>0) {
                adj[p][pai[p]] = ans-1;
                adj[pai[p]][p] = ans-1;
                arestas_aux--;
            }
            else {
                adj[p][pai[p]] = ans;
                adj[pai[p]][p] = ans;
            }
        }
        p = pai[p];
    }
    for (int i=0; i<m; i++) {
        int a = arestas[i].first.second;
        int b = arestas[i].second;
        long long int c = arestas[i].first.first;
        if (c == 0) c = adj[a][b];
        if (adj[a][b] == 0) c = ans;
        printf ("%d %d %lld\n", a, b, c);
    }
    return 0;
}