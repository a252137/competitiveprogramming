#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> grafo[100010];
int visitado[100010];
 
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    while (m--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    int ans = 0, ant = 1;
    vector<pair<int, int>> r;
    for (int i=1; i<=n; i++) {
        if (visitado[i]==1) continue;
        if (i!=1 && visitado[i]==0) {
            ans++;
            r.push_back({ant, i});
        }
        ant = i;
        queue<int> q;
        q.push(i);
        visitado[i]=1;
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int j=0; j<(int)grafo[at].size(); j++) {
                int adj = grafo[at][j];
                if (visitado[adj]==0) {
                    visitado[adj]=1;
                    q.push(adj);
                }
            }
        }
    }
    printf ("%d\n", ans);
    for (int i=0; i<(int)r.size(); i++) printf ("%d %d\n", r[i].first, r[i].second);
    return 0;
}

