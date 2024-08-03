#include <bits/stdc++.h>

using namespace std;

int main () {
    int teste = 1;
    while (true) {
        int c, e, l, p;
        vector<int> grafo[55];
        int nivel[55];
        scanf ("%d%d%d%d", &c, &e, &l, &p);
        if (c==0) break;
        for (int i=1; i<=e; i++) {
            int x, y;
            scanf ("%d%d", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        for (int i=1; i<=c; i++) nivel[i] = -1;
        nivel[l] = 0;
        queue<int>q;
        q.push(l);
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int i=0; i<(int)grafo[at].size(); i++) {
                int adj = grafo[at][i];
                if (nivel[adj]==-1) {
                    nivel[adj] = nivel[at] + 1;
                    q.push(adj);
                }
            }
        }
        printf ("Teste %d\n", teste);
        teste++;
        for (int i=1; i<=c; i++) {
            if ((i!=l && nivel[i]!=-1) && nivel[i]<=p) {
                printf ("%d ", i);
            }
            grafo[i].clear();
            nivel[i] = -1;
        }
        printf ("\n\n");
    }
    return 0;
}