#include <bits/stdc++.h>
#define lli pair<long long int, int>
#define MAXN 100010
#define MOD 1000000007

using namespace std;

long long int nivel_min[MAXN], nivel_max[MAXN], cam[MAXN];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    vector<lli> grafo[MAXN];
    while (m--) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
    }
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    long long int dist[MAXN];
    for (int i=2; i<=n; i++) dist[i] = pow(10, 18);
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if (d>dist[u]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (dist[v]>dist[u]+dv) {
                dist[v]=dist[u]+dv;
                pq.push({dist[v], v});
            }
        }
    }
    long long int dist2[MAXN];
    long long int ans = dist[n];
    for (int i=2; i<=n; i++) dist2[i] = pow(10, 18);
    for (int i=2; i<=n; i++) nivel_min[i] = pow(10, 18);
    dist2[1] = 0;
    pq.push({0, 1});
    cam[1] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if (d>dist2[u]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (dist2[v]>dist2[u]+dv) {
                dist2[v]=dist2[u]+dv;
                pq.push({dist2[v], v});
                nivel_min[v] = nivel_min[u]+1;
                nivel_max[v] = nivel_max[u]+1;
            }
            if (dist2[u]+dv==dist[v]) {
                nivel_min[v] = min(nivel_min[v], nivel_min[u]+1);
                nivel_max[v] = max(nivel_max[v], nivel_max[u]+1);
                cam[v] = (cam[v]+cam[u])%MOD;
            }
        }
    }
    printf ("%lld %lld %lld %lld\n", ans, cam[n], nivel_min[n], nivel_max[n]);
    return 0;
}