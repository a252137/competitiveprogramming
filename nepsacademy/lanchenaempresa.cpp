#include <bits/stdc++.h>
#define MAXN 260

using namespace std;

vector<pair<int, int>> grafo[MAXN];
int dist[MAXN][MAXN];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) dist[i][j] = pow(10, 9);
    }
    while (m--) {
        int a, b, d;
        scanf ("%d%d%d", &a, &b, &d);
        grafo[a].push_back({d, b});
        grafo[b].push_back({d, a});
        dist[a][b] = d;
        dist[b][a] = d;
    }
    for (int i=1; i<=n; i++) dist[i][i] = 0;
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans = pow(10, 9);
    for (int i=1; i<=n; i++) {
        int atual = 0;
        for (int j=1; j<=n; j++) {
            atual = max(atual, dist[i][j]);
        }
        ans = min(ans, atual);
    }
    printf ("%d\n", ans);
    return 0;
}