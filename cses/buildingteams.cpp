#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> grafo[100010];
int ans[100010];
 
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    while (m--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    bool check = true;
    for (int i=1; i<=n; i++) {
        if (ans[i]!=0) continue;
        queue<int> q;
        q.push(i);
        ans[i]=1;
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int j=0; j<(int)grafo[at].size(); j++) {
                int adj=grafo[at][j];
                if (ans[adj] == 0) {
                    if (ans[at]==1) ans[adj]=2;
                    if (ans[at]==2) ans[adj]=1;
                    q.push(adj);
                }
                else {
                    if (ans[adj]==ans[at]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check == false) break;
        }
        if (check == false) break;
    }
    if (check == false) printf ("IMPOSSIBLE\n");
    else {
        for (int i=1; i<=n; i++) printf ("%d ", ans[i]);
        printf ("\n");
    }
    return 0;
}
