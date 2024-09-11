#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

char mat[MAXN][MAXN];
int n, m;
int nivel[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check (int a, int b) {
    if ((a<1 || a>n) || (b<1 || b>m)) return false;
    else return true;
}

int main () {
    scanf ("%d%d", &n, &m);
    int x_ini, y_ini;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf (" %c", &mat[i][j]);
            if (mat[i][j]=='o') {
                x_ini = i;
                y_ini = j;
            }
        }
    }
    nivel[x_ini][y_ini] = 1;
    int nivel_max = 1;
    int x_fim = x_ini, y_fim = y_ini;
    queue<pair<int, int>> q;
    q.push({x_ini, y_ini});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int novo_x = x+dx[k];
            int novo_y = y+dy[k];
            if (!check(novo_x, novo_y)) continue;
            if (mat[novo_x][novo_y]=='.') continue;
            if (nivel[novo_x][novo_y]!=0) continue;
            nivel[novo_x][novo_y] = nivel[x][y]+1;
            q.push({novo_x, novo_y});
            if (nivel[novo_x][novo_y]>nivel_max) {
                nivel_max = nivel[novo_x][novo_y];
                x_fim = novo_x;
                y_fim = novo_y;
            }
        }
    }
    printf ("%d %d\n", x_fim, y_fim);
    return 0;
}