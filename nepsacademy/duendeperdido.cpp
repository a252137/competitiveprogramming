#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    int mat[15][15];
    int x_ini, y_ini;
    int ans[15][15];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf ("%d", &mat[i][j]);
            if (mat[i][j]==3) {
                x_ini = i;
                y_ini = j;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) ans[i][j] = -1;
    }
    ans[x_ini][y_ini] = 0;
    queue<pair<int, int>> q;
    q.push({x_ini, y_ini});
    int a = 10000000;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int novo_x = x + dx[i];
            int novo_y = y + dy[i];
            if ((novo_x<1 || novo_x>n) || (novo_y<1 || novo_y>m)) continue;
            if (mat[novo_x][novo_y]!=2 && ans[novo_x][novo_y]==-1) {
                ans[novo_x][novo_y] = ans[x][y]+1;
                q.push({novo_x, novo_y});
            }
            if (mat[novo_x][novo_y]==0) a = min(a, ans[novo_x][novo_y]);
        }
    }
    printf ("%d\n", a);
    return 0;
}