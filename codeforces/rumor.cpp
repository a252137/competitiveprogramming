#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[100010];
int visitado[100010];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    long long int ans = 0;
    long long int d[100010];
    for (int i=1; i<=n; i++) scanf ("%lld", &d[i]);
    while(m--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (visitado[i]==1) continue;
        long long int ans_temp = 1000000010;
        visitado[i]=1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            ans_temp = min(ans_temp, d[at]);
            for (int j=0; j<(int)grafo[at].size(); j++) {
                int adj=grafo[at][j];
                if (visitado[adj]==0) {
                    visitado[adj]=1;
                    q.push(adj);
                }
            }
        }
        ans += ans_temp;
    }
    printf ("%lld\n", ans);
    return 0;
}
