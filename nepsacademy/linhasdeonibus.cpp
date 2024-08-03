#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[1010];
int ans[1010];

int main () {
    int t, l, o, d;
    scanf ("%d%d%d%d", &t, &l, &o, &d);
    for (int i=1; i<=l; i++) {
        int n;
        scanf ("%d", &n);
        for (int j=1; j<=n; j++) {
            int x;
            scanf ("%d", &x);
            grafo[x].push_back(t+i);
            grafo[t+i].push_back(x);
        }
    }
    queue<int> q;
    q.push(o);
    for (int i=1; i<1010; i++) ans[i] = -1;
    ans[o] = 0;
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        for (int i=0; i<(int)grafo[at].size(); i++) {
            int adj = grafo[at][i];
            if (ans[adj] == -1) {
                ans[adj] = ans[at]+1;
                q.push(adj);
            }
        }
    }
    printf ("%d\n", ans[d]/2);
    return 0;
}