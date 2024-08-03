#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool check (int x, int y) {
    if ((x<1 || x>n) || (y<1 || y>m)) return false;
    else return true;
}

int main () {
    scanf ("%d%d", &n, &m);
    int vet[1010][1010];
    int ini_x, ini_y;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf ("%d", &vet[i][j]);
            if (vet[i][j] == 3) {
                ini_x = i;
                ini_y = j;
            }
        }
    }
    queue<pair<int, int>> fila;
    fila.push(make_pair(ini_x, ini_y));
    int ans = 0;
    bool visitado[1010][1010];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) visitado[i][j] = false;
    }
    while (!fila.empty()) {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        visitado[x][y] = true;
        if (vet[x][y] != 0) ans++;
        if (vet[x][y] == 2) break;
        for (int i=0; i<4; i++) {
            int novoX = x + dx[i];
            int novoY = y + dy[i];
            if (!check(novoX, novoY)) continue;
            if (vet[novoX][novoY] != 0 && visitado[novoX][novoY] == false) fila.push(make_pair(novoX, novoY));
        }
    }
    printf ("%d\n", ans);
    return 0;
}