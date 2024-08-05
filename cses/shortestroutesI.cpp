#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    vector<pair<long long int, int>> grafo[100010];
    scanf ("%d%d", &n, &m);
    while (m--) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
    }
    long long int dist[100010];
    dist[1] = 0;
    for (int i=2; i<=n; i++) dist[i] = pow(10, 18);
    priority_queue <pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        long long int d = pq.top().first;
        int at = pq.top().second;
        pq.pop();
        if (d>dist[at]) continue;
        for (int i=0; i<(int)grafo[at].size(); i++) {
            int adj = grafo[at][i].second;
            long long int d_adj = grafo[at][i].first;
            if (dist[adj]>dist[at]+d_adj) {
                dist[adj] = dist[at]+d_adj;
                pq.push({dist[adj], adj});
            }
        }
    }
    for (int i=1; i<=n; i++) {
        printf ("%lld ", dist[i]);
    }
    printf ("\n");
    return 0;
}