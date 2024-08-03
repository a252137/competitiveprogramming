#include <bits/stdc++.h>

using namespace std;

int cores[10010];
int esq[10010], dir[10010];

// se um vetor é declarado fora da função principal, todas suas posições são igual a 0

int main() {
    
    int n;
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) scanf ("%d", &cores[i]);
    
    // dir[i] = distância da posição i até o 0 mais próximo dela, estando esse 0 a sua direita
    // se dir[x] for igual a 1000000000, quer dizer que não existe nenhum 0 a direita da posição x
    
    if (cores[n] == -1) {
        
        dir[n]=1000000000;
        
    }
    
    for (int i=n-1; i>=1; i--) {
        
        if (cores[i]==0) {
            
            continue;
            
        }
        
        else if (cores[i+1]==0) {
            
            dir[i] = 1;
            
        }
        
        else if (dir[i+1]==1000000000) {
            
            dir[i] = 1000000000;
            
        }
        
        else {
            
            dir[i] = dir[i+1] + 1;
            
        }
        
    }
    
    // esq[i] = a distância pro 0 mais próximo da posição i, estando esse 0 a esquerda de i
    // se esq[x] é igual a 1000000000, isso quer dizer que não existe nenhum 0 a esquerda da posição x
    
    if (cores[1] == -1) {
        
        esq[1] = 1000000000;
        
    }
    
    for (int i=2; i<=n; i++) {
        
        if (cores[i] == 0) {
            
            continue;
            
        }
        
        else if (cores[i-1] == 0) {
            
            esq[i] = 1;
            
        }
        
        else if (esq[i-1] == 1000000000) {
            
            esq[i] = 1000000000;
            
        }
        
        else {
            
            esq[i] = esq[i-1] + 1;
            
        }
        
    }
    
    for (int i=1; i<=n; i++) {
        
        int ans;
        
        ans = min(esq[i], dir[i]);
        
        if (ans>=9) {
            
            printf ("9 ");
            
        }
        
        else {
            
            printf ("%d ", ans);
            
        }
        
    }
    
    printf ("\n");
    
    return 0;
}
