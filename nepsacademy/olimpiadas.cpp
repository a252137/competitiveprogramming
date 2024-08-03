#include <bits/stdc++.h>

using namespace std;

int n, i, m;

struct premios {
    int numero;
    int ouro;
    int prata;
    int bronze;
};

premios medalha[110];

bool parametro(premios a, premios b){
    if (a.ouro==b.ouro){
        if (a.prata==b.prata){
            if (a.bronze==b.bronze){
                return a.numero>b.numero;
            }
            else {
                return a.bronze<b.bronze;
            }
        }
        else {
            return a.prata<b.prata;
        }
    }
    else {
        return a.ouro<b.ouro;
    }
}

int main() {
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; i++){
        medalha[i].numero=i;
    }
    for (i=1; i<=m; i++){
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        medalha[a].ouro++;
        medalha[b].prata++;
        medalha[c].bronze++;
    }
    sort (medalha+1, medalha+n+1, parametro);
    for (i=n; i>=1; i--){
        printf ("%d ", medalha[i].numero);
    }
    printf ("\n");
    return 0;
}








