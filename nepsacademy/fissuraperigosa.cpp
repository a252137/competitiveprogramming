#include <bits/stdc++.h>

using namespace std;

char matriz[510][510];
int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int calc (char z) {
    
    return z - '0';
    
}

bool check (int x, int y) {
    
    if (x>=1 && x<=n && y>=1 && y<=n) return true;
    else return false;
    
}

int main() {
    
    int f;
    scanf ("%d%d", &n, &f);
    
    for (int i=1; i<=n; i++) {
        
        for (int j=1; j<=n; j++) {
            
            scanf (" %c", &matriz[i][j]);
            
        }
        
    }
    
    queue<pair<int, int>> fila;
    
    if (calc(matriz[1][1])<=f) {
        
        fila.push(make_pair(1, 1));
        matriz[1][1]='*';
        
    }
    
    while (!fila.empty()) {
        
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
            
        for (int i=0; i<4; i++) {
                
            int novoX = x + dx[i];
            int novoY = y + dy[i];
                
            if (check(novoX, novoY)==false) continue;
            
            int a = calc(matriz[novoX][novoY]);
            
            if (matriz[novoX][novoY]=='*' || a>f) continue;
            
            matriz[novoX][novoY]='*';    
            fila.push(make_pair(novoX, novoY));
                
        }
        
    }
    
    for (int i=1; i<=n; i++) {
        
        for (int j=1; j<=n; j++) printf ("%c", matriz[i][j]);
        
        printf ("\n");
        
    }
    
    return 0;
    
}
