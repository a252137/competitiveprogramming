#include <bits/stdc++.h>
#define lli pair<long long int, int>
#define MAXN 100010

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
    }
    long long int dist[MAXN][2];
    dist[1][0] = 0;
    dist[1][1] = 0;
    for (int i=2; i<=n; i++) {
        dist[i][0] = pow(10, 18);
        dist[i][1] = pow(10, 18);
    }
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
    pq.push({{0, 1}, 0});
    pq.push({{0, 1}, 1});
    while (!pq.empty()) {
        long long int d = pq.top().first.first;
        int u = pq.top().first.second;
        int id = pq.top().second;
        pq.pop();
        if (d>dist[u][id]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (id==1) {
                if (dist[v][1]>dist[u][1]+dv) {
                    dist[v][1] = dist[u][1]+dv;
                    pq.push({{dist[v][1], v}, 1});
                }
            }
            else {
                if (dist[v][0]>dist[u][0]+dv) {
                    dist[v][0] = dist[u][0]+dv;
                    pq.push({{dist[v][0], v}, 0});
                }
                if (dist[v][1]>dist[u][0]+(dv/2)) {
                    dist[v][1] = dist[u][0]+(dv/2);
                    pq.push({{dist[v][1], v}, 1});
                }
            }
        }
    }
    printf ("%lld\n", min(dist[n][0], dist[n][1]));
    return 0;
}