#include <bits/stdc++.h>
 
using namespace std;
 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
 
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    char mat[1010][1010];
    int x_ini=0, y_ini=0, x_fim=0, y_fim=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf (" %c", &mat[i][j]);
            if (mat[i][j]=='A') {
                x_ini = i;
                y_ini = j;
            }
            if (mat[i][j]=='B') {
                x_fim = i;
                y_fim = j;
            }
        }
    }
    int ans[1010][1010];
    int pai_x[1010][1010], pai_y[1010][1010];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) ans[i][j]=-1;
    }
    ans[x_ini][y_ini] = 0;
    pai_x[x_ini][y_ini] = x_ini;
    pai_y[x_ini][y_ini] = y_ini;
    queue<pair<int, int>> q;
    q.push({x_ini, y_ini});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int novo_x = x+dx[i];
            int novo_y = y+dy[i];
            if ((novo_x<1 || novo_x>n) || (novo_y<1 || novo_y>m)) continue;
            if (mat[novo_x][novo_y]!='#' && ans[novo_x][novo_y]==-1) {
                ans[novo_x][novo_y] = ans[x][y]+1;
                pai_x[novo_x][novo_y] = x;
                pai_y[novo_x][novo_y] = y;
                q.push({novo_x, novo_y});
            }
        }
    }
    if (ans[x_fim][y_fim] == -1) printf ("NO\n");
    else {
        printf ("YES\n");
        printf ("%d\n", ans[x_fim][y_fim]);
        vector<char> c;
        pair<int, int> p = {x_fim, y_fim};
        while (p.first!=x_ini || p.second!=y_ini) {
            int x_ant = pai_x[p.first][p.second];
            int y_ant = pai_y[p.first][p.second];
            if (p.first == x_ant+1) c.push_back('D');
            if (p.first == x_ant-1) c.push_back('U');
            if (p.second == y_ant+1) c.push_back('R');
            if (p.second == y_ant-1) c.push_back('L');
            p.first = x_ant;
            p.second = y_ant;
        }
        for (int i=(int)c.size()-1; i>=0; i--) printf ("%c", c[i]);
        printf ("\n");
    }
    return 0;
}
