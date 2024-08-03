#include <bits/stdc++.h>

using namespace std;

bool grid[3][3];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid (int x, int y) {
    
    if (x>=0 && x<3 && y>=0 && y<3) return true;
    else return false;
    
}

int main() {
    
    for (int i=0; i<3; i++) {
        
        for (int j=0; j<3; j++) {
            
            grid[i][j]=1;
            
        }
        
    }
    
    for (int i=0; i<3; i++) {
        
        for (int j=0; j<3; j++) {
            
            int x;
            scanf ("%d", &x);
            
            if (x%2==1) {
                
                if (grid[i][j]==1) grid[i][j]=0;
                else grid[i][j]=1;
                
                for (int k=0; k<4; k++) {
                    
                    int novoX = i+dx[k];
                    int novoY = j+dy[k];
                    
                    if (!valid(novoX, novoY)) continue;
                    
                    if (grid[novoX][novoY]==0) grid[novoX][novoY]=1;
                    else grid[novoX][novoY]=0;
                    
                }
                
            }
            
        }
        
    }
    
    for (int i=0; i<3; i++) {
        
        for (int j=0; j<3; j++) printf ("%d", grid[i][j]);
        
        printf ("\n");
        
    }
    
    return 0;
    
}
