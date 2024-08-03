#include <bits/stdc++.h>

using namespace std;

int n, i;
int vet[100010];
int soma[100010];
int maximo, total;

int main() {
    
    scanf ("%d", &n);
    for (i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
        total=total+vet[i];
    }
    
    soma[1]=vet[1];
    maximo=max(maximo, vet[1]);
    for (i=2; i<=n; i++) {
        soma[i]=max(soma[i-1]+vet[i], vet[i]);
        maximo=max(maximo, soma[i]);
    }
    printf ("%d\n", (2*maximo)-total);
    
    return 0;
}













