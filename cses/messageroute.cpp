#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> grafo[100010];
int ans[100010];
int pai[100010];
 
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    ans[1]=1;
    while (m--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    pai[1]=1;
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        for (int i=0; i<(int)grafo[at].size(); i++) {
            int adj = grafo[at][i];
            if (ans[adj]==0) {
                ans[adj]=ans[at]+1;
                pai[adj]=at;
                q.push(adj);
            }
        }
    }
    if (ans[n]==0) printf ("IMPOSSIBLE\n");
    else {
        printf ("%d\n", ans[n]);
        vector<int> fim;
        int p = n;
        while (pai[p]!=p) {
            fim.push_back(p);
            p = pai[p];
        }
        fim.push_back(1);
        for (int i=(int)fim.size()-1; i>=0; i--) printf ("%d ", fim[i]);
        printf ("\n");
    }
    return 0;
}
