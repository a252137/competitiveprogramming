#include <bits/stdc++.h>
#define MAXN 100010
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
    long long int dist[MAXN];
    for (int i=1; i<n; i++) dist[i] = pow(10, 18);
    dist[0]=0;
    long long int rev[MAXN];
    for (int i=0; i<n-1; i++) rev[i] = pow(10, 18);
    rev[n-1]=0;
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        long long int d = pq.top().first;
        int u = pq.top().second;
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
    pq.push({0, n-1});
    while (!pq.empty()) {
        long long int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d>rev[u]) continue;
        for (int i=0; i<(int)grafo[u].size(); i++) {
            int v = grafo[u][i].second;
            long long int dv = grafo[u][i].first;
            if (rev[v]>rev[u]+dv) {
                rev[v] = rev[u]+dv;
                pq.push({rev[v], v});
            }
        }
    }
    long long int ans = dist[n-1];
    for (int i=2; i<n-1; i++) {
        ans = max(ans, dist[i]+rev[i]);
    }
    printf ("%lld\n", ans);
    return 0;
}