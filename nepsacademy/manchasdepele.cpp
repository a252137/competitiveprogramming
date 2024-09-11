#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int nivel[MAXN][MAXN], mat[MAXN][MAXN];
int comp;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool check (int x, int y) {
    if ((x<1 || x>n) || (y<1 || y>m)) return false;
    else return true;
}

void bfs (int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int novo_x = x+dx[k];
            int novo_y = y+dy[k];
            if (!check(novo_x, novo_y)) continue;
            if (mat[novo_x][novo_y]==0) continue;
            if (nivel[novo_x][novo_y]!=0) continue;
            nivel[novo_x][novo_y] = comp;
            q.push({novo_x, novo_y});
        }
    }
    return;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) scanf ("%d", &mat[i][j]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mat[i][j]==0) continue;
            if (nivel[i][j]!=0) continue;
            comp++;
            bfs(i, j);
        }
    }
    printf ("%d\n", comp);
    return 0;
}