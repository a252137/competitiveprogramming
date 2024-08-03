#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[100010];
int visitado[100010], pai[100010];
deque<int> ans;
bool check = false, check2 = false;
int p;
 
void dfs (int x) {
    visitado[x] = 1;
    for (int i=0; i<(int)adj[x].size(); i++) {
        if (visitado[adj[x][i]] == 1 && pai[x]!=adj[x][i]) {
            check = true;
            p = pai[adj[x][i]];
            ans.push_back(adj[x][i]);
            ans.push_back(x);
            return;
        }
        if (visitado[adj[x][i]] == 0) {
            pai[adj[x][i]] = x;
            dfs(adj[x][i]);
        }
        if ((int)ans.size()>1) {
            if (ans.front() == ans.back()) return;
        }
        if (check == true && x != p) {
            ans.push_back(x);
            return;
        }
        if (check == true && x == p) {
            check2 = true;
            return;
        }
        if (check == true && check2 == true) {
            return;
        }
    }
    visitado[x] = 2;
}
 
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pai[1] = 1;
    for (int i=1; i<=n; i++) {
        if (visitado[i]==0 && (int)ans.size() == 0) {
            pai[i]=i;
            dfs(i);
        }
    }
    if ((int)ans.size() == 0) printf ("IMPOSSIBLE\n");
    else {
        if (ans.front() != ans.back() && ans.front() != p) ans.push_front(p);
        if (ans.front() != ans.back() && ans.back() != p) ans.push_back(p);
        printf ("%d\n", (int)ans.size());
        for (int i=0; i<(int)ans.size(); i++) printf ("%d ", ans[i]);
        printf ("\n");
    }
    return 0;
}
