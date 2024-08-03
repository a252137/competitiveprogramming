#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, k;

bool valid (int x, int y) {
    
    if (x>=1 && x<=n && y>=1 && y<=m) return true;
    else return false;
    
}

int main() {
    
    char matriz[1010][1011];
    
    scanf ("%d%d%d", &n, &m, &k);
    
    for (int i=1; i<=n; i++) {
        
        for (int j=1; j<=m; j++) {
            
            scanf (" %c", &matriz[i][j]);
            
        }
        
    }
    
    int a, b, c, d;
    
    scanf ("%d%d%d%d", &a, &b, &c, &d);
    
    int segundo[1010][1010];
    
    for (int i=1; i<=n; i++) {
        
        for (int j=1; j<=m; j++) {
            
            segundo[i][j]=1000010;
            
        }
        
    }
    
    segundo[a][b]=0;
    
    queue<pair<int, int>> fila;
    
    fila.push(make_pair(a, b));
    
    while (!fila.empty()) {
        
        int x = fila.front().first;
        int y = fila.front().second;
        
        fila.pop();
        
        for (int i=0; i<4; i++) {
            
            for (int j=1; j<=k; j++) {
                
                if (matriz[x+dx[i]*j][y+dy[i]*j]=='#') break;
                
                int novoX = x + dx[i]*j;
                int novoY = y + dy[i]*j;
                
                if (valid(novoX, novoY)==false) break;
                
                if (matriz[novoX][novoY]=='.' && segundo[novoX][novoY]==1000010) {
                    
                    segundo[novoX][novoY]=segundo[x][y]+1;
                    fila.push(make_pair(novoX, novoY));
                    
                }
                
                else if (segundo[novoX][novoY] < segundo[x][y] + 1) break;
                
            }
            
        }
        
    }
    
    if (segundo[c][d]==1000010) printf ("-1\n");
    else printf ("%d\n", segundo[c][d]);
    
    return 0;
    
}









