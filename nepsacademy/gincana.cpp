#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

vector<int> grafo[MAXN];
int comp[MAXN];
int comp_geral;

void bfs (int x) {
    queue<int> q;
    q.push(x);
    comp[x] = comp_geral;
        while (!q.empty()) {
        int at = q.front();
        q.pop();
        for (int j=0; j<(int)grafo[at].size(); j++) {
            int adj = grafo[at][j];
            if (comp[adj]==0) {
                comp[adj] = comp_geral;
                q.push(adj);
            }
        }
    }
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf ("%d%d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (comp[i]==0) {
            comp_geral++;
            bfs(i);
        }
    }
    printf ("%d\n", comp_geral);
    return 0;
}