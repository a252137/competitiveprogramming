#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    int n, m, q;
    vector<pair<long long int, int>> grafo[510];
    scanf ("%d%d%d", &n, &m, &q);
    while (m--) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
        grafo[b].push_back({c, a});
    }
    for (int i=1; i<=n; i++) sort(grafo[i].begin(), grafo[i].end());
    long long int dist[510][510];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = pow(10, 18);
        }
    }
    while (q--) {
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
        int x, y;
        scanf ("%d%d", &x, &y);
        if (dist[x][y]!=pow(10, 18)) {
            printf ("%lld\n", dist[x][y]);
            continue;
        }
        pq.push({0, x});
        while (!pq.empty()) {
            int at = pq.top().second;
            long long int d = pq.top().first;
            pq.pop();
            if (d>dist[x][at]) continue;
            for (int i=0; i<(int)grafo[at].size(); i++) {
                int adj = grafo[at][i].second;
                long long int d_adj = grafo[at][i].first;
                if (dist[x][adj]>dist[x][at]+d_adj) {
                    dist[x][adj] = dist[x][at]+d_adj;
                    pq.push({dist[x][adj], adj});
                }
            }
        }
        if (dist[x][y]==pow(10, 18)) printf ("-1\n");
        else printf ("%lld\n", dist[x][y]);
    }
    return 0;
}