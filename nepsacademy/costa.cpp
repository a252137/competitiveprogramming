#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main () {
    int n, m;
    char vet[1010][1010];
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) scanf (" %c", &vet[i][j]);
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (vet[i][j] == '#') {
                bool check = false;
                for (int k=0; k<4; k++) {
                    int novoX = i+dx[k];
                    int novoY = j+dy[k];
                    if ((novoX<1 || novoX>n) || (novoY<1 || novoY>m)) {
                        check = true;
                        continue;
                    }
                    if (vet[novoX][novoY] == '.') check = true;
                }
                if (check == true) {
                    ans++;
                }
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}