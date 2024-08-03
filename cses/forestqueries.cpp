#include <bits/stdc++.h>
using namespace std;
int  s[1010][1010], n, q, x, y, x2, y2, i, j;
char f[1010][1010];
 
int main(){
    scanf ("%d%d", &n, &q);
    for (i=1;i<=n;i++){
        for (j=1; j<=n; j++){
            scanf (" %c", &f[i][j]);
            if (f[i][j]=='*'){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+1;
            }
            else {
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            }
        }
    }
    for (i=1; i<=q; i++){
        scanf ("%d%d%d%d", &y, &x, &y2, &x2);
        printf ("%d\n", s[y2][x2]-s[y-1][x2]-s[y2][x-1]+s[y-1][x-1]);
    }
    
}
