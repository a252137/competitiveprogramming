#include <bits/stdc++.h>

using namespace std;

int vet[110];

//ou pega de um lado e dps pega do outro
//ou pega da esquerda e vai prosseguindo pela esquerda
//ou pega da direita e vai prosseguindo pela direita

int main() {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        int mini = 110, maxi = 0, pos1 = 0, pos2 = 0;
        
        for (int i=1; i<=n; i++) {
            
            scanf ("%d", &vet[i]);
            if (vet[i]<mini) {
                
                mini = vet[i];
                pos1 = i;
                
            }
            
            if (vet[i]>maxi) {
                
                maxi = vet[i];
                pos2 = i;
                
            }
            
        }
        
        int caso1, caso2, caso3;
        
        if (pos2<pos1) swap (pos2, pos1);
        
        caso1 = pos1 + (n-pos2+1);
        
        caso2 = pos2;
        
        caso3 = n-pos1+1;
        
        printf ("%d\n", min(caso1, min(caso2, caso3)));
        
    }
    
    return 0;
    
}
