#include <bits/stdc++.h>
#define MAXN 260

using namespace std;

int comp[MAXN][MAXN], lobo[MAXN*MAXN], ovelha[MAXN*MAXN];
int comp_geral;
int n, m;
char mat[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans_lobo, ans_ovelha;

bool check (int x, int y) {
    if ((x<1 || x>n) || (y<1 || y>m)) return false;
    else return true;
}

void bfs (int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    comp[a][b] = ++comp_geral;
    if (mat[a][b]=='k') ovelha[comp_geral]++;
    if (mat[a][b]=='v') lobo[comp_geral]++;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int novo_x = x+dx[k];
            int novo_y = y+dy[k];
            if (!check(novo_x, novo_y)) continue;
            if (mat[novo_x][novo_y]=='#') continue;
            if (comp[novo_x][novo_y]!=0) continue;
            comp[novo_x][novo_y] = comp_geral;
            q.push({novo_x, novo_y});
            if (mat[novo_x][novo_y]=='k') ovelha[comp_geral]++;
            if (mat[novo_x][novo_y]=='v') lobo[comp_geral]++;
        }
    }
    if (lobo[comp_geral]>=ovelha[comp_geral]) ans_lobo+=lobo[comp_geral];
    else ans_ovelha+=ovelha[comp_geral];
    return;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf (" %c", &mat[i][j]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mat[i][j]=='#') continue;
            if (comp[i][j]!=0) continue;
            bfs(i, j);
        }
    }
    printf ("%d %d\n", ans_ovelha, ans_lobo);
    return 0;
}