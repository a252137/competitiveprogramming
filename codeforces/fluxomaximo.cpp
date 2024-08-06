#include <bits/stdc++.h>
#define MAXN 200010
#define lli pair<long long int, int>

using namespace std;

int main () {
    int n, m, s, t;
    scanf ("%d%d%d%d", &n, &m, &s, &t);
    vector<lli> grafo[MAXN];
    while (m--) {
        int a, b;
        long long int c;
        scanf ("%d%d%lld", &a, &b, &c);
        grafo[a].push_back({c, b});
    }
    int l = 1, r = 1000000010, mid;
    int ans = -1;
    while (l<=r) {
        mid = (l+r)/2;
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        long long int dist[MAXN];
        for (int i=1; i<=n; i++) dist[i] = pow(10, 18);
        dist[s]=0;
        pq.push({0, s});
        while (!pq.empty()) {
            int u = pq.top().second;
            long long int d = pq.top().first;
            pq.pop();
            if (d>dist[u]) continue;
            for (int i=0; i<(int)grafo[u].size(); i++) {
                int v = grafo[u][i].second;
                long long int dv = grafo[u][i].first;
                if (dv>=mid && dist[v]>dist[u]+dv) {
                    dist[v]=dist[u]+dv;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[t]==pow(10, 18)) r = mid-1;
        else {
            ans = mid;
            l = mid+1;
        }
    }
    printf ("%d\n", ans);
    return 0;
}