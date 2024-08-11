#include <bits/stdc++.h>
#define MAXN 10002
#define MAXV 202
#define lli pair<long long int, int>

using namespace std;

int main () {
    int v, n, m;
    scanf ("%d%d%d", &v, &n, &m);
    vector<pair<lli, int>> grafo[MAXN];
    while (m--) {
        int a, b, p;
        long long int t;
        scanf ("%d%d%lld%d", &a, &b, &t, &p);
        grafo[a].push_back({{t, p}, b});
        grafo[b].push_back({{t, p}, a});
    }
    int x, y;
    scanf ("%d%d", &x, &y);
    long long int dist[MAXN][MAXV];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=v; j++) {
            if (i==x) dist[i][j]=0;
            else dist[i][j] = pow(10, 18);
        }
    }
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
    pq.push({{0, 0}, x});
    while (!pq.empty()) {
        long long int d = pq.top().first.first;
        int v_at = pq.top().first.second;
        int u = pq.top().second;
        pq.pop();
        if (v_at>v) continue;
        if (d>dist[u][v_at]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int adj = grafo[u][i].second;
            long long int d_adj = grafo[u][i].first.first;
            int p_adj = grafo[u][i].first.second;
            if (v_at+p_adj>v) continue;
            if (dist[adj][v_at+p_adj]>dist[u][v_at]+d_adj) {
                dist[adj][v_at+p_adj] = dist[u][v_at]+d_adj;
                pq.push({{dist[adj][v_at+p_adj], v_at+p_adj}, adj});
            }
        }
    }
    long long int ans = pow(10, 18);
    for (int i=0; i<=v; i++) ans = min(ans, dist[y][i]);
    if (ans==pow(10, 18)) printf ("-1\n");
    else printf ("%lld\n", ans);
    return 0;
}