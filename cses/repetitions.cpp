#include <bits/stdc++.h>
 
using namespace std;
 
char vet[1000010];
 
int main() {
    
    scanf ("%s", vet);
    
    int maxi = 1;
    
    int ans = 1;
    
    int tamanho = strlen(vet);
    
    for (int i=1; i<tamanho; i++) {
        
        if (vet[i]==vet[i-1]) maxi++;
        
        else {
            
            ans = max(maxi, ans);
            maxi = 1;
            
        }
        
    }
    
    ans = max (maxi, ans);
    
    printf ("%d\n", ans);
    
    return 0;
    
}
