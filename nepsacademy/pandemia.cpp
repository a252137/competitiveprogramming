#include <bits/stdc++.h>

using namespace std;

int infectados[1010];
int atuais[1010];

int main() {
    
    int amigos, dias;
    scanf ("%d%d", &amigos, &dias);
    
    int contagio, primeira_r;
    scanf ("%d%d", &contagio, &primeira_r);
    
    for (int i=1; i<=dias; i++) {
        
        bool infeccao = false;
        int numero;
        scanf ("%d", &numero);
        
        if (i>=primeira_r) {
            
            for (int j=1; j<=numero; j++) {
                
                scanf ("%d", &atuais[j]);
                if (atuais[j]==contagio || infectados[atuais[j]]==1) infeccao = true;
                
            }
            
            if (infeccao==true) {
                
                for (int j=1; j<=numero; j++) infectados[atuais[j]] = 1;
                
            }
            
        }
        
        else {
            
            for (int j=1; j<=numero; j++) {
                
                scanf ("%d", &atuais[j]);
                
            }
            
        }
        
    }
    
    int ans = 0;
    
    for (int i=1; i<=amigos; i++) ans += infectados[i];
    
    printf ("%d\n", ans);
    
    return 0;
    
}
