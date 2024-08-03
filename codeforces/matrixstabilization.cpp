#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, m;
        scanf ("%d%d", &n, &m);
        int mat[110][110];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                scanf ("%d", &mat[i][j]);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                bool maior = true;
                int menor_maior = 0;
                for (int k=0; k<4; k++) {
                    int novoX = i+dx[k];
                    int novoY = j+dy[k];
                    if ((novoX<1 || novoX>n) || (novoY<1 || novoY>m)) continue;
                    if (mat[novoX][novoY]>=mat[i][j]) maior = false;
                    menor_maior = max(menor_maior, mat[novoX][novoY]);
                }
                if (maior == true) mat[i][j] = menor_maior;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                printf ("%d ", mat[i][j]);
            }
            printf ("\n");
        }
    }
    return 0;
}
