#include <iostream>
#include <algorithm>

using namespace std;

struct consulta {
    int ini;
    int fim;
};

bool sortar (consulta a, consulta b) {
    return a.fim<b.fim;
}

consulta vet[10010];
int n, ans, livre;

int main () {
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d %d", &vet[i].ini, &vet[i].fim);
    sort (vet+1, vet+n+1, sortar);
    for (int i=1; i<=n; i++) {
        if (vet[i].ini >= livre) {
            ans++;
            livre = vet[i].fim;
        }
    }
    printf ("%d\n", ans);
    return 0;
}
