#include <bits/stdc++.h>

using namespace std;

long long int ans;

vector<int> merge (vector<int> vet){
    
    int tamanho = (int)(vet.size());
    
    if (tamanho<=1) return vet;
    
    vector<int> esquerda;
    
    vector<int> direita;
    
    for (int i=0; i<tamanho/2; i++) esquerda.push_back(vet[i]);
    
    for (int i=tamanho/2; i<tamanho; i++) direita.push_back(vet[i]);
    
    esquerda = merge (esquerda); 
    
    direita = merge (direita); 
    
    esquerda.push_back(1000000);
    
    direita.push_back(1000000);
    
    int contD=0, contE=0;
    
    for (int i=0; i<tamanho; i++) {
        
        if (esquerda[contE]>direita[contD]) {
            
            vet[i]=direita[contD];
            
            contD++;
            
        }
        
        else {
            
            vet[i]=esquerda[contE];
            
            contE++;
            
            ans += contD;
            
        }
        
    }
    
    return vet;
    
}

int main() {
    
    int n, x;
    
    vector<int> vet;
    
    scanf ("%d", &n);
    
    for (int i=0; i<n; i++) {
        
        scanf ("%d", &x);
        
        vet.push_back(x);
        
    }
    
    vector<int> ordenado = merge (vet);
    
    printf ("%lld\n", ans);
    
    return 0;
    
}
