#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int chefe[MAXN][20];

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=19; j++) chefe[i][j] = -1;
    }
    for (int i=2; i<=n; i++) scanf ("%d", &chefe[i][0]);
    for (int j=1; j<=19; j++) {
        for (int i=2; i<=n; i++) {
            if (chefe[i][j-1]==-1) chefe[i][j] = -1;
            else chefe[i][j] = chefe[chefe[i][j-1]][j-1];
        }
    }
    while (q--) {
        int x, k;
        scanf ("%d%d", &x, &k);
        for (int i=19; i>=0; i--) {
            if (pow(2, i)>k) continue;
            k-=pow(2, i);
            x = chefe[x][i];
            if (x==-1) break;
            if (k==0) break;
        }
        printf ("%d\n", x);
    }
    return 0;
}