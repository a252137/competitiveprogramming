#include <bits/stdc++.h>

using namespace std;

int dx[24] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy[24] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    int mat[505][505];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) scanf ("%d", &mat[i][j]);
    }
    queue<pair<int, int>> q;
    q.push({1,1});
    int ans[505][505];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) ans[i][j]=-1;
    }
    ans[1][1]=0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<24; i++) {
            int novo_x = x+dx[i];
            int novo_y = y+dy[i];
            if ((novo_x<1 || novo_x>n) || (novo_y<1 || novo_y>m)) continue;
            if (mat[novo_x][novo_y]==0) continue;
            if (ans[novo_x][novo_y]==-1) {
                ans[novo_x][novo_y]=ans[x][y]+1;
                q.push({novo_x, novo_y});
            }
        }
    }
    printf ("%d\n", ans[n][m]);
    return 0;
}