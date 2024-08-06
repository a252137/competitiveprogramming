#include <bits/stdc++.h>
#define MAXN 10010
#define lli pair<long long int, int>

using namespace std;

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    vector<lli> grafo[MAXN];
    while (m--) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
        grafo[b].push_back({c, a});
    }
    long long int dist[MAXN][2];
    // 0 é par, 1 é ímpar
    dist[1][0] = 0;
    dist[1][1] = pow(10, 18);
    for (int i=2; i<=n; i++) {
        dist[i][0] = pow(10, 18);
        dist[i][1] = pow(10, 18);
    }
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
    pq.push({{0, 1}, 0});
    while (!pq.empty()) {
        int u = pq.top().first.second;
        long long int d = pq.top().first.first;
        int paridade = pq.top().second;
        pq.pop();
        if (d>dist[u][paridade]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (paridade == 0) {
                if (dist[v][1]>dist[u][0]+dv) {
                    dist[v][1] = dist[u][0]+dv;
                    pq.push({{dist[v][1], v}, 1});
                }
            }
            else {
                if (dist[v][0]>dist[u][1]+dv) {
                    dist[v][0]=dist[u][1]+dv;
                    pq.push({{dist[v][0], v}, 0});
                }
            }
        }
    }
    if (dist[n][0]==pow(10, 18)) printf ("-1\n");
    else printf ("%lld\n", dist[n][0]);
    return 0;
}