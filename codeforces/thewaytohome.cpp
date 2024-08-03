#include <bits/stdc++.h>

using namespace std;

int n, d, i, j;
vector<int> adj[110];
vector<int> fila;
int camada[110];
char vet[110];

int main() {
    scanf ("%d%d", &n, &d);
    for (i=1; i<=n; i++){
        scanf (" %c", &vet[i]);
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            if (vet[i]=='1' && vet[j]=='1' && abs(j-i)<=d){
                adj[i].push_back(j);
            }
        }
    }
    for (i=1; i<=n; i++){
        camada[i]=-1;
    }
    camada[1]=0;
    fila.push_back(1);
    
    int ponteiro=0;
    
    while (ponteiro < (int)fila.size()){
        
        int atual = fila[ponteiro];
        ponteiro++;
        
        for (i=0; i < (int)adj[atual].size(); i++){
            int vizinho=adj[atual][i];
            
            if (camada[vizinho] != -1){
                continue;
            }
            camada[vizinho]=camada[atual]+1;
            fila.push_back(vizinho);
        }
    }
    
    printf ("%d\n", camada[n]);
    
    return 0;
}
