#include <bits/stdc++.h>

using namespace std;

int mat[1010][1010], n, i, j, soma, ant, linhas[1010], colunas[1010], maximo;

int main() {
    
    scanf ("%d", &n);
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            scanf ("%d", &mat[i][j]);
        }
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            linhas[i]=linhas[i]+mat[i][j];
        }
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            colunas[i]=colunas[i]+mat[j][i];
        }
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            maximo=max(maximo, (linhas[i]+colunas[j])-(2*mat[i][j]));
        }
    }
    printf ("%d\n", maximo);
    
    
    return 0;
}












