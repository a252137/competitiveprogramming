#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int nivel[MAXN][MAXN];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check (int x, int y) {
    if ((x<1 || x>n) || (y<1 || y>m)) return false;
    else return true;
 }

int main () {
    scanf ("%d%d", &n, &m);
    char mat[MAXN][MAXN];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) scanf (" %c", &mat[i][j]);
    }
    int comp = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mat[i][j]=='#' || nivel[i][j]!=0) continue;
            nivel[i][j] = ++comp;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k=0; k<4; k++) {
                    int novo_x = x+dx[k];
                    int novo_y = y+dy[k];
                    if (!check(novo_x, novo_y)) continue;
                    if (mat[novo_x][novo_y]=='#') continue;
                    if (nivel[novo_x][novo_y]!=0) continue;
                    nivel[novo_x][novo_y] = nivel[i][j];
                    q.push({novo_x, novo_y});
                }
            }
        }
    }
    printf ("%d\n", comp);
    return 0;
}