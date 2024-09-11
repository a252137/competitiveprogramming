#include <bits/stdc++.h>
#define MAXN 100010
#define lli long long int

using namespace std;

vector<pair<lli, int>> grafo[MAXN];
lli dist[MAXN][15];

int main () {
    int n, m, k;
    scanf ("%d%d%d", &n, &m, &k);
    while (m--) {
        int a, b;
        lli c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) dist[i][j] = pow(10, 18);
    }
    dist[1][1] = 0;
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        lli d = pq.top().first;
        pq.pop();
        if (d>dist[u][k]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            lli dv = grafo[u][i].first;
            if (d+dv<dist[v][k]) {
                dist[v][k] = d+dv;
                pq.push({dist[v][k], v});
                sort(dist[v]+1, dist[v]+k+1);
            }
        }
    }
    for (int i=1; i<=k; i++) printf ("%lld ", dist[n][i]);
    printf ("\n");
    return 0;
}