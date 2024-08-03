#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[100010];
vector<int> resp;
int nivel[100010], ans, d, n, pai[100010];
bool check = false;

int main () {
    int m;
    scanf ("%d%d%d", &n, &m, &d);
    for (int i=1; i<=m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }
    int l=0, r=1000000010, mid;
    ans = -1;
    while (l<=r) {
        mid = (l+r)/2;
        nivel[1] = 0;
        for (int i=2; i<=n; i++) nivel[i]=-1;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int i=0; i<(int)adj[at].size(); i++) {
                int adj_at = adj[at][i].first;
                int id = adj[at][i].second;
                if (nivel[adj_at] ==-1 && (nivel[at]<d && id<=mid)) {
                    nivel[adj_at] = nivel[at]+1;
                    q.push(adj_at);
                }
            }
        }
        if (nivel[n]!=-1) {
            ans = mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if (ans == -1) printf ("-1\n");
    else {
        for (int i=2; i<=n; i++) nivel[i] = -1;
        nivel[1] = 0;
        pai[1] = 1;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int at = q.front();
            q.pop();
            for (int i=0; i<(int)adj[at].size(); i++) {
                int adj_at = adj[at][i].first;
                int id = adj[at][i].second;
                if (nivel[adj_at] ==-1 && (nivel[at]<d && id<=ans)) {
                    nivel[adj_at] = nivel[at]+1;
                    q.push(adj_at);
                    pai[adj_at] = at;
                }
            }
        }
        int at = n;
        vector<int> resp;
        while (at != 1) {
            resp.push_back(at);
            at = pai[at];
        }
        resp.push_back(1);
        printf ("%d\n", (int)resp.size()-1);
        for (int i=(int)resp.size()-1; i>=0; i--) printf ("%d ", resp[i]);
        printf ("\n");
    }
    return 0;
}
