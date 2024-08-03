#include <bits/stdc++.h>

using namespace std;

char mat[1010][1010];
int ans_m[1010][1010];
int ans[1010][1010];
int pai_x[1010][1010];
int pai_y[1010][1010];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    queue<pair<int, int>> q_m;
    queue<pair<int, int>> q;
    int x_ini, y_ini;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans_m[i][j]=1000000000;
            ans[i][j]=-1;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf (" %c", &mat[i][j]);
            if (mat[i][j]=='M') {
                q_m.push({i, j});
                ans_m[i][j] = 0;
            }
            if (mat[i][j]=='A') {
                x_ini = i;
                y_ini = j;
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }
    pai_x[x_ini][y_ini] = x_ini;
    pai_x[x_ini][y_ini] = y_ini;
    while (!q_m.empty()) {
        int x = q_m.front().first;
        int y = q_m.front().second;
        q_m.pop();
        for (int i=0; i<4; i++) {
            int novoX = x + dx[i];
            int novoY = y + dy[i];
            if ((novoX<1 || novoX>n) || (novoY<1 || novoY>m)) continue;
            if (mat[novoX][novoY]!='#' && ans_m[novoX][novoY]==1000000000) {
                ans_m[novoX][novoY] = ans_m[x][y]+1;
                q_m.push({novoX, novoY});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int novoX = x+dx[i];
            int novoY = y+dy[i];
            if ((novoX<1 || novoX>n) || (novoY<1 || novoY>m)) continue;
            if (mat[novoX][novoY]!='#' && ans[novoX][novoY]==-1) {
                ans[novoX][novoY]=ans[x][y]+1;
                q.push({novoX, novoY});
                pai_x[novoX][novoY] = x;
                pai_y[novoX][novoY] = y;
            }
        }
    }
    int ans_f = 1000000000, x_fim, y_fim;
    for (int i=1; i<=n; i++) {
        if (mat[i][1]!='#' && (ans[i][1]<ans_m[i][1] && ans[i][1]!=-1)) {
            if (ans[i][1]<ans_f) {
                ans_f = ans[i][1];
                x_fim = i;
                y_fim = 1;
            }
        }
        if (mat[i][m]!='#' && (ans[i][m]<ans_m[i][m] && ans[i][m]!=-1)) {
            if (ans[i][m]<ans_f) {
                ans_f = ans[i][m];
                x_fim = i;
                y_fim = m;
            }
        }
    }
    for (int j=1; j<=m; j++) {
        if (mat[1][j]!='#' && (ans[1][j]<ans_m[1][j] && ans[1][j]!=-1)) {
            if (ans[1][j]<ans_f) {
                ans_f = ans[1][j];
                x_fim = 1;
                y_fim = j;
            }
        }
        if (mat[n][j]!='#' && (ans[n][j]<ans_m[n][j] && ans[n][j]!=-1)) {
            if (ans[n][j]<ans_f) {
                ans_f = ans[n][j];
                x_fim = n;
                y_fim = j;
            }
        }
    }
    if (ans_f == 1000000000) printf ("NO\n");
    else {
        printf ("YES\n");
        printf ("%d\n", ans_f);
        vector<char> aux;
        int x = x_fim;
        int y = y_fim;
        while (x!=x_ini || y!=y_ini) {
            if (x == pai_x[x][y]+1) {
                aux.push_back('D');
                x--;
            }
            if (x == pai_x[x][y]-1) {
                aux.push_back('U');
                x++;
            }
            if (y == pai_y[x][y]+1) {
                aux.push_back('R');
                y--;
            }
            if (y == pai_y[x][y]-1) {
                aux.push_back('L');
                y++;
            }
        }
        for (int i=(int)aux.size()-1; i>=0; i--) printf ("%c", aux[i]);
        printf ("\n");
    }
    return 0;
}